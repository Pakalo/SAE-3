#include "ui.h"
#include "app.h"


void AffichageMenu() 
{
	std::string ImpF;
	std::cout << "Veuillez s�lectionner le nom du fichier entr�e: ";
	std::cin >> ImpF;

	std::string OutF;
	std::cout << "Veuillez s�lectionner le nom du fichier sortie: ";
	std::cin >> OutF;

	OutputToTXT(ImpF, OutF);
}

void Help() 
{
	std::cout << "Options : \n\n--input fichier Sp�cifie le fichier image � convertir\nSi ce param�tre n'est pas sp�cifi�, le fichier est demand� via la console.\n\n--output fichier Sp�cifie le nom du fichier texte qui contiendra l'Ascii Art. \nSi ce param�tre n'est pas sp�cifi�, l'Ascii Art est sortie dans la console.\n\n--palette fichier Sp�cifie un fichier texte contenant la palette de couleur Ascii. \nChaque ligne du fichier contient un charact�re en UTF - 8, du plus sombre au plus clair. \nSi ce param�tre n'est pas sp�cifi�, la palette par d�faut est \"W\", \"w\", \"l\", \"i\", \":\", \",\", \".\", \" \" \n\n--help Affiche cette aide.";
}