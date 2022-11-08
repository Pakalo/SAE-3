#include "app.h"
#include "ui.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>


std::vector<std::vector<unsigned char>> DecodeFile(std::string fileName) {
	/*
	Cette fonction permet de décoder et sortir un tableau contenant les données
	*/

	//DECLARATION DES VAR 
	
	int largeur, hauteur;
	
	//LECTURE DU FICHIER 
	std::ifstream fichier(fileName, std::ios_base::binary); //OUVERTURE
	
	//TEST OVERTURE

	if (!fichier.is_open())
	{
		std::cout << "ERREUR : le fichier n'a pas été ouvert";
		exit(1);
	}

	//LECTURE DE LENTETE
	else
	{
		std::string line, largeur_str, hauteur_str; //Déclaration des variables
		std::stringstream ss(line);

		//LECTURE DES 4 PREMIERE LIGNE (ENTETE)
		for (int i = 0; i < 4; i++)
		{
			std::getline(fichier, line);
			switch (i)
			{
				//VERIFFICATION QUE LE FICHIER SOIT COMPATIBLE
			case 0:
			{
				if (line != "P5")
					exit(2);
				break;
			}
				// LECTURE DE LA HAUTEUR / LARGEUR
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
	
	std::vector<std::vector<char>> colonne(hauteur);
	for (int i = 0; i < hauteur; i++)
	{
		std::vector<char> ligne(largeur);
		fichier.read(ligne.data(), largeur);
		colonne[i] = ligne;
	}
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
	return newcolonne;
}


std::array<int, 2> getDim(std::string fileName) {
	/*
	Cette fonction va ouvrir un nouveau fichier et lire l'entéte de maniére à ne pas faire avancer la lecture
	pour le reste du programme ce qui pose probléme
	*/


	//LECTURE DU FICHIER 
	std::ifstream fichier(fileName, std::ios_base::binary); //OUVERTURE FICHIER

	std::string line, largeur_str, hauteur_str; //Déclaration des variables
	std::stringstream ss(line);
	int largeur, hauteur;

	//LECTURE DES 4 PREMIERE LIGNE (ENTETE)
	for (int i = 0; i < 4; i++)
	{
		std::getline(fichier, line);
		switch (i)
		{
			//VERIFFICATION QUE LE FICHIER SOIT COMPATIBLE
		case 0:
		{
			if (line != "P5")
				exit(2);
			break;
		}
		// LECTURE DE LA HAUTEUR / LARGEUR
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
	std::array<int, 2> res = { largeur, hauteur };

	return res;
}


//PERMET D'ECRIRE DANS UN FICHIER TEXTE LA  SORTIE
void OutputToTXT(std::string ImpF, std::string OutF, std::string Palette)
{
	std::ifstream palette_choix(Palette);
	std::ofstream sortie(OutF + ".txt");
	int nbLignes = 0;
	std::string ligne;
	std::vector<std::string> palette;
	int hauteur = getDim(ImpF)[1];
	int largeur = getDim(ImpF)[0];
	std::vector<std::vector<unsigned char>> newcolonne = DecodeFile(ImpF);

	while (std::getline(palette_choix, ligne))
	{
		palette.push_back(ligne);
	}

	int interval, temp = 0;
	std::vector<int> tab_palette;
	interval = 255 / palette.size();

	for (int i = 0; i < palette.size(); i++)
	{
		if (palette.size() % 2 == 0)
		{
			temp += interval;
			tab_palette.push_back(temp);
			temp += 1;
		}
		else
		{
			temp += interval;
			temp -= 1;
			tab_palette.push_back(temp);
			temp += 1;
		}
	}

	std::vector<std::vector<std::string>> vrai_colone(hauteur);
	for (int i = 0; i < hauteur; i++)
	{
		std::vector<std::string> vrai_ligne(largeur);
		for (int j = 0; j < largeur; j++)
		{
			for (int k = 0; tab_palette.size(); k++)
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


	for (int i = 0; i < vrai_colone.size(); i++)
	{
		for (int j = 0; j < vrai_colone[i].size(); j++)
			sortie << vrai_colone[i][j];
		sortie << "\n";
	}
}

//V.4

void ArgReader(char** Arg, int ArgC)
{
	std::string input, output, palette;
	palette = "palette.txt";
	std::string argument1 = Arg[1];
	if (argument1 == "--help")
	{
		Help();
		exit(0);
	}
	for (int i = 0; i < ArgC; ++i)
	{
		std::string argument = Arg[i];
		if (argument == "--input")
		{
			input = Arg[i + 1];
		}
		else
			if (argument == "--output")
			{
				output = Arg[i + 1];
			}
			else
				if (argument == "--palette")
				{
					palette = Arg[i + 1];
				}
	}
	OutputToTXT(input, output, palette);
}