#include "ItemClass.h"

//default constructor
videogame::videogame(){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    name[index] = '\0';
    platform[index] = '\0';
    initialRelease[index] = '\0';
    developer[index] = '\0';
    publisher[index] = '\0';
  }
  sales = 0;
}

//prints an individual object of struct videogame into the desired location
void videogame::printVG(ostream &out){
  out << name << ';';
  out << sales << ';';
  out << platform << ';';
  out << initialRelease << ';';
  out << developer << ';';
  out << publisher << endl;
}

//inputs from the file a single "videogame"
void videogame::readVG(ifstream &inFile){
  inFile.get(name, MAX_CHARACTERS, ';');
  inFile.ignore(999, ';');
  inFile >> sales;
  inFile.ignore(999, ';');
  inFile.get(platform, MAX_CHARACTERS, ';');
  inFile.ignore(999, ';');
  inFile.get(initialRelease, MAX_CHARACTERS, ';');
  inFile.ignore(999, ';');
  inFile.get(developer, MAX_CHARACTERS, ';');
  inFile.ignore(999, ';');
  inFile.get(publisher, MAX_CHARACTERS, '\n');
  inFile.ignore(999, '\n');
}

//Below are accessors for all the class's private fields
void videogame::getName(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
     cArray[index] = name[index]; 
    }
}
int videogame::getSales(){
  return sales;
}
void videogame::getPlatform(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
   cArray[index] = platform[index]; 
  }
}
void videogame::getRelease(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
   cArray[index] = initialRelease[index]; 
  }
}
void videogame::getDeveloper(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
   cArray[index] = developer[index]; 
  }
}
void videogame::getPublisher(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
   cArray[index] = publisher[index]; 
  }
}

//below are mutators for the class's private fields
void videogame::setName(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    name[index] = cArray[index];
  }
}
void videogame::setPlatform(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    platform[index] = cArray[index];
  }
}
void videogame::setRelease(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    initialRelease[index] = cArray[index];
  }
}
void videogame::setDeveloper(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    developer[index] = cArray[index];
  }
}
void videogame::setPublisher(char cArray[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    publisher[index] = cArray[index];
  }
}
void videogame::setSales(int num){
  sales = num;
}