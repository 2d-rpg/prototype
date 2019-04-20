#ifndef _UTILS_H
#define _UTILS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include "utils.h"

// Read a text file and put its content in a buffer
bool
readfile(const char * name, std::vector<char> &buffer)
{
    std::ifstream fs { name };

    if (!fs) {
        std::cerr << "Failed to open file: '" << name << "'" << std::endl;
        return false;
    }

    // Get file size
    fs.seekg(0L, std::ios::end);
    int size = fs.tellg();

    // Resize the buffer to the appropriate size
    buffer.resize(size + 1);

    // Read the file from the beggining
    fs.seekg(0L, std::ios::beg);
    fs.read(buffer.data(), size);
    buffer[size] = '\0';

    if (!fs) {
        std::cerr << "Failed while reading file: '" << name << "'" << std::endl;
        return false;
    }

    fs.close();
    return true;
}

void
print_error()
{
    static int count = 0;
    std::cout << "print error " << ++count << ": " << glGetError() << std::endl;
}

#endif // ifndef _UTILS_H
