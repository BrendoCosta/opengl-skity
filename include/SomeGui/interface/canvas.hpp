#ifndef SOMEGUI_CANVAS_INTERFACE_HPP
#define SOMEGUI_CANVAS_INTERFACE_HPP

#include <memory>
#include <cstdint>
//#include <skity/skity.hpp>
//#include <skity/gpu/gpu_context.hpp>

//#define EXAMPLE_DEFAULT_FONT "/home/neofox/teste/opengl/skity/RobotoMonoNerdFontComplete.ttf"

namespace SomeGui {

    namespace Interface {

        class Canvas {

            public:

            virtual ~Canvas() = default;

            //virtual void drawRectangle(std::uint32_t width, std::uint32_t height, std::uint32_t positionX, std::uint32_t positionY) = 0;
            //virtual void drawCircle(std::uint32_t diameter, std::uint32_t positionX, std::uint32_t positionY) = 0;

        };

    }

}

#endif  // SOMEGUI_CANVAS_INTERFACE_HPP
