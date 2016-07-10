/*
 * Window.cpp
 * 
 * This file is part of the "LLGL" project (Copyright (c) 2015 by Lukas Hermanns)
 * See "LICENSE.txt" for license information.
 */

#include <LLGL/Window.h>
#include "../Core/Helper.h"


namespace LLGL
{


#define FOREACH_LISTENER(i) \
    for (const auto& i : listeners_)

Window::Listener::~Listener()
{
}

void Window::Listener::OnReset()
{
    // dummy
}

void Window::Listener::OnKeyDown(Key keyCode)
{
    // dummy
}

void Window::Listener::OnKeyUp(Key keyCode)
{
    // dummy
}
                
void Window::Listener::OnChar(wchar_t chr)
{
    // dummy
}

void Window::Listener::OnWheelMotion(int motion)
{
    // dummy
}

void Window::Listener::OnLocalMotion(const Point& position)
{
    // dummy
}

void Window::Listener::OnGlobalMotion(const Point& motion)
{
    // dummy
}


Window::~Window()
{
}

bool Window::ProcessEvents()
{
    FOREACH_LISTENER(lst)
        lst->OnReset();

    ProcessSystemEvents();

    return (!quit_);
}

/* --- Event handling --- */

void Window::AddListener(const std::shared_ptr<Listener>& listener)
{
    AddListenerGlob(listeners_, listener);
}

void Window::RemoveListener(const Listener* listener)
{
    RemoveListenerGlob(listeners_, listener);
}

void Window::PostKeyDown(Key keyCode)
{
    FOREACH_LISTENER(lst)
        lst->OnKeyDown(keyCode);
}

void Window::PostKeyUp(Key keyCode)
{
    FOREACH_LISTENER(lst)
        lst->OnKeyUp(keyCode);
}

void Window::PostChar(wchar_t chr)
{
    FOREACH_LISTENER(lst)
        lst->OnChar(chr);
}

void Window::PostWheelMotion(int motion)
{
    FOREACH_LISTENER(lst)
        lst->OnWheelMotion(motion);
}

void Window::PostLocalMotion(const Point& position)
{
    FOREACH_LISTENER(lst)
        lst->OnLocalMotion(position);
}

void Window::PostGlobalMotion(const Point& motion)
{
    FOREACH_LISTENER(lst)
        lst->OnGlobalMotion(motion);
}

void Window::PostQuit()
{
    quit_ = true;
}

#undef FOREACH_LISTENER


} // /namespace LLGL



// ================================================================================