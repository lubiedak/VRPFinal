#include "DistanceMatrix.h"
#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>

void DistanceMatrix::readFromFile(const std::string &fileName)
{
    std::ifstream input(fileName);
    std::string line;
    std::vector<std::vector<std::string>> cells;

    for( std::string line; getline( input, line ); )
    {
        std::vector<std::string> results;
        boost::split(results, line, [](char c){return c == ';';});
        cells.push_back(results);
        //std::cout<<cells.size() << " "<<results.size()<<std::endl;
    }
    for(int i=3;i<cells.size();++i){
        nodes.push_back(Node(i-3,cells[i][0],std::stoi(cells[i][1],cells[i][2],0))
    }
}
