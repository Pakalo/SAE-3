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