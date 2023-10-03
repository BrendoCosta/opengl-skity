#ifndef SOMEGUI_CANVAS_HPP
#define SOMEGUI_CANVAS_HPP

#include <memory>
#include <cstdint>
#include <skity/skity.hpp>
#include <skity/gpu/gpu_context.hpp>
#include <skity/codec/codec.hpp>
#include <SomeGui/glfw.hpp>
#include <iostream>

#define SOMEGUI_CANVAS_DEFAULT_FONT "/home/neofox/teste/opengl/skity/RobotoMonoNerdFontComplete.ttf"

namespace SomeGui {

    class Canvas {

        private:

        public:

        std::unique_ptr<skity::Canvas> canvas = {};
        std::shared_ptr<skity::Pixmap> pixmapImg = {};
        skity::Paint paintImg = {};
        skity::Rect image_bounds = {};

        void initialize(GLFWwindow* window);
        void drawRectangle(std::uint32_t width, std::uint32_t height, double positionX, double positionY);
        //virtual void drawCircle(std::uint32_t diameter, std::uint32_t positionX, std::uint32_t positionY) = 0;

    };

}

#endif  // SOMEGUI_CANVAS_HPP
