#include "DistanceMatrix.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

void DistanceMatrix::readFromFile(const std::string &fileName)
{
    std::ifstream input(fileName);
    std::string line;
    std::vector<std::vector<std::string>> cells;

    for (std::string line; getline(input, line);)
    {
        std::vector<std::string> results;
        boost::split(results, line, [](char c) { return c == ';'; });
        cells.push_back(results);
    }

    for (size_t i = 3; i < cells.size(); ++i)
    {
        int x = 100 * std::stod(cells[i][matrix::X]);
        int y = 100 * std::stod(cells[i][matrix::Y]);
        nodes.push_back(Node(i - matrix::BEGIN, cells[i][0], x, y, 0));
    }

    matrix = std::vector<std::vector<int>>(cells.size() - matrix::BEGIN);
    for (size_t i = matrix::BEGIN; i < cells.size(); ++i)
    {
        matrix[i - matrix::BEGIN] = std::vector<int>(cells[i].size() - matrix::BEGIN);
        for (size_t j = matrix::BEGIN; j < cells[i].size(); ++j)
        {
            matrix[i - matrix::BEGIN][j - matrix::BEGIN] = std::stoi(cells[i][j]);
        }
    }
}
