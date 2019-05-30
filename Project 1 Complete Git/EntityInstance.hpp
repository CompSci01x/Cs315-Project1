
#ifndef EntityInstance_hpp
#define EntityInstance_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Pair.hpp"
#include "CommandTokenizer.hpp"

using namespace std;


class EntityInstance
{
    
public:
    void addAttribute(Pair &);
    int numAttributes();
    vector <string> attributeNames();
    void print();   // prints this object
    
    void selectTuplePrint(vector <CommandToken> & );
  
    
    
private:
    vector<Pair> entityAttributes;
    
};


#endif /* EntityInstance_hpp */
