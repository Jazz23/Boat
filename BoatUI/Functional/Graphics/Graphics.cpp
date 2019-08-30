#include "Graphics.h"
#include "../Color.h"
#include "../Settings.h"

#include <iostream>

#pragma comment( lib,"d3d11.lib" )

namespace G
{
	const BYTE FramebufferPSBytecode[] =
	{
		 68,  88,  66,  67, 110, 125,
		 50,  48, 174, 178,  52,  10,
		159, 213, 105, 203, 142, 119,
		244, 196,   1,   0,   0,   0,
		172,   2,   0,   0,   6,   0,
		  0,   0,  56,   0,   0,   0,
		164,   0,   0,   0,  16,   1,
		  0,   0, 140,   1,   0,   0,
		 32,   2,   0,   0, 120,   2,
		  0,   0,  65, 111, 110,  57,
		100,   0,   0,   0, 100,   0,
		  0,   0,   0,   2, 255, 255,
		 60,   0,   0,   0,  40,   0,
		  0,   0,   0,   0,  40,   0,
		  0,   0,  40,   0,   0,   0,
		 40,   0,   1,   0,  36,   0,
		  0,   0,  40,   0,   0,   0,
		  0,   0,   0,   2, 255, 255,
		 31,   0,   0,   2,   0,   0,
		  0, 128,   0,   0,   3, 176,
		 31,   0,   0,   2,   0,   0,
		  0, 144,   0,   8,  15, 160,
		 66,   0,   0,   3,   0,   0,
		 15, 128,   0,   0, 228, 176,
		  0,   8, 228, 160,   1,   0,
		  0,   2,   0,   8,  15, 128,
		  0,   0, 228, 128, 255, 255,
		  0,   0,  83,  72,  68,  82,
		100,   0,   0,   0,  64,   0,
		  0,   0,  25,   0,   0,   0,
		 90,   0,   0,   3,   0,  96,
		 16,   0,   0,   0,   0,   0,
		 88,  24,   0,   4,   0, 112,
		 16,   0,   0,   0,   0,   0,
		 85,  85,   0,   0,  98,  16,
		  0,   3,  50,  16,  16,   0,
		  1,   0,   0,   0, 101,   0,
		  0,   3, 242,  32,  16,   0,
		  0,   0,   0,   0,  69,   0,
		  0,   9, 242,  32,  16,   0,
		  0,   0,   0,   0,  70,  16,
		 16,   0,   1,   0,   0,   0,
		 70, 126,  16,   0,   0,   0,
		  0,   0,   0,  96,  16,   0,
		  0,   0,   0,   0,  62,   0,
		  0,   1,  83,  84,  65,  84,
		116,   0,   0,   0,   2,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   2,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   1,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  1,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		 82,  68,  69,  70, 140,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   2,   0,
		  0,   0,  28,   0,   0,   0,
		  0,   4, 255, 255,   0,   1,
		  0,   0, 100,   0,   0,   0,
		 92,   0,   0,   0,   3,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  1,   0,   0,   0,   1,   0,
		  0,   0,  96,   0,   0,   0,
		  2,   0,   0,   0,   5,   0,
		  0,   0,   4,   0,   0,   0,
		255, 255, 255, 255,   0,   0,
		  0,   0,   1,   0,   0,   0,
		 13,   0,   0,   0, 115,  97,
		109,   0, 116, 101, 120,   0,
		 77, 105,  99, 114, 111, 115,
		111, 102, 116,  32,  40,  82,
		 41,  32,  72,  76,  83,  76,
		 32,  83, 104,  97, 100, 101,
		114,  32,  67, 111, 109, 112,
		105, 108, 101, 114,  32,  49,
		 48,  46,  49,   0,  73,  83,
		 71,  78,  80,   0,   0,   0,
		  2,   0,   0,   0,   8,   0,
		  0,   0,  56,   0,   0,   0,
		  0,   0,   0,   0,   1,   0,
		  0,   0,   3,   0,   0,   0,
		  0,   0,   0,   0,  15,   0,
		  0,   0,  68,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   3,   0,   0,   0,
		  1,   0,   0,   0,   3,   3,
		  0,   0,  83,  86,  95,  80,
		 79,  83,  73,  84,  73,  79,
		 78,   0,  84,  69,  88,  67,
		 79,  79,  82,  68,   0, 171,
		171, 171,  79,  83,  71,  78,
		 44,   0,   0,   0,   1,   0,
		  0,   0,   8,   0,   0,   0,
		 32,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  3,   0,   0,   0,   0,   0,
		  0,   0,  15,   0,   0,   0,
		 83,  86,  95,  84,  65,  82,
		 71,  69,  84,   0, 171, 171
	};
	const BYTE FramebufferVSBytecode[] =
	{
		 68,  88,  66,  67,  83, 152,
		  2,  47, 214, 134, 240,  34,
		163,  84, 153, 111, 193, 243,
		 44,   5,   1,   0,   0,   0,
		152,   2,   0,   0,   6,   0,
		  0,   0,  56,   0,   0,   0,
		180,   0,   0,   0,  36,   1,
		  0,   0, 160,   1,   0,   0,
		236,   1,   0,   0,  64,   2,
		  0,   0,  65, 111, 110,  57,
		116,   0,   0,   0, 116,   0,
		  0,   0,   0,   2, 254, 255,
		 76,   0,   0,   0,  40,   0,
		  0,   0,   0,   0,  36,   0,
		  0,   0,  36,   0,   0,   0,
		 36,   0,   0,   0,  36,   0,
		  1,   0,  36,   0,   0,   0,
		  0,   0,   0,   2, 254, 255,
		 31,   0,   0,   2,   5,   0,
		  0, 128,   0,   0,  15, 144,
		 31,   0,   0,   2,   5,   0,
		  1, 128,   1,   0,  15, 144,
		  4,   0,   0,   4,   0,   0,
		  3, 192,   0,   0, 255, 144,
		  0,   0, 228, 160,   0,   0,
		228, 144,   1,   0,   0,   2,
		  0,   0,  12, 192,   0,   0,
		228, 144,   1,   0,   0,   2,
		  0,   0,   3, 224,   1,   0,
		228, 144, 255, 255,   0,   0,
		 83,  72,  68,  82, 104,   0,
		  0,   0,  64,   0,   1,   0,
		 26,   0,   0,   0,  95,   0,
		  0,   3, 242,  16,  16,   0,
		  0,   0,   0,   0,  95,   0,
		  0,   3,  50,  16,  16,   0,
		  1,   0,   0,   0, 103,   0,
		  0,   4, 242,  32,  16,   0,
		  0,   0,   0,   0,   1,   0,
		  0,   0, 101,   0,   0,   3,
		 50,  32,  16,   0,   1,   0,
		  0,   0,  54,   0,   0,   5,
		242,  32,  16,   0,   0,   0,
		  0,   0,  70,  30,  16,   0,
		  0,   0,   0,   0,  54,   0,
		  0,   5,  50,  32,  16,   0,
		  1,   0,   0,   0,  70,  16,
		 16,   0,   1,   0,   0,   0,
		 62,   0,   0,   1,  83,  84,
		 65,  84, 116,   0,   0,   0,
		  3,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  4,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   1,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   2,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,  82,  68,  69,  70,
		 68,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,  28,   0,
		  0,   0,   0,   4, 254, 255,
		  0,   1,   0,   0,  28,   0,
		  0,   0,  77, 105,  99, 114,
		111, 115, 111, 102, 116,  32,
		 40,  82,  41,  32,  72,  76,
		 83,  76,  32,  83, 104,  97,
		100, 101, 114,  32,  67, 111,
		109, 112, 105, 108, 101, 114,
		 32,  49,  48,  46,  49,   0,
		 73,  83,  71,  78,  76,   0,
		  0,   0,   2,   0,   0,   0,
		  8,   0,   0,   0,  56,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   3,   0,
		  0,   0,   0,   0,   0,   0,
		 15,  15,   0,   0,  65,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   3,   0,
		  0,   0,   1,   0,   0,   0,
		  3,   3,   0,   0,  80,  79,
		 83,  73,  84,  73,  79,  78,
		  0,  84,  69,  88,  67,  79,
		 79,  82,  68,   0, 171, 171,
		 79,  83,  71,  78,  80,   0,
		  0,   0,   2,   0,   0,   0,
		  8,   0,   0,   0,  56,   0,
		  0,   0,   0,   0,   0,   0,
		  1,   0,   0,   0,   3,   0,
		  0,   0,   0,   0,   0,   0,
		 15,   0,   0,   0,  68,   0,
		  0,   0,   0,   0,   0,   0,
		  0,   0,   0,   0,   3,   0,
		  0,   0,   1,   0,   0,   0,
		  3,  12,   0,   0,  83,  86,
		 95,  80,  79,  83,  73,  84,
		 73,  79,  78,   0,  84,  69,
		 88,  67,  79,  79,  82,  68,
		  0, 171, 171, 171
	};


