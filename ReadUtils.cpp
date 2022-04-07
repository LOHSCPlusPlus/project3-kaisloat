#include <iostream>
#include <string>
#include "ReadUtils.h"
enum{MAX_CHARACTERS = 100};
using namespace std;

void commonErrorCode(const char prompt[]) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
}

int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
double readDouble(const char prompt[]){
    double temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        commonErrorCode(prompt);
        cin >> temp;
    }
    return temp;
}
bool readBool(const char prompt[]){
    char temp;
    cout << prompt;
    cin >> temp;
    temp = toupper(temp); 
    while (temp != 'Y' && temp != 'N') {
        commonErrorCode(prompt);
        cin >> temp;
        temp = toupper(temp);
    }
    return temp == 'Y';
}

bool compareCharArray(char cArray1[], char cArray2[]){
  for(int index = 0; index < MAX_CHARACTERS; ++index){
    if (cArray1[index] != cArray2[index]){
      return false;
    }
  }
  return true;
}

void charArrayInput(char array[], string prompt){
  char temp = '\0';
  do{
    cout << prompt;
    cin >> temp;
    cin.getline(array, MAX_CHARACTERS - 1, '\n');
    if(!cin){
      cin.clear();
      cin.ignore(9999, '\n');
      cout << "\n\tInvalid input data.\n" << endl;
    }
    else{
      for(int index = (MAX_CHARACTERS - 1); index > 0; --index){
        array[index] = array[index - 1];
      }
      array[0] = temp;
      break;
    }
  }while(true);
}