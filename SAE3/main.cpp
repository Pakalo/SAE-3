#include "app.h"
#include "ui.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

int main()
{
	std::cout << "Entrez le nom du fichier d'entrée";
	std::string fileName;
	std::cin >> fileName;
	AffichageASCII(fileName);
}
