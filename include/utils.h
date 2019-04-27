<<<<<<< HEAD
#ifndef _UTILS_H
#define _UTILS_H
=======
#pragma once
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b

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
>>>>>>> f3f788d241a277ff1891a6e84a1e85a7b596693b
