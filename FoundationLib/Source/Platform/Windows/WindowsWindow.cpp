
#include "WindowsWindow.h"

/**
* ________________________________________________________
* Project Created by Frazor Sharp : 17/01/2022
*
* Twitch : Simple Server Programming in C/C++
*
* Contact Email : daocamberskies@googlemail.com
* Github		: https://github.com/Avengez/Amber.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/




#include "Amberskies/Events/ApplicationEvent.h"
#include "Amberskies/Events/KeyEvent.h"
#include "Amberskies/Events/MouseEvent.h"



namespace Amber
{

    static bool s_GLFWInitialized = false;



	static void GLFWErrorCallback(
		int error,
		const char* description)
	{

        AMBER_ERROR(
                "[WindowsWindow] GLFW error ({0}): {1}",
                error,
                description
                );

	}



	Window* Window::Create(const WindowProperties& props)
	{

		return new WindowsWindow(props);

	}
	


#pragma clang diagnostic push
#pragma ide diagnostic ignored "VirtualCallInCtorOrDtor"
	WindowsWindow::WindowsWindow(const WindowProperties& props)
	{
		
		Initialize(
			props
		);

	}
#pragma clang diagnostic pop



#pragma clang diagnostic push
#pragma ide diagnostic ignored "VirtualCallInCtorOrDtor"
	WindowsWindow::~WindowsWindow()
	{

		Shutdown();

	}
#pragma clang diagnostic pop



	void WindowsWindow::OnUpdate()
	{
		
		glfwPollEvents();

		m_gfxContext->SwapBuffers();
		
	}



	void WindowsWindow::SetVSync(bool enabled)
	{
		
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = 
			enabled;

	}



	bool WindowsWindow::IsVSync() const
	{

		return m_Data.VSync;

	}



	void WindowsWindow::Initialize(const WindowProperties& props)
	{
		
		m_Data.Title = 
			props.Title;

		m_Data.Width =
			props.Width;

		m_Data.Height =
			props.Height;

		AMBER_TRACE("[WindowsWindow] Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Width, m_Data.Height);

		if (!s_GLFWInitialized)
		{

			int success = glfwInit();

			AMBER_ASSERT(success, "[WindowsWindow]: Unable to initialize GLFW")

			glfwSetErrorCallback(
				GLFWErrorCallback
			);
		
			s_GLFWInitialized = 
				true;

		}

		m_Window = glfwCreateWindow(
			(int)m_Data.Width,
			(int)m_Data.Height,
			m_Data.Title.c_str(),
			nullptr,
			nullptr
		);

		m_gfxContext = new OpenGLContext(m_Window);
		
		m_gfxContext->Initialize();
		
		glfwSetWindowUserPointer(
			m_Window,
			&m_Data
		);

		SetVSync(
			true
		);

		// set GLFW callbacks

		glfwSetWindowSizeCallback(
			m_Window,
			[](
				GLFWwindow* window,
				int width,
				int height
			)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				data.Width =
					width;

				data.Height =
					height;

				WindowResizeEvent event(
					width,
					height
				);

				data.EventCallback(
					event
				);

			}
		);

		glfwSetWindowCloseCallback(
			m_Window,
			[](
				GLFWwindow* window
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				WindowCloseEvent event;

				data.EventCallback(
					event
				);

			}
		);

		glfwSetKeyCallback(
			m_Window,
			[](
				GLFWwindow* window,
				int key,
				int scancode,
				int action,
				int mods
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				switch (action)
				{

					case GLFW_PRESS :
					{

						KeyPressedEvent event(
							key,
							0
						);

						data.EventCallback(
							event
						);

						break;

					}

					case GLFW_RELEASE :
					{

						KeyReleasedEvent event(
							key
							);

						data.EventCallback(
							event
						);

						break;

					}

					case GLFW_REPEAT :
					{

						KeyPressedEvent event(
							key,
							1
							);

						data.EventCallback(
							event
						);

						break;

					}

				}

			}
		);

		glfwSetCharCallback(
			m_Window,
			[](
				GLFWwindow* window,
				unsigned int character
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				KeyTypedEvent event(
					character
				);

				data.EventCallback(
					event
				);

			}
		);

		glfwSetMouseButtonCallback(
			m_Window,
			[](
				GLFWwindow* window,
				int button,
				int action,
				int mods
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				switch (action)
				{

					case GLFW_PRESS:
					{

						MouseButtonPressedEvent event(
							button
							);

						data.EventCallback(
							event
						);

						break;

					}

					case GLFW_RELEASE:
					{

						MouseButtonReleasedEvent event(
							button
							);

						data.EventCallback(
							event
						);

						break;

					}

				}

			}
		);

		glfwSetScrollCallback(
			m_Window,
			[](
				GLFWwindow* window,
				double xoffset,
				double yoffset
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				MouseScrolledEvent event(
					(float)xoffset,
					(float)yoffset
				);

				data.EventCallback(
					event
				);

			}
		);

		glfwSetCursorPosCallback(
			m_Window,
			[](
				GLFWwindow* window,
				double xpos,
				double ypos
				)
			{

				WindowData& data =
					*(WindowData*)glfwGetWindowUserPointer(
						window
				);

				MouseMovedEvent event(
					(float)xpos,
					(float)ypos
					);

				data.EventCallback(
					event
				);

			}

		);

	}



	void WindowsWindow::Shutdown()
	{

		glfwDestroyWindow(
			m_Window
		);

	}

}