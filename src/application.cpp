#include <SomeGui/application.hpp>

static void error_callback(int error, const char* description) {

    std::cout << "GLFW ERROR CALLBACK: " << description << std::endl;

}

void SomeGui::Application::initialize(void) {

    std::cout << "GLFW set error callback" << std::endl;

    glfwSetErrorCallback(error_callback);
    
    std::cout << "GLFW init" << std::endl;

    if (!glfwInit()) {

        std::cout << "GLFW abort" << std::endl;
        std::abort();

    }

    std::cout << "GLFW window hints" << std::endl;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);

}

SomeGui::Application::Application(std::string title, std::uint32_t width, std::uint32_t height) {

    Application(title, width, height, 100, 100);

}

SomeGui::Application::Application(std::string title, std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY) {

    std::cout << "App initialize" << std::endl;
    this->initialize();
    std::cout << "Push first window" << std::endl;
    this->applicationWindowVec.push_back(std::unique_ptr<SomeGui::ApplicationWindow>(new SomeGui::ApplicationWindow(title, width, height, positionX, positionY, nullptr)));
    std::cout << "Push second window" << std::endl;
    this->applicationWindowVec.push_back(std::unique_ptr<SomeGui::ApplicationWindow>(new SomeGui::ApplicationWindow("Passaro", width, height, positionX+512, positionY+512, nullptr)));
    //this->applicationWindowVec.push_back(std::unique_ptr<SomeGui::ApplicationWindow>(new SomeGui::ApplicationWindow("Passaro 2", width, height, positionX+512, positionY+512, NULL)));
    std::cout << "App run" << std::endl;
    this->run();
    std::cout << "App end" << std::endl;
    this->end();
    //this->applicationWindow = std::unique_ptr<SomeGui::ApplicationWindow>(new SomeGui::ApplicationWindow(title, width, height, positionX, positionY));

}

void SomeGui::Application::run(void) {

    std::cout << "Thread vector init" << std::endl;

    std::vector<std::thread> threadVec;

    //glfwMakeContextCurrent(this->applicationWindowVec.front().get()->getWindowObject());
    //gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    //glfwSwapInterval(1);

    for (auto& ptr: this->applicationWindowVec) {
    
        std::function<void()> func = [&]() {

            //int a = 0;
            //int b = 0;

            if (ptr.get()) {

                std::cout << "Window getted" << std::endl;

                glfwMakeContextCurrent(NULL);
                glfwMakeContextCurrent(ptr.get()->getWindowObject());
                if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
                    std::cout << "GLAD LOADING ERROR" << std::endl;
                }
                glfwSwapInterval(1);

                std::cout << "Setting gl clear color" << std::endl;

                glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
                glEnable(GL_BLEND);
                glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
                glEnable(GL_STENCIL_TEST);

                std::cout << "Init canvas inside thread" << std::endl;

                ptr.get()->canvas.initialize(ptr.get()->getWindowObject());

                while (!glfwWindowShouldClose(ptr.get()->getWindowObject())) {
                    
                    /*a = (a + 1) % 1000;
                    if (a == 999) {
                        b = (b + 1) % 1000;
                    }
                    std::cout << a << " - " << b << std::endl;*/

                    glClear(GL_COLOR_BUFFER_BIT);

                    std::cout << "\033c" << std::endl;
                    double mx, my;
                    glfwGetCursorPos(ptr.get()->getWindowObject(), &mx, &my);
                    std::cout << mx << " - " << my << std::endl;

                    ptr.get()->canvas.drawRectangle(640, 480, 0, 0);
                    ptr.get()->canvas.canvas.get()->flush();
                    //ptr.get()->canvas.canvas.reset();
                    std::cout << glGetError() << std::endl;

                    glfwSwapBuffers(ptr.get()->getWindowObject());
                    std::cout << glGetError() << std::endl;
                    glfwPollEvents();
                    //glfwMakeContextCurrent(NULL);

                }

                std::cout << "Finish window loop" << std::endl;

            }

        };

        std::cout << "Push thread" << std::endl;

        threadVec.push_back(std::thread(func));

    }

    std::cout << "Run threads" << std::endl;

    for (std::thread& thr: threadVec) {
        // If thread Object is Joinable then Join that thread.
        if (thr.joinable())
            thr.join();
    }

    std::cout << "Endding run" << std::endl;

    return;

}

SomeGui::Application::~Application() {

    //this->end();

}

void SomeGui::Application::end(void) {

    //delete this->applicationWindow;
    glfwTerminate();
    std::exit(EXIT_SUCCESS);

}