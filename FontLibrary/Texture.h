//=================================================================================
// Name			:	Texture.h
// Author		:	Christian Thurow
// Date			:	March 30th 2020
// Description	:	Header file for CGLTexture, used by the FontLibrary
//=================================================================================

#include <Windows.h>
#include <glew.h>
#include <string>

struct CRawTexture
{
	CRawTexture(){}
	~CRawTexture()
	{
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}
	}

	uint16_t m_channels = 0;
	uint16_t m_sizeX = 0;
	uint16_t m_sizeY = 0;
	uint8_t *m_data = nullptr;
};

class CGLTexture
{
public:
	CGLTexture(){};
	~CGLTexture(){};

	static bool LoadTextureFromFile(const std::string& strFileName, uint32_t& texID, bool compressTexture = false);
	static bool GetTextureSizeFromFile(const std::string& strFileName, float &w, float &h);
	
private:
	// This Loads And Returns The TGA Image Data
	static CRawTexture *LoadTGA(const std::string& strFileName);
	static CRawTexture *LoadPNG(const std::string& strFileName);
};