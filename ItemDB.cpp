#include "ItemDB.h"

//this function is called once at the start; it reads from videogames1, the file that changes with the user input, and stores that file into struct array, return vgNum
void vgDB::initialFileRead(){
  vgNum = 0;
  ifstream inFile("videogames1.txt");
  while(inFile.peek() != EOF && vgNum < MAX_VIDEOGAMES) {
    vgList[vgNum].readVG(inFile);
    ++vgNum;
  }
}

//reads the videogames file, stores it in the struct array, and return the number of videogames
void vgDB::fileRead(){
  int vgNum = 0;
  ifstream inFile("videogames.txt");
  while(inFile.peek() != EOF && vgNum < MAX_VIDEOGAMES) {
    vgList[vgNum].readVG(inFile);
    ++vgNum;
  }
}

//prints the array either to the console or to the file
void vgDB::printVGs(char searchField, char search[], char outputLocation) {
  //if platform, the platform asked should show AS WELL AS multi-platform
  int order[vgNum] = {0};
  char cArray[MAX_CHARACTERS] = {'\0'};
  char comparisonArray[MAX_CHARACTERS] = {'\0'};
  if (searchField == 'f' && outputLocation == 'c'){
    comparisonArray[0] = 'M';
    comparisonArray[1] = 'u';
    comparisonArray[2] = 'l';
    comparisonArray[3] = 't';
    comparisonArray[4] = 'i';
    comparisonArray[5] = '-';
    comparisonArray[6] = 'p';
    comparisonArray[7] = 'l';
    comparisonArray[8] = 'a';
    comparisonArray[9] = 't';
    comparisonArray[10] = 'f';
    comparisonArray[11] = 'o';
    comparisonArray[12] = 'r';
    comparisonArray[13] = 'm';
  }
    //if search by sales, this will order from high to low or vice versa
  else if (searchField == 's' && outputLocation == 'c'){
    if(search[0] == 'l'){//low--high
      for(int index1 = 0; index1 < vgNum; ++index1){

        for(int index4 = 0; index4 < index1; ++index4){
          if(order[index1] == order[index4] && index1 != 0){
            order[index1] += 1;
          }
        }
        
        for(int index2 = 0; index2 < vgNum; ++index2){
          if(vgList[index2].getSales() < vgList[order[index1]].getSales()){
            
            for(int index3 = 0; index3 < vgNum; ++index3){
              if(order[index3] == index2){
                break;
              }
              
              if(index3 == (vgNum - 1)){
                order[index1] = index2;
              }
            }
          
          }
        }
      }
      
      
    }
    else{//high--low
      for(int index1 = 0; index1 < vgNum; ++index1){

        for(int index4 = 0; index4 < index1; ++index4){
          if(order[index1] == order[index4] && index1 != 0){
            order[index1] += 1;
          }
        }
        
        for(int index2 = 0; index2 < vgNum; ++index2){
          if(vgList[index2].getSales() > vgList[order[index1]].getSales()){
            
            for(int index3 = 0; index3 < vgNum; ++index3){
              if(order[index3] == index2){
                break;
              }
              
              if(index3 == (vgNum - 1)){
                order[index1] = index2;
              }
            }
          
          }
        }
      }
    }
  }
  if(outputLocation == 'f'){
    ofstream fileout("videogames1.txt");
    for(int index = 0; index < vgNum; ++index){
      vgList[index].printVG(fileout);
    }
  }
  else{
    for(int index = 0; index < vgNum; ++index){
      //console, all
      if(outputLocation == 'c' && searchField == '\0'){
        cout << "Index " << index << ": ";
        vgList[index].printVG(cout);
      }
      //console, sales (highest to low, or vice versa)
      else if(outputLocation == 'c' && searchField == 's'){
        cout << "Index " << order[index] << ": ";
        vgList[order[index]].printVG(cout);
      }
      //console, platform (searched by + multiplatform)
      else if(outputLocation == 'c' && searchField == 'f'){
        vgList[index].getPlatform(cArray);
        if(compareCharArray(search, cArray) || compareCharArray(comparisonArray, cArray) ){
          cout << "Index " << index << ": ";
          vgList[index].printVG(cout);
        }
      }
      //console, developer (searched by)
      else if(outputLocation == 'c' && searchField == 'd'){
        vgList[index].getDeveloper(cArray);
        if(compareCharArray(search, cArray)){
          cout << "Index " << index << ": ";
          vgList[index].printVG(cout);
        }
      }
      //console, publisher (search by)
      else if(outputLocation == 'c' && searchField == 'p'){
        vgList[index].getPublisher(cArray);
        if(compareCharArray(search, cArray)){
          cout << "Index " << index << ": ";
          vgList[index].printVG(cout);
        }
      }
    }
  }
}

