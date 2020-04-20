#include <iostream>
#include <vector>
#include "Compilador.cpp"
using namespace std;

int main() {
	Compilador jarara;
	int opc;

	cout << "   ____  ____    _____   ____    _____   ____    \n";
	cout << "  |    ||    \\  |     | |    \\  |     | |    \\   \n";
	cout << " _|    ||     \\ |     \\ |     \\ |     \\ |     \\  \n";
	cout << "|______||__|\\__\\|__|\\__\\|__|\\__\\|__|\\__\\|__|\\__\\ \n";

	cout << "\n";

	cout << "+-----------------------------------------------+\n";
	cout << "| 1- Leer Archivo                               |\n";
	cout << "| 2- Interprete en consola                      |\n";
	cout << "| 3- Salir                                      |\n";
	cout << "+-----------------------------------------------+\n";

	cout << "> ";
	cin >> opc;
	cout << "+-----------------------------------------------+\n";

	if (opc == 1) 
		jarara.compile_from_file();
	else if (opc == 2)
		jarara.live_repl();

	return 1;
}
