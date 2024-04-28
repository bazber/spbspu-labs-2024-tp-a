#include <iostream>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <limits>

#include "fig.hpp"

using namespace konovalova;

int main(int argc, char* argv[] ) {
    if (argc != 2) {
        std::cerr << "Not enough arguments" << std::endl;
        std::cout << "Usage: <bin> <filename>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "File not found!" << std::endl;
        return 1;
    }

    std::cout << std::setprecision(1) << std::fixed;

    std::vector<Polygon> data;

    using input_it_t = std::istream_iterator<Polygon>;
    using output_it_t = std::ostream_iterator<Polygon>;
    while (!file.eof())
    {
        std::copy(input_it_t{file}, input_it_t{}, std::back_inserter(data));

        if (!file.eof() && file.fail()) {
            file.clear();
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}