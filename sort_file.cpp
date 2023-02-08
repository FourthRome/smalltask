#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Incorrect number of arguments; 1 expected, got "
                  << argc - 1 << std::endl;
        return -1;
    }

    std::ifstream in_stream;
    in_stream.open(argv[1]);  // ios::in by default
    if (!in_stream.is_open()) {
        std::cerr << "Failed to open file " << argv[1] << std::endl;
        return -1;
    }

    std::string token;
    std::vector<std::string> result;
    while (in_stream >> token) {
        result.push_back(token);
    }
    in_stream.close();

    // Approach A: reuse what works well already
    std::sort(result.begin(), result.end());

    for (auto item : result) {
        std::cout << item << std::endl;
    }
}
