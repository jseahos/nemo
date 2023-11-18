#include <cstdint>
#include <fstream>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

using byte_t = uint8_t;
static byte_t accumulator = 0;

static std::optional<std::string> read_commands(const std::string& file);
static void execute_commands(const std::string& commands);

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cerr << "usage: nemo <file>" << std::endl;
        return 1;
    }

    auto commands = read_commands(argv[1]);
    if (!commands.has_value()) {
        std::cerr << "nemo: error: failed to open '" << argv[1] << "'" << std::endl;
        return 1;
    }

    execute_commands(commands.value());

    return 0;
}

std::optional<std::string> read_commands(const std::string& file)
{
    std::optional<std::string> commands = {};

    std::stringstream buffer;
    std::ifstream stream(file);
    if (!stream) {
        return {};
    }
    buffer << stream.rdbuf();
    commands = buffer.str();

    return commands;
}

void execute_commands(const std::string& commands)
{
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
        case 'r':
            accumulator = 0;
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
}
