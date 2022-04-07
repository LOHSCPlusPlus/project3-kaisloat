#include <iostream>
#include "ItemDB.cpp"
using namespace std;

int main() {
  vgDB a;
  //search field is the category they are searching for (developed, publisher ,platform, etc.)
  char searchField = '\0';
  char search[MAX_CHARACTERS] = {'\0'};
  a.initialFileRead();
  int option = 0;

  
  while(true){
    for(int index = 0; index < MAX_CHARACTERS; ++index){
      search[index] = {'\0'};
    }
    searchField = '\0';
    cout << endl << "\t1. Print all Videogames" << endl << "\t2. Print by Sales" << endl << "\t3. Print by Platform" << endl << "\t4. Print by Developer" << endl << "\t5. Print by Publisher" << endl << "\t6. Add Videogame" << endl << "\t7. Remove Videogame" << endl << "\t8. Save Changes" << endl << "\t9. Reload File" << endl << "\t0. Quit" << endl << "\nSelect an option: ";
    cin >> option;
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else if(option == 1){
      searchField = '\0';
      a.printVGs(searchField, search, 'c');
    }
    else if(option == 2){//create two options: high to low or vice versa
      do{
        option = 0;
        cout << "\n\t1. Search Sales by High to Low" << endl << "\t2. Search Sales by Low to High" << endl << "\t3. Quit\n\nSelect an option: ";
        cin >> option;
        if(!cin){
          cin.clear();
          cin.ignore(9999, '\n');
          cout << "\n\tInvalid input data.\n" << endl;
        }
        else if(!(option <= 3 && option >= 1)){
          cout << "\n\tInvalid input.\n" << endl;
        }
        else{
          if(option == 1){
            search[0] = 'h';
          }
          else if(option == 2){
            search[0] = 'l';
          }
          break;
        }
      }while(true);
      if(option != 3){
        searchField = 's';
        a.printVGs(searchField, search, 'c');
      }
    }
    else if (option == 3){
      charArrayInput(search, "Platform to search: ");
      searchField = 'f';
      a.printVGs(searchField, search, 'c');
    }
    else if (option == 4){
      charArrayInput(search, "Developer to search: ");
      searchField = 'd';
      a.printVGs(searchField, search, 'c');
    }
    else if (option == 5){
      charArrayInput(search, "Publisher to search: ");
      searchField = 'p';
      a.printVGs(searchField, search, 'c');
    }
    else if(option == 6){//HERE
      a.addVG();
    }
    else if(option == 7){
      a.removeVG();
    }
    else if (option == 8){
      a.saveChanges();
      cout << "The file has been changed." << endl;
    }
    else if(option == 9){
      a.reloadFile();
      cout << "The file has been restored." << endl;
    }
      else if(option == 0){
        break;
      }
    else{
      cout << endl << "Invalid response." << endl;
    }
  }
  
  return 0;
}