//reloads the file by copying the base file (videogames) to the user-malleable file (videogames1)
void vgDB::reloadFile(){
  char discard[5] = {'\0'};
  fileRead();
  printVGs('\0', discard, 'f');
}

//saves user-input from the array to the videogames1 file.
void vgDB::saveChanges(){
  char discard[5] = {'\0'};
  printVGs('\0', discard, 'f');
}

//removes a videogame from the database
void vgDB::removeVG(){
  char cArray[MAX_CHARACTERS] = {'\0'};
  int input = 0;
  do{
    cout << "Enter the index of the videogame to remove (-1 to quit): ";
    cin >> input;
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else if(input == -1){
      break;
    }
    else if(!(input < vgNum && input >= 0)){
      cout << "\n\tThat videogame index is not valid.\n" << endl;
    }
    else{
      vgList[input].getName(cArray);
      cout << cArray << " has been removed." << endl;
      for(int index = input; index < vgNum; ++index){
        vgList[index] = vgList[index + 1];
      }
      --vgNum;
      break;
    }
  }while(true);
  return;
}

//adds a videogame to the database
void vgDB::addVG(){
  char cArray[MAX_CHARACTERS] = {'\0'};
  videogame a;
  char temp = '\0';
  int num = 0;
  if(vgNum == MAX_VIDEOGAMES){
    cout << "\tThe videogame database is full, you cannot add another one.\n" << endl;
    return;
  }
  while(true){
    cout << "Enter the name of the videogame to be added: ";
    cin >> temp;
    cin.getline(cArray, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        cArray[index] = cArray[index - 1];
      }
      cArray[0] = temp;
      a.setName(cArray);
      break;
    }
  }
  while(true){
    a.getName(cArray);
    cout << "Enter " << cArray << "'s total number of sales: ";
    cin >> num;
    if(!cin){
      cin.clear();
      cin.ignore(999999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else if(num < 0){
      cout << "\n\tThe number of sales cannot be negative.\n" << endl;
    }
    else{
      a.setSales(num);
      break;
    }
  }
  while(true){
    a.getName(cArray);
    cout << "Enter " << cArray << "'s platform (\"Multi-platform\" for more than 1): ";
    for(int index = 0; index < MAX_CHARACTERS; ++index){
      cArray[index] = '\0';
    }
    cin >> temp;
    cin.getline(cArray, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        cArray[index] = cArray[index - 1];
      }
      cArray[0] = temp;
      a.setPlatform(cArray);
      break;
    }
  }
  while(true){
    a.getName(cArray);
    cout << "Enter " << cArray << "'s release date: ";
    for(int index = 0; index < MAX_CHARACTERS; ++index){
      cArray[index] = '\0';
    }
    cin >> temp;
    cin.getline(cArray, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        cArray[index] = cArray[index - 1];
      }
      cArray[0] = temp;
      a.setRelease(cArray);
      break;
    }
  }
  while(true){
    a.getName(cArray);
    cout << "Enter " << cArray << "'s developer: ";
    for(int index = 0; index < MAX_CHARACTERS; ++index){
      cArray[index] = '\0';
    }
   cin >> temp;
    cin.getline(cArray, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        cArray[index] = cArray[index - 1];
      }
      cArray[0] = temp;
      a.setDeveloper(cArray);
      break;
    }
  }
  while(true){
    a.getName(cArray);
    cout << "Enter " << cArray << "'s publisher: ";
    for(int index = 0; index < MAX_CHARACTERS; ++index){
      cArray[index] = '\0';
    }
    cin >> temp;
    cin.getline(cArray, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        cArray[index] = cArray[index - 1];
      }
      cArray[0] = temp;
      a.setPublisher(cArray);
      break;
    }
  }
  vgList[vgNum] = a;
  ++vgNum;
  return;
}

//default constructor
vgDB::vgDB(){
  initialFileRead();
}