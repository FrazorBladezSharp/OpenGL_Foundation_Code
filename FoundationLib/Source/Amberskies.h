
/**
* ________________________________________________________
*
* Project Created by Frazor Sharp : 16/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amber.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/


#pragma once


#define AMBER_PLATFORM_WINDOWS
#define AMBER_DEBUG


#ifdef AMBER_PLATFORM_WINDOWS

#include <Windows.h>

#else

#error Amber supports windows only

#endif




#include "Test.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

#include "Amberskies/Core/Application.h"
#include "Amberskies/Core/Log.h"
#include "Amberskies/Core/Layer.h"
#include "Amberskies/Core/DeltaTime.h"

#include "Amberskies/Events/Event.h"

//#include "Amberskies/Gui/ImGuiLayer.h"



