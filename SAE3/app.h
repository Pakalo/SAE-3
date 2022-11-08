#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <array>


std::vector<std::vector<unsigned char>> DecodeFile(std::string fileName);
std::array<int, 2> getDim(std::string fileName);
void OutputToTXT(std::string ImpF, std::string OutF, std::string Palette);
void ArgReader(char** Arg, int ArgC);