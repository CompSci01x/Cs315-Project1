

#include "CommandTokenizer.hpp"


//**************************************************************
//
// Runs through the input file which only holds commands and
//  gets Tokens
//
//**************************************************************
CommandToken CommandTokenizer::getToken()
{
    char c;
    
    while (inStream.get(c) && !charOfInterest(c))
    {
        
    }
    
    CommandToken token;
  
    
    if (inStream.eof())
    {
        token.endOfFile() = true;
        return token;
    }

    if (c == 'l' && inStream.peek() == 'e')
    {
       
        string check = commandKeyWord(c);
        
        if (check == "let")
        {
            token.isLet() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "let\n" << "but found";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
        
        
    }
    
    else if (c == 'l' && inStream.peek() == 'i')
    {
        
        string check = commandKeyWord(c);
        if (check == "limit")
        {
            token.isLimit() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "limit\n" << "but found";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
        
        
    }
    
    else if (c == 'c')
    {
        string check = commandKeyWord(c);
        
        if (check == "courses")
        {
            
            token.isObjCourses() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "courses\n" << "but found";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
        
    }
    
    else if (c == '=')
    {
        token.isEqualSign() = true;
        return token;
    }
    
    else if (c == 'o')
    {
        string check = commandKeyWord(c);
        
        if (check == "open")
        {
            token.isOpen() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "open\n" << "but found";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
       
    }
    
    else if (c == 'p')
    {
        string check = commandKeyWord(c);
        
        if (check == "print")
        {
            token.isPrint() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "print\n" << "but found";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
        
    }
    
    else if (c == '(')
    {
        
        token.isOpenParen() = true;
        return token;
    }
    
    else if (c == ')')
    {
        token.isClosedParen() = true;
        return token;
    }
    
    else if (c == '"')
    {
      
        token.isString() = true;
        token.makeString(quotedString(c));
        
        return token;
        
    }
    
    
    else if (c == '.')
    {
        token.isPeriod() = true;
        return token;
    }
    
    else if (isdigit(c))
    {
        
        token.isNum() = true;
        token.makeNum(createDigit(c));
        
        return token;
        
    }
    
    else if (c == 's')
    {
        string check = commandKeyWord(c);
        if (check == "selectTuples")
        {
            token.isSelectTuples() = true;
            return token;
        }
        else
        {
            cout << "Expected key word: " << "selectTuples\n" << "but found\n";
            cout << check << endl;
            cout << "Terminating..." << endl;;
            exit(1);
        }
        
    }
    
    else if (c == '{')
    {
        token.isOpenSquigglyBracket() = true;
        return token;
    }
    else if (c == '}')
    {
        token.isClosedSquigglyBracket() = true;
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
    
    return token;
}

//**************************************************************
//
// Finds char of intrest
//
//**************************************************************

bool CommandTokenizer::charOfInterest(char c)
{
    if (c == 'l' && inStream.peek() == 'e')
    {
        return true;
    }
    
    else if (c == 'l' && inStream.peek() == 'i')
    {
        return true;
    }
    
    else if (c == 'c')
    {
        return true;
    }
    else if (c == 'p')
    {
        return true;
    }
    
    else if (c == '=')
    {
        return true;
    }
    
    else if (c == 'o')
    {
        return true;
    }
    else if (c == '(')
    {
        return true;
    }
    
    else if (c == ')')
    {
        return true;
    }
    else if (c == '"')
    {
        return true;
    }
    
    else if (c == '.')
    {
        return true;
    }
    
    else if (isdigit(c))
    {
        return true;
    }
    
    else if (c == 's')
    {
        return true;
    }
    else if (c == '{')
    {
        return true;
    }
    else if (c == '}')
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
    
    return false;
}



//**************************************************************
//
// Assigns the key word
//
//**************************************************************
string CommandTokenizer::commandKeyWord(char c)
{
    
    string temp = "";
    temp += c;
    
    while ( isalnum( inStream.peek() ) )
    {
        inStream.get(c);
        temp += c;
    }
    
        return temp;
    
}


//**************************************************************
//
// Assigns the Quoted String
//
//**************************************************************
string CommandTokenizer::quotedString(char c)
{

    string temp = "";
    
    do
    {
        inStream.get(c);
        temp += c;
        
    }while(inStream.peek() != '"');
    
    inStream.get(c);
    
    return temp;

    
}

//**************************************************************
//
// Assigns the number
//
//**************************************************************
int CommandTokenizer::createDigit(char c)
{
    string temp = "";
    temp+=c;
    
    while (isdigit(inStream.peek()))
    {
        inStream.get(c);
        temp += c;
    }
    
    stringstream numString(temp);
    int digit;
    numString >> digit;
    
    return digit;
    
}
