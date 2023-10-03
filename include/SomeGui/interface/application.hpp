#ifndef SOMEGUI_APPLICATION_INTERFACE_HPP
#define SOMEGUI_APPLICATION_INTERFACE_HPP

#include <cstdint>
#include <memory>

namespace SomeGui {

    namespace Interface {

        class Application {

            public:
            
            virtual ~Application() = default;

            virtual void end(void) = 0;

        };

    }

}

#endif  // SOMEGUI_APPLICATION_INTERFACE_HPP
