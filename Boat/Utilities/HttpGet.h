#pragma once
#pragma comment(lib, "urlmon.lib")

#include <urlmon.h>
#include <sstream>

size_t WebsiteGetRequest(std::string_view url, std::string& storage_str, const size_t copy_buffer_size = 100)
{
	IStream* stream;
	if (URLOpenBlockingStream(0, url.data(), &stream, 0, 0) != 0)
		return 0;

	char* buffer = new char[copy_buffer_size];
	unsigned long bytesRead;
	std::stringstream ss;
	size_t ret = 0;
	stream->Read(buffer, copy_buffer_size, &bytesRead);
	while (bytesRead > 0)
	{
		ret += bytesRead;
		ss.write(buffer, (long long)bytesRead);
		stream->Read(buffer, copy_buffer_size, &bytesRead);
	}
	stream->Release();
	storage_str = ss.str();
	return ret;
}