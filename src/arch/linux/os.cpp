#include <SomeGui/os.hpp>

std::uint32_t SomeGui::OS::getProcessId(void) {

    pid_t pid = getpid();

    return (std::uint32_t) pid;

}