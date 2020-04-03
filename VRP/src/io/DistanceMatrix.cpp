#include "DistanceMatrix.h"
#include <iostream>
#include <fstream>

void DistanceMatrix::readFromFile(const std::string &fileName)
{
    std::ifstream fin;
    std::string line;
    fin.open(fileName);
    while (!fin.eof())
    {
        fin >> line;
        std::cout << line << " ";
    }
}
