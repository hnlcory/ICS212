#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "lickitung.h"
#include "sunkern.h"
#include "unown.h"

void checkPokedex(pokemon *);

int main(){

   pokemon *poke1, *poke2, *poke3;

   poke1 = new lickitung;
   poke2 = new sunkern;
   poke3 = new unown;

   std::vector<std::string> vec1;
   std::map<std::string, pokemon*> map1;

   vec1.push_back("pinkBlob");
   vec1.push_back("literalSeed");
   vec1.push_back("symbolThing");

   map1.insert(std::map<std::string, pokemon*>::value_type(vec1.at(0),poke1));
   map1.insert(std::map<std::string, pokemon*>::value_type(vec1.at(1),poke2));
   map1.insert(std::map<std::string, pokemon*>::value_type(vec1.at(2),poke3));   

   checkPokedex(map1.at("pinkBlob"));
   checkPokedex(map1.at("symbolThing"));
   checkPokedex(map1.at("literalSeed"));
    
   delete poke1;
   delete poke2;
   delete poke3;
   
   return 0;
}

void checkPokedex(pokemon *pokemonPtr)
{
    pokemonPtr->printData();
}

