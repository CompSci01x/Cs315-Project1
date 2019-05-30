

#ifndef JSONParser_hpp
#define JSONParser_hpp

#include <stdio.h>
#include "JSONTokenizer.hpp"
#include "Pair.hpp"
#include "EntityInstance.hpp"

class JSONParser
{
    
public:
    
    JSONParser(JSONTokenizer &t);
    
    Pair parseAPair();
    EntityInstance parseJSONObject();

    
private:
    JSONTokenizer &tokenizer;
    
    
};




#endif /* JSONParser_hpp */
