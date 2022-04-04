//
// Created by DAOCa on 05/02/2022.
//

#ifndef AMBER_COMMON_H
#define AMBER_COMMON_H

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 04/04/2022
*
* Twitch : OpenGL Foundation in C/C++
*
* Contact Email : frazor.sharp@virginmedia.com
* Github		: https://github.com/FrazorBladezSharp/OpenGL_Foundation_Code.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp*
*
* ______________________________________________________*/


//#define AMBER_PLATFORM_WINDOWS
//#define AMBER_DEBUG


//#ifdef AMBER_PLATFORM_WINDOWS

//#include <Windows.h>

//#else

//#error Amber supports windows only

//#endif



//#ifdef AMBER_DEBUG

//#define AMBER_ENABLE_ASSERTS

//#endif



//#ifdef AMBER_ENABLE_ASSERTS

//#define DEV_ASSERT(x, ...) { if(!(x)) { DEV_ERROR("Assert Failure: {0}", __VA_ARGS__); __debugbreak(); }}

//#define AMBER_ASSERT(x, ...) { if(!(x)) { AMBER_ERROR("Assert Failure: {0}", __VA_ARGS__); __debugbreak(); }}

//#else

//#define DEV_ASSERT(x, ...)

//	#define AMBER_ASSERT(x, ...)

//#endif



//#define BIT(x) (1 << x)

//#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

//#include "Platform/OpenGL/glad.h"
//#include <GLFW/glfw3.h>


#include <algorithm>
#include <functional>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>


//#include <imgui.h>
//#include <backends/imgui_impl_glfw.h>
//#include <backends/imgui_impl_opengl3.h>

//#include "Amberskies/Core/Log.h"
//#include "Amberskies/Core/DeltaTime.h"

//#include "Amberskies/Events/Event.h"
//#include "Amberskies/Events/ApplicationEvent.h"
//#include "Amberskies/Events/KeyEvent.h"
//#include "Amberskies/Events/MouseEvent.h"




// Typedefs *********************************************

typedef uint8_t		u8;
typedef uint32_t    u32;
typedef uint64_t	u64;
typedef int8_t		i8;
typedef int32_t     i32;
typedef int64_t     i64;

#endif //AMBER_COMMON_H
