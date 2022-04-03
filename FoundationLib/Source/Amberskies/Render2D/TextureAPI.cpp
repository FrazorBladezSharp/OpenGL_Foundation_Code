
#include "TextureAPI.h"

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




#include "Amberskies/Render3D/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture2D.h"



namespace Amber
{

	Ref<Texture2D> Texture2D::Create(
		const std::string& filePath)
	{

		switch (Renderer::GetAPI())
		{

			case RendererAPI::API::None:
			{

				AMBER_ASSERT(
					false,
					"[TextureAPI] no Renderer API specified."
				);

				break;

			}

			case RendererAPI::API::OpenGL:
			{

				return CreateRef<OpenGLTexture2D>(
					filePath
				);

				break;

			}

			default:
			{

				AMBER_ASSERT(
					false,
					"[VertexArray] Unknown Renderer API."
				);

			}

		}

		return nullptr;

	}

	Ref<Texture2D> Texture2D::Create(
		u32 width, 
		u32 height)
	{

		switch (Renderer::GetAPI())
		{

		case RendererAPI::API::None:
		{

			AMBER_ASSERT(
				false,
				"[TextureAPI] no Renderer API specified."
			);

			break;

		}

		case RendererAPI::API::OpenGL:
		{

			return CreateRef<OpenGLTexture2D>(
				width,
				height
			);

			break;

		}

		default:
		{

			AMBER_ASSERT(
				false,
				"[VertexArray] Unknown Renderer API."
			);

		}

		}

		return nullptr;
	
	}

}
