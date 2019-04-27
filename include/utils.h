<<<<<<< HEAD
#ifndef _UTILS_H
#define _UTILS_H
=======
#pragma once
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7

#include <vector>
#include <fstream>
#include <iostream>

// Read a text file and put its content in a buffer
<<<<<<< HEAD
bool readfile(const char *name, std::vector<char> &buffer);

void print_error();

#endif
=======
bool readfile(const char* name, std::vector<char>& buffer);

void print_error();
void print_error(int i);

int get_address_2D(int, int, int, int);
>>>>>>> e0eaba8d8a822fe8dfeb53680028476d5b43b4a7
