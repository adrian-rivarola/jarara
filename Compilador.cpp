#include <iostream>
#include <string>
#include "reader/reader.cpp"
#include "parser/parser.cpp"
#include "token/token.cpp"

#ifndef COMPILER
#define COMPILER

class Compilador
{
public:
	void compile_from_file() {
		auto fileName = get_user_input();
		auto lines_read = read_from_file(fileName);

		std::vector<Token*> tokens; 

		for (std::string line : lines_read)
			tokens.push_back(parseExpression(line));

		for (auto token : tokens)
			token->eval_to_str();
	}

	void live_repl() {

		std::cout << "|                 jarara v1.0                   |\n";
		std::cout << "+-----------------------------------------------+\n";

		std::string line;
		Token* token;

		while(true) {
			std::cout << ">>> ";
			std::cin >> line;

			if (line == "end<>") break;

			try {
				token = parseExpression(line);
				std::cout << token->eval_to_str() << "\n";
				delete token;
			} catch (std::exception& e) {
				std::cout << "comando invalido\n";
			}
		}
	}
};

#endif
