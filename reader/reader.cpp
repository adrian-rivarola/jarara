#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef READER
#define READER

class Reader
{
public:
	bool is_valid(std::string& fileName) {
		int n = fileName.length();
		if (n < 4) return false;
		if (filename.substr(n-4) != '.jrr') return false;
		if (filename[n-4] != '.') return false;
		return true;
	}

	void clean_input(std::string& fileName) {
		if (fileName[0] == '\'' && fileName[fileName.length() - 1] == '\'')
			fileName = fileName.substr(1, fileName.length() - 2);
	}

	static std::vector<std::string> read_from_file(std::string fileName) {
		
		std::ifstream file (fileName);

		if (!file.is_open()) {
			std::cout << "No se puede abrir " << fileName << std::endl;
			return {};
		}

		std::vector<std::string> file_lines;
		std::string line;
		
		while (std::getline(file, line)) {
			if (!file.good()) break;
			file_lines.push_back(line);
		}
		file.close();
		return file_lines;
	}

	static std::string get_user_input() {
		std::string fileName;
		bool valid_input = true;

		do {
			if (!valid_input) {
				std::cout << "Nombre de archivo no valido" << std::endl;
			}
			std::cout << "Ingresar direccion del archivo:\n> ";
			std::cin >> fileName;

			clean_input(fileName);
			valid_input = is_valid(fileName);

		} while(!valid_input); 
		
		return fileName;
	}
};

#endif
