#include <SomeGui/window.hpp>

SomeGui::Window::Window(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY) {

    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    glfwSetWindowPos(this->window, positionX, positionY);
    
    glfwSetWindowAttrib(this->window, GLFW_DECORATED, GLFW_FALSE);
    glfwSetWindowAttrib(this->window, GLFW_RESIZABLE, GLFW_TRUE);

    glfwMakeContextCurrent(this->window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    glClearColor(0.0f, 0.0f, 0.0f, 0.8f);
    glClearStencil(0x00);
    glStencilMask(0xFF);

    // Blend is need for anti-alias

    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_STENCIL_TEST);

    this->renderLoop();

}

SomeGui::Window::Window(std::string title, std::uint32_t width, std::uint32_t height) {

    Window(title, width, height, 100, 100);

}

void SomeGui::Window::show(void) {

    glfwShowWindow(this->window);

}
void SomeGui::Window::hide(void) {

    glfwHideWindow(this->window);

}

void SomeGui::Window::renderLoop(void) {

    while (!glfwWindowShouldClose(this->window)) {
        
        glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        glfwSwapBuffers(this->window);
        glfwPollEvents();

    }

}