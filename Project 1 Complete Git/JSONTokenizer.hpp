
#ifndef JSONTokenizer_hpp
#define JSONTokenizer_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "JSONToken.hpp"

using namespace std;

class JSONTokenizer
{
  
public:
    JSONTokenizer(ifstream &t) : inStream {t} {}
    JSONTokenizer(string);
    JSONToken getToken();
    
    
    bool charOfInterest(char );
    
    string assignAttributeString();
    int assignAttributeInt(char);
    
    string assignAttributeNull(char);
    
    
    
private:
    
    ifstream &inStream;
    
    
    
};


#endif /* JSONTokenizer_hpp */
