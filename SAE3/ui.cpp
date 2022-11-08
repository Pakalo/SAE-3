#include "ui.h"
#include "app.h"

void AffichageASCII(std::string fileName)
{
	std::vector<char> donnees = DecodeFile(fileName);
	int largeur = getDim(fileName)[0];
	int cpt = 0;

	for (int a : donnees)
	{
		//std::cout << a << " | ";
		if (a <= -96) {
			std::cout << ":";
		}
		if (a <= -64 && a > -96) { // -96 < a < -64
			std::cout << ",";
		}
		if (a <= -32 && a > -64) {
			std::cout << ".";
		}
		if (a < 0 && a > -32) {
			std::cout << " ";
		}
		if (a <= 32 && a >= 0) { // 
			std::cout << "W";
		}
		if (a <= 64 && a > 32) {
			std::cout << "w";
		}
		if (a <= 96 && a > 64) {
			std::cout << "l";
		}
		if (a > 96) {
			std::cout << "i";
		}
		cpt++;
		if (cpt == largeur) {
			std::cout << "\n";
			cpt = 0;
		}
	}
}