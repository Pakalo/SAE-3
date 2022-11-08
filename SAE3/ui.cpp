#include "ui.h"
#include "app.h"


void AffichageMenu() 
{
	std::string ImpF;
	std::cout << "Veuillez sélectionner le nom du fichier entrée: ";
	std::cin >> ImpF;

	std::string OutF;
	std::cout << "Veuillez sélectionner le nom du fichier sortie: ";
	std::cin >> OutF;

	OutputToTXT(ImpF, OutF);
}

void Help() 
{
	std::cout << "Options : \n\n--input fichier Spécifie le fichier image à convertir\nSi ce paramètre n'est pas spécifié, le fichier est demandé via la console.\n\n--output fichier Spécifie le nom du fichier texte qui contiendra l'Ascii Art. \nSi ce paramètre n'est pas spécifié, l'Ascii Art est sortie dans la console.\n\n--palette fichier Spécifie un fichier texte contenant la palette de couleur Ascii. \nChaque ligne du fichier contient un charactère en UTF - 8, du plus sombre au plus clair. \nSi ce paramètre n'est pas spécifié, la palette par défaut est \"W\", \"w\", \"l\", \"i\", \":\", \",\", \".\", \" \" \n\n--help Affiche cette aide.";
}