#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <array>

//std::array<int, 2> DecodeEntete(std::ifstream &fichier);
//std::ifstream FichierGet();
//std::vector<char> FileToVector(std::ifstream &fichier);
//void OpeningError(std::ifstream &fichier);

std::vector<char> DecodeFile(std::string fileName);
std::array<int, 2> getDim(std::string fileName);
void OutputToTXT(std::string ImpF, std::string OutF);