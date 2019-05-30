

#ifndef CommandTokenizer_hpp
#define CommandTokenizer_hpp

#include <stdio.h>
#include <fstream>
#include "CommandToken.hpp"
#include <sstream>

using namespace std;


class CommandTokenizer
{
  
public:
    
    CommandTokenizer(ifstream &ct) : inStream {ct} {}
    
    CommandToken getToken();
    
    bool charOfInterest(char);
    
    string commandKeyWord(char c);
    string quotedString(char c);
    int createDigit(char c);
    
    
private:
    ifstream &inStream;
    
    
};

#endif /* CommandTokenizer_hpp */
