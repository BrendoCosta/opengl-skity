#ifndef SOMEGUI_APPLICATION_HPP
#define SOMEGUI_APPLICATION_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <thread>
#include <SomeGui/glfw.hpp>
#include <SomeGui/interface/application.hpp>
#include <SomeGui/applicationWindow.hpp>

namespace SomeGui {

    class Application: public SomeGui::Interface::Application {

        private:

        std::vector<std::unique_ptr<SomeGui::ApplicationWindow>> applicationWindowVec;
        //std::unique_ptr<SomeGui::ApplicationWindow> applicationWindow;
        void initialize(void);

        public:

        Application(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY);
        Application(std::string title, std::uint32_t width, std::uint32_t height);
        ~Application();

        void run(void);
        virtual void end(void);

    };

}

#endif  // SOMEGUI_APPLICATION_GLFW_HPP