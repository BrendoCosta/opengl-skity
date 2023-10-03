#ifndef SOMEGUI_APPLICATION_WINDOW_INTERFACE_HPP
#define SOMEGUI_APPLICATION_WINDOW_INTERFACE_HPP

#include <SomeGui/glfw.hpp>
#include <SomeGui/interface/applicationWindow.hpp>

namespace SomeGui {

    namespace Interface {

        class ApplicationWindow {

            public:

            virtual ~ApplicationWindow() = default;

            virtual void show(void) = 0;
            virtual void hide(void) = 0;

        };

    }

}

#endif  // SOMEGUI_APPLICATION_WINDOW_INTERFACE_HPP