	struct FSQVertex
	{
		float x, y, z;		// position
		float u, v;			// texcoords
	};

	Microsoft::WRL::ComPtr<IDXGISwapChain>				pSwapChain;
	Microsoft::WRL::ComPtr<ID3D11Device>				pDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			pImmediateContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		pRenderTargetView;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				pSysBufferTexture;
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView>	pSysBufferTextureView;
	Microsoft::WRL::ComPtr<ID3D11PixelShader>			pPixelShader;
	Microsoft::WRL::ComPtr<ID3D11VertexShader>			pVertexShader;
	Microsoft::WRL::ComPtr<ID3D11Buffer>				pVertexBuffer;
	Microsoft::WRL::ComPtr<ID3D11InputLayout>			pInputLayout;
	Microsoft::WRL::ComPtr<ID3D11SamplerState>			pSamplerState;
	D3D11_MAPPED_SUBRESOURCE							mappedSysBufferTexture;
	Color* pSysBuffer = nullptr;

	void FrameBegin()
	{
		memset(pSysBuffer, 0u, sizeof(Color) * WINDOW_HEIGHT * WINDOW_WIDTH);
	}
	
	void PutPixel(int x, int y, Color c)
	{
		assert(x >= 0);
		assert(x < int(WINDOW_WIDTH));
		assert(y >= 0);
		assert(y < int(WINDOW_HEIGHT));
		pSysBuffer[WINDOW_WIDTH * y + x] = c;
	}
	Color GetPixel(int x, int y)
	{
		assert(x >= 0);
		assert(x < int(WINDOW_WIDTH));
		assert(y >= 0);
		assert(y < int(WINDOW_HEIGHT));
		return pSysBuffer[WINDOW_WIDTH * y + x];
	}

