#include <iostream>
#include <string>
#include <unordered_map>
#include "reader/reader.cpp"

#ifndef COMPILER
#define COMPILER

class Compiler
{
private:
	unordered_map<std::string, int> n_memory;
public:
	Compiler() {
		
	}
}

#endif
