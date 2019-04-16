#ifndef _UTILS_H
#define _UTILS_H

#include <vector>
#include <fstream>
#include <iostream>

// Read a text file and put its content in a buffer
bool readfile(const char *name, std::vector<char> &buffer);

#endif