	void Setup()
	{
		assert(Settings::hWnd != nullptr);

		auto wHWND = Settings::hWnd;

		DXGI_SWAP_CHAIN_DESC sd = {};
		sd.BufferCount = 1;
		sd.BufferDesc.Width = WINDOW_WIDTH;
		sd.BufferDesc.Height = WINDOW_HEIGHT;
		sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 1;
		sd.BufferDesc.RefreshRate.Denominator = 60;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.OutputWindow = Settings::hWnd;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.Windowed = TRUE;

		HRESULT				hr;
		UINT				createFlags = 0u;

		if (FAILED(hr = D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			createFlags,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&sd,
			&pSwapChain,
			&pDevice,
			nullptr,
			&pImmediateContext)))
		{
			assert(0);
		}

		Microsoft::WRL::ComPtr<ID3D11Resource> pBackBuffer;
		if (FAILED(hr = pSwapChain->GetBuffer(
			0,
			__uuidof(ID3D11Texture2D),
			(LPVOID*)& pBackBuffer)))
		{
			assert(0);
		}

		if (FAILED(hr = pDevice->CreateRenderTargetView(
			pBackBuffer.Get(),
			nullptr,
			&pRenderTargetView)))
		{
			assert(0);
		}
		pImmediateContext->OMSetRenderTargets(1, pRenderTargetView.GetAddressOf(), nullptr);


		D3D11_VIEWPORT vp;
		vp.Width = float(WINDOW_WIDTH);
		vp.Height = float(WINDOW_HEIGHT);
		vp.MinDepth = 0.0f;
		vp.MaxDepth = 1.0f;
		vp.TopLeftX = 0.0f;
		vp.TopLeftY = 0.0f;
		pImmediateContext->RSSetViewports(1, &vp);

		D3D11_TEXTURE2D_DESC sysTexDesc;
		sysTexDesc.Width = WINDOW_WIDTH;
		sysTexDesc.Height = WINDOW_HEIGHT;
		sysTexDesc.MipLevels = 1;
		sysTexDesc.ArraySize = 1;
		sysTexDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		sysTexDesc.SampleDesc.Count = 1;
		sysTexDesc.SampleDesc.Quality = 0;
		sysTexDesc.Usage = D3D11_USAGE_DYNAMIC;
		sysTexDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
		sysTexDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		sysTexDesc.MiscFlags = 0;
		if (FAILED(hr = pDevice->CreateTexture2D(&sysTexDesc, nullptr, &pSysBufferTexture)))
		{
			assert(0);
		}

		D3D11_SHADER_RESOURCE_VIEW_DESC srvDesc = {};
		srvDesc.Format = sysTexDesc.Format;
		srvDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		srvDesc.Texture2D.MipLevels = 1;
		if (FAILED(hr = pDevice->CreateShaderResourceView(pSysBufferTexture.Get(),
			&srvDesc, &pSysBufferTextureView)))
		{
			assert(0);
		}

