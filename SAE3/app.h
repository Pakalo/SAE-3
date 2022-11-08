#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <array>


std::vector<char> DecodeFile(std::string fileName);
std::array<int, 2> getDim(std::string fileName);
void OutputToTXT(std::string ImpF, std::string OutF);
void ArgReader(char** Arg, int ArgC);