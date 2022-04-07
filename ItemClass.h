#include <iostream>
#include "ReadUtils.cpp"
using namespace std;
//enum {MAX_CHARACTERS = 100};


class videogame{
  private:
    char name[MAX_CHARACTERS];
    int sales;
    char platform[MAX_CHARACTERS];
    char initialRelease[MAX_CHARACTERS];
    char developer[MAX_CHARACTERS];
    char publisher[MAX_CHARACTERS];
  public:
    videogame();
    void printVG(ostream &out);
    void readVG(ifstream &inFile);

    void getName(char cArray[]);
    void getPlatform(char cArray[]);
    void getRelease(char cArray[]);
    void getDeveloper(char cArray[]);
    void getPublisher(char cArray[]);
    int getSales();

    void setName(char cArray[]);
    void setPlatform(char cArray[]);
    void setRelease(char cArray[]);
    void setDeveloper(char cArray[]);
    void setPublisher(char cArray[]);
    void setSales(int num);
};