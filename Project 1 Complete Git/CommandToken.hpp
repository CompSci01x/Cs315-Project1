

#ifndef CommandToken_hpp
#define CommandToken_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class CommandToken
{
  
public:
    
    CommandToken();
    
    bool &isLet();
    bool &isOpen();
    
    bool &isEqualSign();
    bool &isOpenParen();
    bool &isClosedParen();
    
    bool &isPeriod();
    bool &isPrint();
    

    bool &isLimit();
    bool &isString();
    
    bool &isNum();
    bool &isSelectTuples();
    
  

    bool &isComma();
    bool &isOpenSquigglyBracket();
    bool &isClosedSquigglyBracket();
    bool &isColon();
    
    bool &isObjCourses();
    
    bool &endOfFile();
    
    

    string aString();
    
    int returnNum();
  
    void makeString(string);

    void makeNum(int);

    
    void print();
    
    
private:
    bool _isLet , _isOpen , _isObjCourses , _isEqualSign , _isOpenParen , _isClosedParen , _isPeriod , _isPrint ,_isFileName , _isLimit ,_isNum , _isSelectTuples , _isAttributeName, _isAttributeStringValue , _isComma, _isColon ,_isString, _isOpenSquigglyBracket, _isClosedSquigglyBracket , _eof;
    
    
    string _aString;
    
    int num;
 
    
    
    
};


#endif /* CommandToken_hpp */
