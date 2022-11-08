#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>


int main()
{
	//Selection du fichier d'écriture
	std::string rep;
	std::cout << "Veuillez sélectionner le nom du fichier : ";
	std::cin >> rep;


	//Ouverture du fichier "ImageTest1.pgm" en mode binaire :
	std::ifstream fichier("image.pgm", std::ios_base::binary);
	std::ofstream sortie(rep + ".txt");
	//Ici vous devez décoder l'entête du fichier

	std::string line, hauteur_str, largeur_str;
	int largeur, hauteur;
	std::stringstream ss(line);

	if (!fichier.is_open())
	{
		std::cout << "ERREUR : le fichier n'a pas été ouvert";
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			std::getline(fichier, line);
			switch (i)
			{
			case 0:
			{
				if (line != "P5")
					exit;
				break;
			}
			case 2:
			{
				std::stringstream ss(line);
				std::getline(ss, largeur_str, ' ');
				std::getline(ss, hauteur_str, ' ');
				largeur = stoi(largeur_str);
				hauteur = stoi(hauteur_str);
				break;
			}
			}
		}
	}
	std::cout << "\n\n";
	std::cout << hauteur << " | " << largeur;
	std::cout << "\n\n";


	//Création d'une mémoire de 10 octets :
	std::vector<char> donnees(hauteur * largeur);

	//Lecture de 10 octets depuis le fichier et stockage dans le tableau donnees :
	fichier.read(donnees.data(), hauteur * largeur);
	int cpt = 0;
	for (int a : donnees) 
	{ 
		//std::cout << a << " | ";
		if (a <= 32 && a >= 0) { // 
			sortie << "W";
		}
		if (a <= 64 && a > 32) {
			sortie << "w";
		}
		if (a <= 96 && a > 64) {
			sortie << "l";
		}
		if (a > 96) {
			sortie << "i";
		}
		if (a <= -96) {
			sortie << ":";
		}
		if (a <= -64 && a > -96) { // -96 < a < -64
			sortie << ",";
		}
		if (a <= -32 && a > -64) {
			sortie << ".";
		}
		if (a < 0 && a > -32) {
			sortie << " ";
		}
		cpt++;
		if (cpt == largeur) {
			sortie << std::endl;
			cpt = 0;
		}
	}
}

