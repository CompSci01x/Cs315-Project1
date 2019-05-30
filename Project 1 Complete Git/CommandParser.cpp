

#include "CommandParser.hpp"
#include "JSONParser.hpp"


//**************************************************************
//
// Gets command Tokens id's them and calls the corresponding
//  function to execute the commands
//
//**************************************************************
void CommandParser::parser()
{

    CommandToken commandToken = tokenizer.getToken();
    
    Entity entityName;

    while (!commandToken.endOfFile())
    {
        
        if (commandToken.isLet())
        {
            
            entityName = executeLet(commandToken);
            
        }
        else if (commandToken.isPrint())
        {
            printFunction(entityName);
            
        }
        
        commandToken = tokenizer.getToken();
        
    }
    
    
}


//**************************************************************
//
// Is called when the key word "print" is found
//
//**************************************************************

void CommandParser::printFunction(Entity entity)
{
 
    CommandToken token = tokenizer.getToken();
    
    if (token.isObjCourses())
    {
        token = tokenizer.getToken();
    
        if (token.isPeriod())
        {
            token = tokenizer.getToken();
            
            if (token.isSelectTuples())
            {
                token = tokenizer.getToken();
                
                if (token.isOpenParen())
                {
                    token = tokenizer.getToken();
                    
                    if (token.isOpenSquigglyBracket())
                    {
                        printSelectTuples(entity);
                        exit(0);
                    }
                
                }
               
            }
            
            if (token.isLimit())
            {
                token = tokenizer.getToken();
                
                if (token.isOpenParen())
                {
                    token = tokenizer.getToken();
                    
                    if (token.isNum())
                    {
                        // just to check that the next token is a Closed Paren Before Printing
                        CommandToken nxtToken = tokenizer.getToken();
                       
                        if (nxtToken.isClosedParen())
                        {
                            cout << "Printing the first: " << token.returnNum() << " instances\n\n";
                            entity.limitPrint(token.returnNum());
                        }
                        
                        else
                        {
                            cout << "Expected a Closed Parentheses but found ";
                            nxtToken.print();
                            cout << "Terminating\n\n";
                            exit(3);
                        }
                        
                        
                    }
                    
                }
            }
        }
    }
    
}


//**************************************************************
//
// Is called to print specific rows
//
//**************************************************************
void CommandParser::printSelectTuples(Entity entity)
{
     CommandToken token = tokenizer.getToken();
    
            if (token.isString())
            {
                CommandToken nxtToken = tokenizer.getToken();
                
                if (nxtToken.isColon())
                {
                    nxtToken = tokenizer.getToken();
                    
                    if (nxtToken.isString() || nxtToken.isNum())
                    {
                        CommandToken checkerToken = tokenizer.getToken();
                        
                        // this will run if multi set of attributes is searched for
                        if (checkerToken.isComma())
                        {
                            tokenHolder.push_back(token);
                            tokenHolder.push_back(nxtToken);
                            printSelectTuples(entity);
                            
                        }
                        // this will run if only 1 set of attributes is searched for
                        else if (checkerToken.isClosedSquigglyBracket())
                        {
                            checkerToken = tokenizer.getToken();
                            
                            if (checkerToken.isClosedParen())
                            {
                                    tokenHolder.push_back(token);
                                    tokenHolder.push_back(nxtToken);
                                entity.selectTuplesPrint(tokenHolder);
                                //maybe tokenholder.empty;
                                
                            }
                            
                        }
                        
                        
                    }
                }
                
             }
    }



//**************************************************************
//
// The "let" command creates the internal rep
//  of the JSON file which is passed in and assigns it to courses
//
//**************************************************************
Entity CommandParser::executeLet(CommandToken& commandToken)
{
    
    if (commandToken.isLet())
    {
        commandToken = tokenizer.getToken();
        
        if (commandToken.isObjCourses())
        {
            CommandToken nxtCommandToken = tokenizer.getToken();
           
            if (nxtCommandToken.isEqualSign())
            {
                nxtCommandToken = tokenizer.getToken();
                
                if (nxtCommandToken.isOpen())
                {
                    nxtCommandToken = tokenizer.getToken();
                    
                    if (nxtCommandToken.isOpenParen())
                    {
                        nxtCommandToken = tokenizer.getToken();
                        
                        
                        ifstream inStream(nxtCommandToken.aString());
                        
                        JSONTokenizer jsonTokenizer(inStream);
                        JSONToken token = jsonTokenizer.getToken();
                        
                    
                        
                            if (token.isOpenSquareBracket())
                            {
                                JSONParser parser(jsonTokenizer);
                                EntityInstance instance;
                                Entity courses;
                        
                                int numInstances = 0;
                        
    
                                do
                                {
                        
                               instance = parser.parseJSONObject();
                        
                                courses.addObject(instance);
                                     numInstances++;
                        
                                token = jsonTokenizer.getToken();
                        
                                }while (token.isComma());
                        
                        
                                if (token.isClosedSquareBracket())
                                {
                                    cout << "Total number of entity instances: " << numInstances << "\n\n";
                                }
                                else
                                {
                                    cout << "Unkown Token\n";
                                    token.print();
                                }
                        
                                nxtCommandToken = tokenizer.getToken();
                        
                                // make sure the nxtToken is a Closed Parenthese
                                if (!nxtCommandToken.isClosedParen())
                                {
                                    cout << "Expected a Closed Parentheses but found ";
                                    nxtCommandToken.print();
                                    cout << "Terminating\n\n";
                                    exit(2);
                                }
                               
                                return courses;
                                
                            }
                        

                    }
                }
            }
        }
    }
    
    
    
    cout << "Error: CommandParser::executeLet(CommandToken& commandToken): Found Unknown Token" << endl;
    commandToken.print();
    cout << "Terminating..." << endl;
    exit(1);
    
    
}
