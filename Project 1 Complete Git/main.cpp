
//***************************
//
// Class: CS-315
//
// Project 1
//
// Date: September 27th, 2018
//
//***************************

#include <iostream>
#include <fstream>
#include "JSONToken.hpp"
#include "JSONTokenizer.hpp"
#include "JSONParser.hpp"
#include "EntityInstance.hpp"
#include "Pair.hpp"
#include "Entity.hpp"
#include "CommandTokenizer.hpp"
#include "CommandToken.hpp"
#include "CommandParser.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    
    ifstream inputStream;
    
    inputStream.open(argv[1], std::ios::in);    // open for reading
    
    if( ! inputStream.is_open())
    {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    
    CommandTokenizer commandTokenizer(inputStream);
    CommandParser  commandParser(commandTokenizer);

    commandParser.parser();

    
    return 0;
}
