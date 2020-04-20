#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "../token/token.cpp"

#ifndef PARSER
#define PARSER

std::regex numeros("^\\d+$");

Token* parseExpression(std::string expression) 
{
	int n = expression.length();

	if (n == 0) return new Texto("");

	if (expression[0] == ',' && expression[n-1] == ',')
		return new Texto(expression.substr(1, n-2));

	if (std::regex_match(expression, numeros)) {
		return new Numero(std::stoi(expression));
	}
	
	std::string func = expression.substr(0, 3);
	if (func == "inp") return new UserInput();

	std::string args = expression.substr(4, n-5);

	if (func == "out") return new Imprimir(parseExpression(args));

	int func_calls = 0, idx_mid = 0;

	for (int i = 0; i < args.length(); i++) {
		switch (args[i]) {
			case '<': func_calls++; break;
			case '>': func_calls--; break;
			case '_':
				  if (func_calls == 0) idx_mid = i;
				  break;
			default: break;
		}
		if (idx_mid != 0) break;
	}

	if (idx_mid == 0) return new Texto("");

	Token* token;
	Token* el1 = parseExpression(args.substr(0, idx_mid));
	Token* el2 = parseExpression(args.substr(idx_mid + 1));
	
	if (func == "sum") return new Suma(el1, el2);
	if (func == "res") return new Resta(el1, el2);
	if (func == "mul") return new Multiplicacion(el1, el2);
	if (func == "div") return new Division(el1, el2);
	if (func == "cat") return new Concat(el1, el2);

	return new Texto("");
}

#endif
