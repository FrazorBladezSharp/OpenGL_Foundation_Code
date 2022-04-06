
/**
* ________________________________________________________
* Project Created by Frazor Sharp : 04/04/2022
*
* Twitch : OpenGL Foundation in C/C++
*
* Contact Email : frazor.sharp@virginmedia.com
* Github		: https://github.com/FrazorBladezSharp/OpenGL_Foundation_Code.git
* Twitch		: frazorbladezsharp
* Youtube		: Frazor Sharp
*
* ______________________________________________________*/



#include <Amberskies.h>

#include <iostream>


class FirstLayer : public Amber::Layer
{

    float m_SimpleTimer = 0.0f;

public:

    FirstLayer() :
            Amber::Layer("FirstLayer")
    {

        std::cout
                << "[FirstLayer] : Constructed. \n";

//        DEV_INFO(
//                "First Layer Constructed"
//                );

    }

    ~FirstLayer() override
    {
        std::cout
                << "[FirstLayer] : Destroyed \n";
    }

//    void OnUpdate(Amber::DeltaTime deltaTime) override
//    {

//        float dt =
//                deltaTime.GetSeconds();

//        m_SimpleTimer +=
//                dt;

//        if (m_SimpleTimer >= 1)
//        {

//            DEV_INFO(
//                    "Delta time : {0}s   {1}ms",
//                    dt,
//                    deltaTime.GetMilliseconds()
//            );

//            m_SimpleTimer = 0.0f;

//        }

//    }

};



class Sandbox : public Amber::Application
{

public:

    Sandbox()
    {
        std::cout
                << "[Sandbox] : Constructed \n";

        PushLayer(
                new FirstLayer()
        );

    }

    ~Sandbox() override
    {
        std::cout
                << "[Sandbox] : Destroyed \n";
    }

};






//*******************************
// Main Entry Point for the User
//*******************************
#include <Amberskies/Core/MainEntryPoint.h>

Amber::Application* Amber::CreateApplication()
{

    return new Sandbox();

}


