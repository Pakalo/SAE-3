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