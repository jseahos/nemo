#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using byte_t = uint8_t;
static byte_t accumulator = 0;

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "usage: nemo <file>" << std::endl;
        return -1;
    }

    std::string commands;
    {
        std::stringstream buffer;
        std::ifstream file(argv[1]);
        if (!file) {
            std::cerr << "nemo: error: failed to open '" << argv[1] << "'" << std::endl;
            return -1;
        }
        buffer << file.rdbuf();
        commands = buffer.str();
    }

    for (char command : commands) {
        switch (command) {
        case 'i':
            accumulator++;
            break;
        case 'd':
            accumulator = (accumulator < 1 ? 0 : accumulator - 1);
            break;
        case 's':
            accumulator = (accumulator > 15 ? 0 : accumulator * accumulator);
            break;
        case 'o':
            std::cout << accumulator;
            break;
        default:
            break;
        }
    }

    /* Prevent zsh from appending a special newline to the output.
       https://unix.stackexchange.com/questions/167582/why-zsh-ends-a-line-with-a-highlighted-percent-symbol */
    std::cout << std::endl;

    return 0;
}
