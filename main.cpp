#include <iostream>
#include <cstdlib>
#include "Compilador.cpp"
using namespace std;

void menu_principal();
void mostrar_docs();

int main() {
	Compilador jarara;

	int opc = 1;
	while (opc > 0 && opc < 4) {
		menu_principal();
		
		cout << "> ";
		cin >> opc;

		opc < 4 && system("clear");

		switch(opc) {
			case 1:
				jarara.compile_from_file();
				break;
			case 2:
				
				jarara.live_repl();
				break;
			case 3:
				mostrar_docs();
				break;
			default:
				break;
		}
	} 

	return 1;
}

void menu_principal() {
	system("clear");

	cout << "   ____  ____    _____   ____    _____   ____    \n";
	cout << "  |    ||    \\  |     | |    \\  |     | |    \\   \n";
	cout << " _|    ||     \\ |     \\ |     \\ |     \\ |     \\  \n";
	cout << "|______||__|\\__\\|__|\\__\\|__|\\__\\|__|\\__\\|__|\\__\\ \n";

	cout << "\n";
	cout << "+-----------------------------------------------+\n";
	cout << "| 1- Leer Archivo                               |\n";
	cout << "| 2- REPL                                       |\n";
	cout << "| 3- Docs                                       |\n";
	cout << "| 4- Salir                                      |\n";
	cout << "+-----------------------------------------------+\n";
}

void mostrar_docs() {
	
	cout << "+-----------------------------------------------+\n";
	cout << "|                     DOCS                      |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|  Sintaxis: func<arg1_arg2>                    |\n";
	cout << "|                                               |\n";
	cout << "|  funciones validas:                           |\n";
	cout << "|    sum - res - mul - div - out - inp - cat    |\n";
	cout << "|                                               |\n";
	cout << "|  argumentos validos:                          |\n";
	cout << "|  * numeros ej: 1 2 3 ... 1214748364           |\n";
	cout << "|  * strings ej: ,hola, ,mundo,                 |\n";
	cout << "|  * funciones ej: sum<1_2> div<10_2>           |\n";
	cout << "|                                               |\n";
	cout << "|  ejemplos:                                    |\n";
	cout << "|  * hola mundo => out<cat<,hello,_,world,>>    |\n";
	cout << "|  * multiplicar 9*2 => mul<9_2>                |\n";
	cout << "|  * imprimir resultado => out<mul<9_2>>        |\n";
	cout << "|  * imprimir suma de dos numeros ingresados    |\n";
	cout << "|    por teclado => out<sum<inp<>_inp<>>>       |\n";
	cout << "|                                   ____        |\n";
	cout << "|  ________________________________/ O  \\___/   |\n";
	cout << "| <%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%_____/   \\   |\n";
	cout << "+-----------------------------------------------+\n";
	cout << "|          Creado por: Adrian Rivarola          |\n";
	cout << "+-----------------------------------------------+\n";

	cout<<"Press ENTER to exit";
	cin.ignore().get();
}
