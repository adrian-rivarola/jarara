#include <iostream>
#include <string>
#include <vector>

#ifndef TOKENS
#define TOKENS

class Token
{
public:
	Token() {}
	virtual ~Token() {}
	virtual int eval_to_int() = 0;
	virtual std::string eval_to_str() = 0;
};

class Numero: public Token
{
private:
	int value;
public:
	Numero(int n): value(n) {}

	int eval_to_int() override {
		return value;
	}
	std::string eval_to_str() override {
		return std::to_string(value);
	}
};

class Texto: public Token
{
private:
	std::string value;
public:
	Texto(std::string str): value(str) {}

	virtual int eval_to_int() override {
		return 0;
	}
	virtual std::string eval_to_str() override {
		return value;
	}
};

class Imprimir : public Token
{
private:
	Token* token;
public:
	Imprimir(Token* t): token(t) {}

	std::string eval_to_str() override {
		std::cout << token->eval_to_str() << std::endl;
		return "";
	}

	int eval_to_int() override {
		return 0;
	}
};

class UserInput : public Token
{
public:
	std::string eval_to_str() override {
		std::string input;
		std::cout << "> ";
		std::cin >> input;
		return input;
	}

	int eval_to_int() override {
		int input;
		std::cout << "> ";
		std::cin >> input;
		return input;
	}
};

class Operacion : public Token
{
protected:
	Token* elem1;
	Token* elem2;
	std::string name;
public:
	Operacion(Token* el1, Token* el2): elem1(el1), elem2(el2) {}
	Operacion(std::string var_name, Token* elem): name(var_name), elem1(elem) {}

	virtual int eval_to_int() {
		return 0;
	}

	virtual std::string eval_to_str() {
		return std::to_string(this->eval_to_int());
	}
};

class Concat : public Operacion
{
public:
	Concat(Token* el1, Token* el2): Operacion(el1, el2) {}

	std::string eval_to_str() override {
		return elem1->eval_to_str() + " " + elem2->eval_to_str();
	}
};

class Suma : public Operacion
{
public:
	Suma(Token* el1, Token* el2): Operacion(el1, el2) {}
	
	int eval_to_int() override {
		return elem1->eval_to_int() + elem2->eval_to_int();
	}
};

class Resta : public Operacion
{
public:
	Resta(Token* el1, Token* el2): Operacion(el1, el2) {}
	
	int eval_to_int() override {
		return elem1->eval_to_int() - elem2->eval_to_int();
	}

};

class Multiplicacion : public Operacion
{
public:
	Multiplicacion(Token* el1, Token* el2): Operacion(el1, el2) {}
	
	int eval_to_int() override {
		return elem1->eval_to_int() * elem2->eval_to_int();
	}
};

class Division : public Operacion
{
public:
	Division(Token* el1, Token* el2): Operacion(el1, el2) {}
	
	int eval_to_int() override {
		if (elem2->eval_to_int() == 0) return 0;
		return elem1->eval_to_int() / elem2->eval_to_int();
	}
};

#endif
