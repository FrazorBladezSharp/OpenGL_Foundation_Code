
#include "OpenGLTexture2D.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 10/02/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "stb_image.h"



namespace Amber
{

	OpenGLTexture2D::OpenGLTexture2D(
		u32 width,
		u32 height
	) :
		m_FilePath(" "),
		m_Width(width),
		m_Height(height),
		m_RendererID(0),
		m_InternalFormat(GL_RGBA8),
		m_DataFormat(GL_RGBA)
	{

		glCreateTextures(
			GL_TEXTURE_2D,
			1,
			&m_RendererID
		);

		glTextureStorage2D(
			m_RendererID,
			1,
			m_InternalFormat,
			m_Width,
			m_Height
		);

		glTextureParameteri(
			m_RendererID,
			GL_TEXTURE_MIN_FILTER,
			GL_LINEAR
		);

		glTextureParameteri(
			m_RendererID,
			GL_TEXTURE_MAG_FILTER,
			GL_NEAREST
		);

	}



	OpenGLTexture2D::OpenGLTexture2D(
		const std::string& filePath
	) :
		m_FilePath(filePath),
		m_Width(0),
		m_Height(0),
		m_RendererID(0)
	{

		int width;

		int height;

		int channels;

		stbi_set_flip_vertically_on_load(
			true
		);

		stbi_uc* imageData =  stbi_load(
			filePath.c_str(),
			&width,
			&height,
			&channels,
			0
		);

		AMBER_ASSERT(
			imageData,
			"[OpenGLTexture2D] Failed to load image."
		);

		m_Width = width;

		m_Height = height;

		GLenum channelFormat =
			0;

		GLenum dataFormat =
			0;

		if (channels == 4)
		{

			channelFormat = GL_RGBA8;

			dataFormat = GL_RGBA;

		}
		else if (channels == 3)
		{

			channelFormat = GL_RGB8;

			dataFormat = GL_RGB;

		}

		m_InternalFormat =
			channelFormat;

		m_DataFormat =
			dataFormat;
		
		AMBER_ASSERT(
			channelFormat & dataFormat,
			"[OpenGLTexture2D] Image format not supported."
		);

		glCreateTextures(
			GL_TEXTURE_2D,
			1,
			&m_RendererID
		);

		glTextureStorage2D(
			m_RendererID,
			1,
			channelFormat,
			m_Width,
			m_Height
		);

		glTextureParameteri(
			m_RendererID,
			GL_TEXTURE_MIN_FILTER,
			GL_LINEAR
		);

		glTextureParameteri(
			m_RendererID,
			GL_TEXTURE_MAG_FILTER,
			GL_NEAREST
		);

		glTextureSubImage2D(
			m_RendererID,
			0,
			0,
			0,
			m_Width,
			m_Height,
			dataFormat,
			GL_UNSIGNED_BYTE,
			imageData
		);

		stbi_image_free(
			imageData
		);

	}


	


	OpenGLTexture2D::~OpenGLTexture2D()
	{

		glDeleteTextures(
			1,
			&m_RendererID
		);

	}


	void OpenGLTexture2D::SetData(
		void* data,
		u32 size)
	{

		u32 bpp =
			m_DataFormat == GL_RGBA ?
			4 : 3;

		AMBER_ASSERT(
			size == (m_Width * m_Height * bpp),
			"[OpenGLTexture2D] SetData is incorrect size."
		);

		glTexSubImage2D(
			m_RendererID,
			0,
			0,
			0,
			m_Width,
			m_Height,
			m_DataFormat,
			GL_UNSIGNED_BYTE,
			data
		);

	}



	void OpenGLTexture2D::Bind(
		u32 slot
	) const
	{

		glBindTextureUnit(
			slot,
			m_RendererID
		);

	}

}
