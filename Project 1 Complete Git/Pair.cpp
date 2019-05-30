
#include "Pair.hpp"


//**************************************************************
//
// Constructor for string attributes
//
//**************************************************************
Pair::Pair(string attributeName, string attributeValue)
{
    _attributeName = attributeName;
    _attributeStringValue = attributeValue;
    
    _isNumber = false;
}



//**************************************************************
//
// Constructor for number(int) attributes
//
//**************************************************************
Pair::Pair(string attributeName, int attributeNumValue)
{
    _attributeName = attributeName;
    _attributeNumberValue = attributeNumValue;
    _isNumber = true;
}


string Pair::stringValue()
{
    return _attributeStringValue;
    
}
string Pair::attributeName()
{
    return _attributeName;
}

bool Pair::isNumber()
{
    return _isNumber;
}

int Pair::numberValue()
{
    return _attributeNumberValue;
}
