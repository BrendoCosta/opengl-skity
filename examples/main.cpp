#include <iostream>
#include <SomeGui/application.hpp>
#include <SomeGui/os.hpp>
#include <config.hpp>

int main(int argc, char *argv[]) {

    // clear && meson setup --wipe build && ninja -C ./build/ && valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --keep-debuginfo=yes ./build/examples/example
    // clear && meson setup --wipe build && ninja -C ./build/ && ./build/examples/example

    std::cout << _SOMEGUI_VERSION << std::endl;
    std::cout << SomeGui::OS::getProcessId() << std::endl;
    SomeGui::Application app = SomeGui::Application("Teste", 800, 600);

}

/*#include <SomeGui/application.hpp>
#include <SomeGui/window.hpp>
#include <SomeGui/glad.hpp>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

static void error_callback(int error, const char* description) {

    std::cerr << "Error: " << description << std::endl;

}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(int argc, char *argv[]) {

    // gcc main.c glad.c -o main `pkg-config --cflags --libs glfw3 wayland-client gl` -lrt -lm -ldl && ./main
    
    if (!glfwInit()) {

        std::abort();

    }

    glfwSetErrorCallback(error_callback);

    GLFWwindow* window;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);

    window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
    
    if (!window) {
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);
    glfwSetWindowAttrib(window, GLFW_DECORATED, GLFW_FALSE);
    glfwSetWindowAttrib(window, GLFW_RESIZABLE, GLFW_TRUE);
    glfwSetKeyCallback(window, key_callback);
 
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSwapInterval(1);

    glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // set the color

    while (!glfwWindowShouldClose(window)) {
        
        glClear(GL_COLOR_BUFFER_BIT); // clear the screen with the color set with glClearColor(r, g, b, a)
 
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwDestroyWindow(window);
    glfwTerminate();
    std::exit(EXIT_SUCCESS);

}*/