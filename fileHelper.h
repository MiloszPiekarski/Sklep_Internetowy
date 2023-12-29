//
// Created by HARDPC on 29.12.2023.
//

#ifndef PROJEKT_FILEHELPER_H
#define PROJEKT_FILEHELPER_H
using namespace std;

#include <vector>
#include <sstream>
#include "fstream"

fstream OpenFile(string path);
vector<string> split(const string &s, char delim);

#endif //PROJEKT_FILEHELPER_H
