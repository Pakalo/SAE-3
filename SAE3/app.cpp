#include "app.h"
#include "ui.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>


std::vector<char> DecodeFile(std::string fileName) {
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

	std::vector<char> donnees(hauteur * largeur); //Création d'un tableau de la taille du nbr total de pixel de l'image
	fichier.read(donnees.data(), hauteur * largeur); //Ajout des valeurs de l'image dans le tableau

	return donnees;
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
void OutputToTXT(std::string ImpF,std::string OutF)
{
	std::ofstream sortie(OutF + ".txt"); //Ouverture du fichier de sortie
	std::vector<char> donnees = DecodeFile(ImpF); 
	int cpt = 0;
	int largeur = getDim(ImpF)[0];
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
	OutputToTXT(input, output);
}