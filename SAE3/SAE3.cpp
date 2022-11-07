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
	std::vector<char> donnees(20*20);
	//Lecture de 10 octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), 20*20);
	int cpt = 0;
	for (int a : donnees)
	{
		std::cout << a << " | ";
		//if (a <= -96) {
		//	std::cout << "Z";
		//}
		//if (a <= -64 && a > -96) { // -96 < a < -64
		//	std::cout << "w";
		//}
		//if (a <= -32 && a > -64) {
		//	std::cout << "l";
		//}
		//if (a <= 0 && a > -32) {
		//	std::cout << "i";
		//}
		//if (a <= 32 && a > 0) { // 
		//	std::cout << ":";
		//}
		//if (a <= 64 && a > 32) {
		//	std::cout << ",";
		//}
		//if (a <= 96 && a> 64) {
		//	std::cout << ".";
		//}
		//if (a > 96) {
		//	std::cout << " ";
		//}
		cpt++;
		if (cpt == 20) {
			std::cout << "\n";
			cpt = 0;
		}
	}
}