#ifndef SOMEGUI_OS_HPP
#define SOMEGUI_OS_HPP

#include <cstdint>
#include <config.hpp>
#ifdef _SOMEGUI_TARGET_ARCH_LINUX
    #include <sys/types.h>
    #include <unistd.h>
#endif 

namespace SomeGui {

    namespace OS {

        std::uint32_t getProcessId(void);

    }

}

#endif  // SOMEGUI_OS_HPP