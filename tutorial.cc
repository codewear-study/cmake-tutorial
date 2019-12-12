#include <iostream>
#include "./TutorialConfig.hh"

auto main(int argc, char **argv) -> int
{
    if (argc < 2)
    {
        std::cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "."
                  << Tutorial_VERSION_MINOR << "." << Tutorial_VERSION_PATCH << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;

        return 1;
    }

    const double inputValue = std::atof(argv[1]);
    std::cout << inputValue << std::endl;

    return 0;
}
