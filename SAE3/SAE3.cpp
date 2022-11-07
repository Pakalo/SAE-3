#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32 

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>


int main()
{
#ifdef _WIN32
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
#endif // _WIN32

	//Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier("image1.pgm", std::ios_base::binary);
	//Ici vous devez décoder l'entête du fichier
	//...
	//Création d'une mémoire de 10 octets :
	std::vector<char> donnees(200*156);
	//Lecture de 10 octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), 200*156);
	int cpt = 0;
	for (int a : donnees)
	{
		//std::cout << a+127 << " | ";
		if (a+127 <= 31) {
			std::cout << "W";
		}
		if (a+127 <= 62 && a + 127 > 31) {
			std::cout << "w";
		}
		if (a+127 <= 93 && a + 127 > 62) {
			std::cout << "l";
		}
		if (a+127 <= 124 && a + 127 > 93) {
			std::cout << "i";
		}
		if (a+127 <= 155 && a + 127 > 124) {
			std::cout << ":";
		}
		if (a+127 <= 186 && a + 127 > 155) {
			std::cout << ",";
		}
		if (a+127 <= 217 && a + 127 > 186) {
			std::cout << ".";
		}
		if (a+127 > 217) {
			std::cout << " ";
		}
		cpt++;
		if (cpt == 200) {
			std::cout << "\n";
			cpt = 0;
		}
	}
}