#ifndef SOMEGUI_WINDOW_HPP
#define SOMEGUI_WINDOW_HPP

#include <cstdint>
#include <string>
#include "glad.hpp"
#include <GLFW/glfw3.h>

namespace SomeGui {

    namespace Interface {

        class Window {

            private:

            std::uint32_t width;
            std::uint32_t height;
            std::string title;
            bool rezisable;
            bool decorated;

            public:

            virtual void show(void) = 0;
            virtual void hide(void) = 0;
            //virtual void resize(std::uint32_t width, std::uint32_t height) = 0;

        };

    }

    class Window: public SomeGui::Interface::Window {

        private:

        GLFWwindow* window;

        public:

        Window(std::string title, std::uint32_t width, std::uint32_t height);
        Window(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY);
        //~Window();

        void renderLoop(void);
        virtual void show(void);
        virtual void hide(void);
        //virtual void resize(std::uint32_t width, std::uint32_t height);

    };

}

#endif  // SOMEGUI_WINDOW_HPP
