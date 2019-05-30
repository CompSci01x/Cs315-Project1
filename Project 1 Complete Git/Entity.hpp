

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "EntityInstance.hpp"
#include "CommandTokenizer.hpp"


class Entity
{
public:
    Entity()
    {
        
    }
    
   void  addObject(EntityInstance &);
    void print();    // prints all instances of this Entity.
    void limitPrint(int);
    void selectTuplesPrint(vector<CommandToken>&);
    

    
private:
    std::vector<EntityInstance> instances;
};

#endif /* Entity_hpp */
