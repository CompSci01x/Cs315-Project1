

#include "CommandToken.hpp"

CommandToken::CommandToken()
{
    _isLet = false;
    _isLimit = false;
    _isOpen = false;
    
    _isObjCourses = false;
    _isEqualSign = false;
    
    _isOpenParen = false;
    _isClosedParen = false;
    
    _isPrint = false;
    _isPeriod = false;
    _isComma = false;
    _isOpenSquigglyBracket = false;
    _isClosedSquigglyBracket = false;
    _isColon = false;
    
    _eof = false;
    
    
    _isNum = false;
    _isSelectTuples = false;
    
    _isAttributeName = false;
    _isAttributeStringValue = false;
    
    
    _isString = false;
    _aString = "";
    

}



bool &CommandToken::isComma()
{
    return _isComma;
}

bool &CommandToken::isOpenSquigglyBracket()
{
    return _isOpenSquigglyBracket;
}

bool &CommandToken::isClosedSquigglyBracket()
{
    return _isClosedSquigglyBracket;
}

bool &CommandToken::isColon()
{
    return _isColon;
}

bool &CommandToken::isLet()
{
    return _isLet;
}

bool &CommandToken::isLimit()
{
    return _isLimit;
}

bool &CommandToken::isOpen()
{
    return _isOpen;
}

bool &CommandToken::isEqualSign()
{
    return _isEqualSign;
}

bool &CommandToken::isOpenParen()
{
    return _isOpenParen;
}
bool &CommandToken::isClosedParen()
{
    return _isClosedParen;
}

bool &CommandToken::isPeriod()
{
    return _isPeriod;
}

bool &CommandToken::isPrint()
{
    return _isPrint;
}




bool &CommandToken::endOfFile()
{
    return _eof;
}

bool &CommandToken::isObjCourses()
{
    return _isObjCourses;
}

bool &CommandToken::isNum()
{
    return _isNum;
}

bool &CommandToken::isSelectTuples()
{
    return _isSelectTuples;
}



bool &CommandToken::isString()
{
    return _isString;
}


string CommandToken::aString()
{
    return _aString;
}


int CommandToken::returnNum()
{
    return num;
}



void CommandToken::makeString(string s)
{
    _aString = s;
    _isString = true;
}

void CommandToken::makeNum(int n)
{
    num = n;
    _isNum = true;
}


//**************************************************************
//
// This function is only for checking if the Tokenizer is
//  working properly (otherwise it is not used).
//
//**************************************************************
void CommandToken::print()
{
    
    if (isLet())
    {
        cout << "let" << endl;
    }
    
    else if (isLimit())
    {
        cout << "limit" << endl;
    }
    
    else if (isObjCourses())
    {
        cout << "courses" << endl;
    }
    
    else if (isEqualSign())
    {
        cout << " = " << endl;
    }
    
    else if (isOpen())
    {
        cout << "open" << endl;
    }
    
    else if (isOpenParen())
    {
        cout << "(" << endl;
    }
    
    else if (isClosedParen())
    {
        cout << ")" << endl;
    }
  
    else if (isPeriod())
    {
        cout << "." << endl;
    }
    
    else if  (isPrint())
    {
        cout << "print" << endl;
    }
    
    else if (isNum())
    {
        cout << returnNum() << endl;
    }
    
    else if (isSelectTuples())
    {
        cout << "selectTuples" << endl;
    }
    
    else if (isColon())
    {
        cout << ":" << endl;
    }
    else if (isOpenSquigglyBracket())
    {
        cout << "{" << endl;
    }
    else if (isClosedSquigglyBracket())
    {
        cout << "}" << endl;
    }
    else if (isComma())
    {
        cout << "," << endl;
    }
    else if (isString())
    {
        cout << aString() << endl;
    }
    
   
    
    else
    {
        cout << "Unknown Token" << endl;
    }
    
}
