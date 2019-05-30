

#ifndef CommandParser_hpp
#define CommandParser_hpp

#include <stdio.h>
#include "CommandTokenizer.hpp"
#include "Entity.hpp"

class CommandParser
{
  
public:
    CommandParser(CommandTokenizer &ct): tokenizer {ct} {}
    
    void parser();
    void printFunction(Entity);
    void printSelectTuples(Entity);
    
    Entity executeLet(CommandToken&);
    
    
    
private:
    CommandTokenizer &tokenizer;
    vector<CommandToken> tokenHolder;
    
    
    
};

#endif /* CommandParser_hpp */
