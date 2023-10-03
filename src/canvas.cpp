#include <SomeGui/canvas.hpp>

void SomeGui::Canvas::initialize(GLFWwindow* window) {

    if (!window) { std::cout << "Fail to init windows canvas" << std::endl; }

    std::cout << "Canvas init start" << std::endl;

    int windowWidth, windowHeight = 0;
    int frameBufferWidth, frameBufferHeight = 0;
    float density = 0;

    std::cout << "Framebuffer calcs" << std::endl;

    glfwGetWindowSize(window, &windowWidth, &windowHeight);
    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);

    std::cout << "Density init" << std::endl;

    density = (float) (frameBufferWidth * frameBufferWidth + frameBufferHeight * frameBufferHeight)
                / (float) (windowWidth * windowWidth + windowHeight * windowHeight);


    std::cout << "Hardware canvas init" << std::endl;
    skity::GPUContext context = skity::GPUContext(skity::GPUBackendType::kOpenGL, (void*) glfwGetProcAddress);
    
    this->canvas = skity::Canvas::MakeHardwareAccelationCanvas(windowWidth, windowHeight, density, &context);
    //this->canvas.get()->setDefaultTypeface(skity::Typeface::MakeFromFile(SOMEGUI_CANVAS_DEFAULT_FONT));
    std::cout << "Image loading" << std::endl;
    auto data = skity::Data::MakeFromFileName("./test.png");
    
    if (!data->IsEmpty()) {

        auto codec = skity::Codec::MakeFromData(data);
        codec->SetData(data);
        this->pixmapImg = codec->Decode();
        this->paintImg.setShader(skity::Shader::MakeShader(this->pixmapImg));
        this->paintImg.setStyle(skity::Paint::kFill_Style);

        std::cout << "Canvas init finish" << std::endl;

    } else {
        std::cout << "IMAGE NOT LOADED" << std::endl;
    }

}

void SomeGui::Canvas::drawRectangle(std::uint32_t width, std::uint32_t height, double positionX, double positionY) {

    std::cout << "Canvas init" << std::endl;

    /*float corner_radius = 4.f;
    float tw = 0.f, iw = 0.f;
    skity::Color col = skity::ColorSetARGB(255, 0, 0, 255);
    
    skity::Paint paint;
    paint.setAntiAlias(true);
    paint.setStyle(skity::Paint::kFill_Style);
    skity::RRect rrect;
    rrect.setRectXY(skity::Rect::MakeXYWH(positionX + 1.f, positionY + 1.f, width - 2.f, height - 2.f),
                    corner_radius - 1.f, corner_radius - 1.f);
    paint.setColor(col);
    this->canvas.get()->drawRRect(rrect, paint);*/

    this->image_bounds.setXYWH(positionX, positionY, this->pixmapImg->Width() / 5, this->pixmapImg->Height() / 5);
    this->canvas->drawRRect(skity::RRect::MakeRectXY(this->image_bounds, 0, 0), this->paintImg);

    std::cout << "Canvas draw" << std::endl;

}
