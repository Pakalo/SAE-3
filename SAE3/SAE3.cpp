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

	//Selection du fichier d'écriture
	std::string rep;
	std::cout << "Veuillez sélectionner le nom du fichier : ";
	//std::cin >> rep;
	rep = "test";

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

	//Affichage de la hauteur et de la largeur
	std::cout << "\n\n";
	std::cout << hauteur << " | " << largeur;
	std::cout << "\n\n";


	//Création d'un tableau de tableaux qui va contenir toute les valeurs 
	std::vector<std::vector<char>> colonne(hauteur);
	for (int i = 0; i < hauteur; i++)
	{
		std::vector<char> ligne(largeur);
		fichier.read(ligne.data(), largeur);
		colonne[i] = ligne;
	}

	//Le tableau précédent contenant des valeurs négatives, nous le convertissons afin qu'il ne contienne que des valeurs comprises entre 0 et 255
	std::vector<std::vector<unsigned char>> newcolonne(hauteur);
	for (int j = 0; j < hauteur; j++)
	{
		std::vector<unsigned char> newligne(largeur);
		for (int k = 0; k < largeur; k++)
		{
			int caractere = int(colonne[j][k]);
			caractere = (caractere + 256) % 256;
			newligne[k] = unsigned char(caractere);
		}
		newcolonne[j] = newligne;
	}
	

	// Cargement de la palette
	std::string choix;
	std::cout << "Veuillez coisir une palette : ";
	std::cin >> choix;
	

	// Ouverture du fichier de la palette selectionné
	std::ifstream palette_choix(choix);
	int nbLignes = 0;
	std::string ligne;
	std::vector<std::string> palette;
	

	// Récupération des caractères dans une liste
	while (std::getline(palette_choix, ligne))
	{
		palette.push_back(ligne);
	}
	
	/*for (auto i : palette)
		std::cout << i;*/


	// Calcul de l'intervalle
	int interval, temp = 0;
	std::vector<int> tab_palette;
	interval = 255 / palette.size();

	for (int i = 0; i < palette.size(); i++)
	{
		if (palette.size() % 2 == 0)
		{
			temp += interval;
			tab_palette.push_back(temp);
			temp +=1;
		}
		else
		{
			temp += interval;
			temp -= 1;
			tab_palette.push_back(temp);
			temp += 1;
		}
	}

	

	// Affichage en fonction de la palette
	std::vector<std::vector<std::string>> vrai_colone(hauteur);
	for (int i=0; i<hauteur; i++)
	{
		std::vector<std::string> vrai_ligne(largeur);
		for (int j=0; j<largeur; j++)
		{
			for (int k=0; tab_palette.size(); k++)
			{
				if (int(newcolonne[i][j]) <= tab_palette[k])
				{
					vrai_ligne[j] = palette[k];
					break;
				}
			}
		}
		vrai_colone[i] = vrai_ligne;
	}
	

	for (int i = 0; i<vrai_colone.size(); i++)
	{
		for (int j = 0; j < vrai_colone[i].size(); j++)
			sortie << vrai_colone[i][j];
		sortie << "\n";
	}
	



}