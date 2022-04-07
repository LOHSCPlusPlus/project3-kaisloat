#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

#include "ItemClass.cpp"
using namespace std;


class vgDB{
  private:
    enum{MAX_VIDEOGAMES = 60};
    int vgNum;
    videogame vgList[MAX_VIDEOGAMES];
  public:
    vgDB();
    void fileRead();
    void initialFileRead();
    void printVGs(char searchField, char search[], char outputLocation);
    void reloadFile();
    void saveChanges();
    void removeVG();
    void addVG();
};