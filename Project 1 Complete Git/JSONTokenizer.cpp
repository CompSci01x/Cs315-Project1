
#include "JSONTokenizer.hpp"


//**************************************************************
//
// Finds char of intrest
//
//**************************************************************
bool JSONTokenizer::charOfInterest(char c)
{
    
    if (c == '[')
    {
        return true;
    }
    
    else if (c == '{')
    {
        return true;
    }
    
    else if (c == '"' &&  ( isalnum(inStream.peek() )  ) )
    {
        return true;
    }
    
    else if ( isalnum(c) )
    {
        return true;
    }
    
    else if (c == ':')
    {
        return true;
    }
    
    else if (c == ',')
    {
        return true;
    }
    
    else if (c == '}')
    {
        return true;
    }
    
    else if (c == ']')
    {
        return true;
    }
    
    
    return false;
}


//**************************************************************
//
// Runs through the JSON file and gets Tokens
//
//**************************************************************
JSONToken JSONTokenizer::getToken()
{
    char c;
    
    while (inStream.get(c) && !charOfInterest(c))
    {
        
    }
    
 
    JSONToken token;
    
    
    if (inStream.eof())
    {
        token.endOfFile() = true;
        return token;
    }

    if (c == '[')
    {
        token.isOpenSquareBracket() = true;
        return token;
    }
    
    else if (c == '{')
    {
        token.isOpenSquigglyBracket() = true;
        return token;
    }
    
    else if (c == '"' &&  ( isalnum(inStream.peek() )  ) )
    {
        
        token.makeString( assignAttributeString() );
        return token;
    }
    
    else if ( isalnum(c) )
    {
        
        if (c == 'n' && inStream.peek() == 'u')
        {
            token.makeNull( assignAttributeNull(c) );
            token.isAttributeNull() = true;
            return token;
        }
        
        if (isdigit(c))
        {
                token.makeInt( assignAttributeInt(c) );
                token.isAttributeInt() = true;
                return token;
            }
        
    }
    
    else if (c == '}')
    {
        token.isClosedSquigglyBracket() = true;
        return token;
    }
    
    else if (c == ']')
    {
        token.isClosedSquareBracket() = true;
        return token;
    }
    
    else if (c == ':')
    {
        token.isColon() = true;
        return token;
        
    }
    
    else if (c == ',')
    {
        token.isComma() = true;
        return token;
    }
    
    
    else
    {
        cout << "Unkown Token\n\n";
    }
    
    return token;
    
}


//**************************************************************
//
// Assigns the attribute string value
//
//**************************************************************
string JSONTokenizer::assignAttributeString()
{
 
    char c;
    string attribute = "";
    
    
    do
    {
        inStream.get(c);
        attribute += c;
        
        
    }while ( inStream.peek() != '"');
    
        inStream.get(c);
   
    return attribute;
}


//**************************************************************
//
// Assigns the attribute number(int) value
//
//**************************************************************
int JSONTokenizer::assignAttributeInt(char c)
{
    int num = 0;
    string temp = "";
    temp+=c;
    
    
    inStream.get(c);
    
    if (!isdigit(c))
    {
        inStream.putback(c);
    }
    else
    {
        do
        {
            temp+=c;
            inStream.get(c);
            
        }while(isdigit(inStream.peek() ) );
        
        stringstream numString(temp);
       
        
        numString >> num;
    
    }
    
    return num;
}



//**************************************************************
//
// Assigns the the null value as a string
//
//**************************************************************
string JSONTokenizer::assignAttributeNull(char c)
{
    
    string n = "";
    n += c;
    
    do
    {
        inStream.get(c);
        n += c;
        
        
    }while (n != "null");
    
    return n;
}




