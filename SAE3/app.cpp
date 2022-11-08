#include "app.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

//std::ifstream FichierGet()
//{
//	std::ifstream fichier("image.pgm", std::ios_base::binary);
//	return fichier;
//}

//std::vector<char> FileToVector(std::ifstream &fichier)
//{
//	size_t hauteur = DecodeEntete(fichier)[0];
//	size_t largeur = DecodeEntete(fichier)[1];
//	std::vector<char> donnees(hauteur * largeur);
//	fichier.read(donnees.data(), hauteur * largeur);
//	return donnees;
//}



//void OpeningError(std::ifstream &fichier)
//{
//	if (!fichier.is_open())
//	{
//		std::cout << "ERREUR : le fichier n'a pas été ouvert";
//		exit(1);
//	}
//}

//std::array<int, 2> DecodeEntete(std::ifstream &fichier)
//{
//
//	std::string line, largeur_str, hauteur_str;
//	std::stringstream ss(line);
//	int largeur, hauteur;
//	for (int i = 0; i < 4; i++)
//	{
//		std::getline(fichier, line);
//		switch (i)
//		{
//		case 0:
//		{
//			if (line != "P5")
//				exit(2);
//			break;
//		}
//		case 2:
//		{
//			std::stringstream ss(line);
//			std::getline(ss, largeur_str, ' ');
//			std::getline(ss, hauteur_str, ' ');
//			largeur = stoi(largeur_str);
//			hauteur = stoi(hauteur_str);
//			break;
//		}
//		}
//
//	}
//	std::array<int, 2>res = {hauteur, largeur};
//	return res;
//}

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