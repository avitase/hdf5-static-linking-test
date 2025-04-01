#include <cstdlib>
#include <iostream>

#include "test.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        return EXIT_FAILURE;
    }

    std::cout << hdf5_static_linking_test::get_size(argv[1], argv[2]) << '\n';

    return EXIT_SUCCESS;
}
