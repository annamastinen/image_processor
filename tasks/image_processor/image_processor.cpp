#include <stdexcept>
#include <queue>
#include <string>
#include <vector>
#include <iostream>

#include "Image.h"
#include "Filter.cpp"
#include "map"
#include "BMP.cpp"
#include "RGB.cpp"
#include "Image.cpp"

int main(int argc, char* argv[]) {
    std::map<std::string, Filter*> filters;
    std::map<std::string, int> filters_count;

    if (argc < 2) {
        throw std::runtime_error("Wrong input.");
    }

    filters["-neg"] = new Negative();
    filters["-gs"] = new Grayscale();

    std::queue<char*> args;
    for (int i = 1; i < argc; ++i) {
        args.push(argv[i]);
    }

    char* inp = args.front();
    args.pop();
    char* output = args.front();
    args.pop();

    Image image;
    image.Read(inp);

    while (!args.empty()) {
        std::string name_filter = args.front();
        args.pop();
        if (filters.find(name_filter) == filters.end()) {
            break;
        }
        std::vector<std::string> arguments;
        for (int i = 0; i < filters_count.find(name_filter)->second; i++) {
            if (args.empty()) {
                break;
            }
            arguments.push_back(args.front());
            args.pop();
        }

        filters.find(name_filter)->second->Change(image, arguments);
    }

    Save(output, image);
    for (auto& item : filters) {
        delete item.second;
    }
    return 0;
}