#pragma once

#include <cstring>
#include <utility>
#include <string>
#include <intrin.h>
namespace Packet
{
	inline constexpr size_t sz_INT32 = sizeof(int32_t);
	inline constexpr size_t sz_INT16 = sizeof(int16_t);
	inline constexpr size_t sz_INT8 = sizeof(int8_t);
	inline constexpr size_t sz_UINT32 = sizeof(uint32_t);
	inline constexpr size_t sz_UINT16 = sizeof(uint16_t);
	inline constexpr size_t sz_UINT8 = sizeof(uint8_t);
	inline constexpr size_t sz_FLOAT = sizeof(float);


	class PacketBuffer
	{
	public:
		unsigned char* buffer;
		size_t  size;
		size_t  index;
	public:
		PacketBuffer(unsigned int _size = 1024)
		{

			buffer = new unsigned char[_size];
			size = _size;
			index = 0;
		}
		PacketBuffer(char* data, unsigned int _size)
		{
			buffer = new unsigned char[_size];
			memcpy(buffer, data, _size);
			size = _size;
			index = 0;
		}
		~PacketBuffer()
		{
			if (buffer) delete[] buffer;
		}
		float ReverseFloat(const float _in)
		{
			float ret;
			char* floatToConvert = (char*)&_in;
			char* returnFloat = (char*)&ret;

			returnFloat[0] = floatToConvert[3];
			returnFloat[1] = floatToConvert[2];
			returnFloat[2] = floatToConvert[1];
			returnFloat[3] = floatToConvert[0];

			return ret;
		}
		[[nodiscard]] std::pair<unsigned char*, size_t> GetBuffer() const
		{
			return { buffer, size };
		}
		[[nodiscard]] unsigned char* GetBuffer(size_t& _size)
		{
			_size = size;
			return buffer;
		}
		[[nodiscard]] std::pair<unsigned char*, size_t> GetBufferEx()
		{
			return { buffer, size };
		}
		[[nodiscard]] bool __fastcall IsSpace(int bytes2add, bool make_space = true)
		{
			if (size_t newsize = index + bytes2add; newsize > size)
			{
				if (make_space)
				{
					Resize(newsize); 
					return true;
				}
				else
					return false;
			}
			else
				return true;
		}
		void Resize()
		{
			size_t newsize = size_t(floor(size * 1.5));
			unsigned char* tmp = new unsigned char[newsize];
			memcpy(tmp, buffer, sizeof(buffer));
			delete[] buffer;
			buffer = tmp;
			size = newsize;
		}
		void __fastcall Resize(int newsize)
		{
			unsigned char* tmp = new unsigned char(newsize);
			memcpy(tmp, buffer, newsize);
			delete[] buffer;
			buffer = tmp;
			size = newsize;
		}
		void ShrinkToFit()
		{
			Resize(index);
		}
		void __fastcall Reset(int _size = 1024)
		{
			delete buffer;
			index = 0;
			buffer = new unsigned char[_size];
		}
		[[nodiscard]] int32_t ReadInt32()
		{
			int32_t ret = 0;
			memcpy(&ret, &buffer[index], sz_INT32);
			index += sz_INT32;
			return _byteswap_ulong(ret);
		}
		void __fastcall WriteInt32(int32_t val)
		{
			if (!IsSpace(sz_INT32))
				return;
			val = _byteswap_ulong(val);
			memcpy(&buffer[index], &val, sz_INT32);
			index += sz_INT32;
		}
		[[nodiscard]] uint32_t ReadUnsignedInt32()
		{
			uint32_t ret = 0;
			memcpy(&ret, &buffer[index], sz_UINT32);
			index += sz_UINT32;
			return _byteswap_ulong(ret);
		}
		void __fastcall WriteUnsignedInt32(uint32_t val)
		{
			if (!IsSpace(sz_UINT32))
				return;
			val = _byteswap_ulong(val);
			memcpy(&buffer[index], &val, sz_UINT32);
			index += sz_UINT32;
		}
		[[nodiscard]] int16_t ReadInt16()
		{
			int16_t ret = 0;
			memcpy(&ret, &buffer[index], sz_INT16);
			index += sz_INT16;
			return _byteswap_ushort(ret);
		}
		void __fastcall WriteInt16(int16_t val)
		{
			if (!IsSpace(sz_INT16))
				return;
			val = _byteswap_ushort(val);
			memcpy(&buffer[index], &val, sz_INT16);
			index += sz_INT16;
		}
		[[nodiscard]] uint16_t ReadUnsignedInt16()
		{
			uint16_t ret = 0;
			memcpy(&ret, &buffer[index], sz_UINT16);
			index += sz_UINT16;
			return _byteswap_ushort(ret);
		}
		void __fastcall WriteUnsignedInt16(uint16_t val)
		{
			if (!IsSpace(sz_UINT16))
				return;
			val = _byteswap_ushort(val);
			memcpy(&buffer[index], &val, sz_UINT16);
			index += sz_UINT16;
		}
		[[nodiscard]] int8_t ReadInt8()
		{
			int8_t ret = 0;
			memcpy(&ret, &buffer[index], sz_INT8);
			index += sz_INT8;
			return ret;
		}
		void __fastcall WriteInt8(int8_t val)
		{
			if (!IsSpace(sz_INT8))
				return;
			memcpy(&buffer[index], &val, sz_INT8);
		}
		[[nodiscard]] uint8_t ReadUnsignedInt8()
		{
			uint8_t ret = 0;
			memcpy(&ret, &buffer[index], sz_UINT8);
			index += sz_UINT8;
			return ret;
		}
		void __fastcall WriteUnsignedInt8(uint8_t val)
		{
			if (!IsSpace(sz_UINT8))
				return;
			memcpy(&buffer[index], &val, sz_UINT8);
			index += sz_UINT8;
		}
		[[nodiscard]] bool ReadBoolean()
		{
			return !!(ReadInt8() != 0);
		}
		void __fastcall WriteBoolean(bool val)
		{
			WriteInt8(!!(val ? 1 : 0));
		}
		[[nodiscard]] float ReadFloat()
		{
			float ret = 0.f;
			memcpy(&ret, &buffer[index], sz_FLOAT);
			index += sz_FLOAT;
			return ReverseFloat(ret);
		}
		void __fastcall WriteFloat(float val)
		{
			if (!IsSpace(sz_FLOAT))
				return;
			memcpy(&buffer[index], &val, sz_FLOAT);
			index += sz_FLOAT;
		}
		[[nodiscard]] char* __fastcall ReadByteArray(int16_t &_size)
		{
			_size = ReadInt16();
			char* arr = new char[_size];
			for (int i = 0; i < _size; i++, index++)
				arr[i] = buffer[index];
			return arr;
		}
		void __fastcall WriteByteArray(unsigned char* arr, const int16_t _size)
		{
			if (!arr || _size == 0)
			{
				WriteInt16(0); 
				return;
			}
			WriteInt16(_size);
			for (int i = 0; i < _size; i++, index++)
				buffer[index] = arr[i];
		}
		[[nodiscard]] void ReadByteArrayEx(std::vector<unsigned char> &v)
		{
			auto size = ReadInt16();
			v.resize(size);
			for (int i = 0; i < size; i++, index++)
				v[i] = buffer[index];
		}
		void WriteByteArrayEx(const std::vector<int8_t>& v)
		{
			auto sz = v.size();
			if (sz < 1)
			{
				WriteInt16(0);
				return;
			}
			WriteInt16((int16_t)sz);
			for (size_t i = 0; i < sz; i++, index++)
				buffer[index] = v[i];
		}
		[[nodiscard]] std::string& ReadString()
		{
			const auto len = ReadInt16();
			std::string ret = "";
			for (int i = 0; i < len; i++, index++)
				ret += (char)buffer[index];
			return ret;
		}
		void WriteString(const std::string &str)
		{
			if (str.length() < 1 || str == "")
			{
				WriteInt16(0); 
				return;
			}
			const auto len = str.length();
			WriteInt16((int16_t)len);
			for (size_t i = 0; i < len; i++, index++)
				buffer[index] = (char)str[i];
		}
		[[nodiscard]] std::u32string& ReadStringUTF32()
		{
			const auto len = ReadInt32();
			std::u32string ret = { };
			for (int i = 0; i < len; i += 4, index += 4)
			{
				char32_t c = 0;
				memcpy(&c, &buffer[index], 4);
				ret.push_back(c);
			}
			return ret;
		}
		void WriteStringUTF32(const std::u32string &str)
		{
			if (str.length() < 1)
			{
				WriteInt32(0);
				return;
			}
			const size_t len = str.length();
			WriteInt32(len);
			for (size_t i = 0; i < len; i+=4, index+=4)
				memcpy(&buffer[index], &str[i], 4);
		}
	};
}