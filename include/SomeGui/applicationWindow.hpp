#include <SomeGui/glfw.hpp>
#include <SomeGui/interface/applicationWindow.hpp>
#include <SomeGui/canvas.hpp>

namespace SomeGui {

    class ApplicationWindow: public SomeGui::Interface::ApplicationWindow {

        private:

        GLFWwindow* window;
        

        public:

        SomeGui::Canvas canvas;

        ApplicationWindow(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY);
        ApplicationWindow(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY, GLFWwindow* share);
        ApplicationWindow(std::string title, std::uint32_t width, std::uint32_t height);
        ~ApplicationWindow(void);
        virtual void show(void);
        virtual void hide(void);
        GLFWwindow* getWindowObject(void);

    };

}