#pragma once

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 19/01/2022
*
* Twitch : Mini Game Engine Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amberskies.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/





#include "Common.h"

#include <glm/glm.hpp>

#include "Amberskies/Render3D/RenderCommand.h"
#include "Amberskies/Render3D/PerspectiveCamera.h"
#include "Amberskies/Render3D/ShaderAPI.h"



namespace Amber
{
	
	class Renderer
	{

		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;


	public:

		static void Initialize();

		static void OnWindowResize(
			u32 width,
			u32 height
		);

		static void BeginScene(
			PerspectiveCamera& camera
		);

		static void EndScene();

		static void Submit(
			const Ref<Shader>& shader,
			const Ref<VertexArray>& vertexArray,
			const glm::mat4& modelTransform = glm::mat4(1.0f)
		);

		inline static RendererAPI::API GetAPI() { 
			return RendererAPI::GetAPI(); }
		
	};

}
