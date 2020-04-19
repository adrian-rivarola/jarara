#include <iostream>
#include <vector>
#include "filereader/filereader.cpp"
#include "parser/parser.cpp"
#include "token/token.cpp"

int main() {
	auto filename = get_user_input();
	auto file_lines = read_from_file(filename);

	std::vector<Token*> tokens;
	
	for (std::string line : file_lines)
		tokens.push_back(parseExpression(line));

	for (Token* token : tokens) 
		token->eval_to_str();
	
	return 1;
}
