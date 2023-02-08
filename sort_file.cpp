#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments; 1 expected, got "
                  << argc - 1 << std::endl;
        return -1;
    }

    auto filename = argv[1];

    std::ifstream in_stream;
    in_stream.open(filename);  // ios::in by default
    if (!in_stream.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return -1;
    }

    std::string token;
    in_stream >> token;
    std::cout << token << std::endl;
    in_stream.close();
}
