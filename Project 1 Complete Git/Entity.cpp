
#include "Entity.hpp"

//**************************************************************
//
// Adds an EntityInstance object to the vector which holds
//  EntityInstance's
//
//**************************************************************
void Entity::addObject(EntityInstance &enInst)
{
    instances.push_back(enInst);
}


//**************************************************************
//
// Will get the next EntityInstance and then call it's print to
//   print it's attributes.
//
//**************************************************************
void Entity::print()
{
    int size = int(instances.size());
    
    for (int x = 0; x < size ; x++)
    {
        instances.at(x).print();
        cout << "\n\n";
    }
}

//**************************************************************
//
// Will print a certain number of the instances
//
//**************************************************************
void Entity::limitPrint(int n)
{
    for (int x = 0; x < n ; x++)
    {
        instances.at(x).print();
        cout << "\n\n";
    }
    
}

//**************************************************************
//
// Will print the specific instances searched for
//
//**************************************************************
void Entity::selectTuplesPrint(vector<CommandToken>& tokenHolder)
{
    int size = int(instances.size());
    
     cout << "Here are the entity instances that match the attributes searched for.\n\n";
    
    for (int x = 0 ; x < size ; x++)
    {
        instances.at(x).selectTuplePrint(tokenHolder);
        
    }
    
}




