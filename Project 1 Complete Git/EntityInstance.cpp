
#include "EntityInstance.hpp"

//**************************************************************
//
// Adds Pair object's to the vector which holds Pair object's
//
//**************************************************************
void EntityInstance::addAttribute(Pair & pair)
{
    entityAttributes.push_back(pair);
}


//**************************************************************
//
// Will print the attributes of the Entity Instance
//
//**************************************************************
void EntityInstance::print()
{
    
    int size = int(entityAttributes.size() );
    
    for (int x = 0; x < size ; x++)
    {
       
        cout << entityAttributes.at(x).attributeName() << " : ";
        
        
        if (entityAttributes.at(x).isNumber())
        {
            cout << entityAttributes.at(x).numberValue() << endl;
        }
        else
        {
             cout << entityAttributes.at(x).stringValue() << endl;
        }
        
    }
    
    
}


//**************************************************************
//
// Will only print the Entity Instance(s) attributes that were
//  searched for
//
//**************************************************************
void EntityInstance::selectTuplePrint(vector<CommandToken>& tokenHolder)
{
    // holds the number of attributes
    int size = int(entityAttributes.size() );
    int tokenHolderSize = int(tokenHolder.size());
    int y = 0;
    
    
    for (int x = 0 ; x < size ; x++)
    {
            if (tokenHolder.at(y).aString() == entityAttributes.at(x).attributeName())
            {
                y++;
                // check if attribute searched for is a number
                if (tokenHolder.at(y).isNum())
                {
                    if (tokenHolder.at(y).returnNum() == entityAttributes.at(x).numberValue())
                    {
                        x = 0;
                        y++;
                        
                        if (y >= tokenHolderSize)
                        {
                            for (int z = 0 ; z < size ; z++)
                            {
                                cout << entityAttributes.at(z).attributeName() << " : ";
                                
                                if (entityAttributes.at(z).isNumber())
                                {
                                    cout << entityAttributes.at(z).numberValue() << endl;
                                }
                                else
                                {
                                    cout << entityAttributes.at(z).stringValue() << endl;
                                }
                                
                            }
                            
                            cout << "\n\n";
                            return;
                        }
                    }
                }
                
                // otherwise the attribute searched for is a string
              else if (tokenHolder.at(y).aString() == entityAttributes.at(x).stringValue())
                {
                    
                    x = 0;
                    y++;
                    
                    if (y >= tokenHolderSize)
                    {
                        for (int z = 0 ; z < size ; z++)
                        {
                            
                            cout << entityAttributes.at(z).attributeName() << " : ";
                            
                            if (entityAttributes.at(z).isNumber())
                            {
                                cout << entityAttributes.at(z).numberValue() << endl;
                            }
                            else
                            {
                                cout << entityAttributes.at(z).stringValue() << endl;
                            }
                            
                           
                        }
                        
                        cout << "\n\n";
                        return;
                    }
                    
                }
                
                
                
            }
        
        
      }
    
   
    
}