		if (FAILED(hr = pDevice->CreatePixelShader(
			FramebufferPSBytecode,
			sizeof(FramebufferPSBytecode),
			nullptr,
			&pPixelShader)))
		{
			assert(0);
		}

		if (FAILED(hr = pDevice->CreateVertexShader(
			FramebufferVSBytecode,
			sizeof(FramebufferVSBytecode),
			nullptr,
			&pVertexShader)))
		{
			assert(0);
		}

		const FSQVertex vertices[] =
		{
			{ -1.0f,1.0f,0.5f,0.0f,0.0f },
			{ 1.0f,1.0f,0.5f,1.0f,0.0f },
			{ 1.0f,-1.0f,0.5f,1.0f,1.0f },
			{ -1.0f,1.0f,0.5f,0.0f,0.0f },
			{ 1.0f,-1.0f,0.5f,1.0f,1.0f },
			{ -1.0f,-1.0f,0.5f,0.0f,1.0f },
		};
		D3D11_BUFFER_DESC bd = {};
		bd.Usage = D3D11_USAGE_DEFAULT;
		bd.ByteWidth = sizeof(FSQVertex) * 6;
		bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bd.CPUAccessFlags = 0u;
		D3D11_SUBRESOURCE_DATA initData = {};
		initData.pSysMem = vertices;
		if (FAILED(hr = pDevice->CreateBuffer(&bd, &initData, &pVertexBuffer)))
		{
			assert(0);
		}

		const D3D11_INPUT_ELEMENT_DESC ied[] =
		{
			{ "POSITION",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
			{ "TEXCOORD",0,DXGI_FORMAT_R32G32_FLOAT,0,12,D3D11_INPUT_PER_VERTEX_DATA,0 }
		};

		if (FAILED(hr = pDevice->CreateInputLayout(ied, 2,
			FramebufferVSBytecode,
			sizeof(FramebufferVSBytecode),
			&pInputLayout)))
		{
			assert(0);
		}

		D3D11_SAMPLER_DESC sampDesc = {};
		sampDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT;
		sampDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
		sampDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
		sampDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
		sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
		sampDesc.MinLOD = 0;
		sampDesc.MaxLOD = D3D11_FLOAT32_MAX;
		if (FAILED(hr = pDevice->CreateSamplerState(&sampDesc, &pSamplerState)))
		{
			assert(0);
		}

		pSysBuffer = reinterpret_cast<Color*>(
			_aligned_malloc(sizeof(Color) * WINDOW_WIDTH * WINDOW_HEIGHT, 16u));
	}
	
	
	void FrameEnd()
	{
		HRESULT hr;

		if (FAILED(hr = pImmediateContext->Map(pSysBufferTexture.Get(), 0u,
			D3D11_MAP_WRITE_DISCARD, 0u, &mappedSysBufferTexture)))
		{
			assert(0);
		}
		Color* pDst = reinterpret_cast<Color*>(mappedSysBufferTexture.pData);
		const size_t dstPitch = mappedSysBufferTexture.RowPitch / sizeof(Color);
		const size_t srcPitch = WINDOW_WIDTH;
		const size_t rowBytes = srcPitch * sizeof(Color);
		for (size_t y = 0u; y < WINDOW_HEIGHT; y++)
		{
			memcpy(&pDst[y * dstPitch], &pSysBuffer[y * srcPitch], rowBytes);
		}
		pImmediateContext->Unmap(pSysBufferTexture.Get(), 0u);

		pImmediateContext->IASetInputLayout(pInputLayout.Get());
		pImmediateContext->VSSetShader(pVertexShader.Get(), nullptr, 0u);
		pImmediateContext->PSSetShader(pPixelShader.Get(), nullptr, 0u);
		pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		const UINT stride = sizeof(FSQVertex);
		const UINT offset = 0u;
		pImmediateContext->IASetVertexBuffers(0u, 1u, pVertexBuffer.GetAddressOf(), &stride, &offset);
		pImmediateContext->PSSetShaderResources(0u, 1u, pSysBufferTextureView.GetAddressOf());
		pImmediateContext->PSSetSamplers(0u, 1u, pSamplerState.GetAddressOf());
		pImmediateContext->Draw(6u, 0u);

		if (FAILED(hr = pSwapChain->Present(1u, 0u)))
		{
			if (hr == DXGI_ERROR_DEVICE_REMOVED)
			{
				assert(0);
			}
			else
			{
				assert(0);
			}
		}
	}
}
