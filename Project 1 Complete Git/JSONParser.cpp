
#include "JSONParser.hpp"

//**************************************************************
//
//  Constructor
//
//**************************************************************
JSONParser::JSONParser(JSONTokenizer & t)
    :   tokenizer {t}
    {}




EntityInstance JSONParser::parseJSONObject()
{
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    
    if( ! token.isOpenSquigglyBracket() ) // [ or { ???
    {
        cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << endl;
        token.print();
        cout << "Terminating..." << endl;
        exit(1);
    }
    
    EntityInstance instance;
    
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    
    
    // So, we didn't find a comma. Then, it must be a close brace.
    
    if( ! token.isClosedSquigglyBracket() )
    {
        cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << endl;
        token.print();
        cout << "Terminating..." << endl;
        exit(1);
    }
    
    
    return instance;
}



//**************************************************************
//
// Gets the attribute name and value and assigns it to Pair
//
//**************************************************************
Pair JSONParser::parseAPair()
{
    // get next token
    JSONToken token = tokenizer.getToken();
    
    JSONToken nxtToken = tokenizer.getToken();
    
    if (token.isAttributeString())
    {
        
        if ( nxtToken.isColon() )
        {
            nxtToken = tokenizer.getToken();
            
            if (nxtToken.isAttributeNull())
            {
                Pair pair(token.attributeString() , nxtToken.attributeNull() );
                return pair;
            }
            
                else if (nxtToken.isAttributeInt())
                {
                    Pair pair(token.attributeString() , nxtToken.attributeInt());
                    return pair;
                }
                          else if (nxtToken.isAttributeString())
                          {
                              Pair pair(token.attributeString() , nxtToken.attributeString());
                              return pair;
                          }
            
           
        }
        
    }
    
    
    cout << "Error: JSONParser::parseAPair(): Found Unknown Token" << endl;
    token.print();
    cout << "Terminating..." << endl;
    exit(1);
    
}


