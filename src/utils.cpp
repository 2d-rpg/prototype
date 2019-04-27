<<<<<<< HEAD
#ifndef _UTILS_H
#define _UTILS_H

=======
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
<<<<<<< HEAD
#include "utils.h"

// Read a text file and put its content in a buffer
bool
readfile(const char * name, std::vector<char> &buffer)
{
    std::ifstream fs { name };
=======
#include <utils.h>
#include <cassert>

// Read a text file and put its content in a buffer
bool readfile(const char* name, std::vector<char>& buffer) {
    std::ifstream fs{name};
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7

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

<<<<<<< HEAD
void
print_error()
{
=======
void print_error() {
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7
    static int count = 0;
    std::cout << "print error " << ++count << ": " << glGetError() << std::endl;
}

<<<<<<< HEAD
#endif // ifndef _UTILS_H
=======
void print_error(int i) {
    std::cout << "print error custom " << i << ": " << glGetError() << std::endl;
}

int get_address_2D(int width, int height, int x, int y) {
    assert(width * y + x <= width * height);
    return width * y + x;
}
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7
