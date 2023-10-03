#include <SomeGui/applicationWindow.hpp>
#include <iostream>

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

SomeGui::ApplicationWindow::ApplicationWindow(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY, GLFWwindow* share) {

    if (!share) {

        std::cout << "Create solo window" << std::endl;
        this->window = glfwCreateWindow(width, height, title.c_str(), NULL, nullptr);

    } else {

        std::cout << "Create shared window" << std::endl;
        this->window = glfwCreateWindow(width, height, title.c_str(), NULL, share);

    }

    if (!this->window) {

        std::cout << "GLFW terminate" << std::endl;
        glfwTerminate();
        std::exit(EXIT_FAILURE);

    }

    std::cout << "Set window position" << std::endl;

    glfwSetWindowPos(this->window, positionX, positionY);
    glfwSetWindowAttrib(this->window, GLFW_DECORATED, GLFW_FALSE);
    glfwSetWindowAttrib(this->window, GLFW_RESIZABLE, GLFW_TRUE);

    std::cout << "Set key callback" << std::endl;

    glfwSetKeyCallback(this->window, key_callback);

    std::cout << "Finish window creation" << std::endl;

    //glfwMakeContextCurrent(this->window);
    //gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    //glfwSwapInterval(1);

    //this->canvas.initialize(this->window);

    if (!this->window) {

        std::cout << "Erro ao criar janela" << std::endl;

    }

    //glClearColor(0.0f, 0.0f, 0.0f, 0.5f);

    /*while (!glfwWindowShouldClose(this->window)) {
        
        glClear(GL_COLOR_BUFFER_BIT);
 
        glfwSwapBuffers(this->window);
        glfwPollEvents();

    }*/

}

SomeGui::ApplicationWindow::ApplicationWindow(std::string title, std::uint32_t width, std::uint32_t height) {

    ApplicationWindow(title, width, height, 100, 100, NULL);

}

SomeGui::ApplicationWindow::~ApplicationWindow(void) {

    //glfwDestroyWindow(this->window);

}

void SomeGui::ApplicationWindow::show(void) {

    glfwShowWindow(this->window);

}
void SomeGui::ApplicationWindow::hide(void) {

    glfwHideWindow(this->window);

}

GLFWwindow* SomeGui::ApplicationWindow::getWindowObject(void) {

    return this->window;

}