#pragma once

#include <vector>
#include <fstream>
#include <iostream>

// Read a text file and put its content in a buffer
bool readfile(const char* name, std::vector<char>& buffer);

void print_error();
void print_error(int i);

int get_address_2D(int, int, int, int);
