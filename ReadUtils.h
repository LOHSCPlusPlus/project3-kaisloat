using namespace std;
// Pass in the prompt, it will spin until the user enters an integer
int readInt(const char prompt[]);
// Pass in the prompt, it will spin until the user enters a double
double readDouble(const char prompt[]);
// Ask a y/n question returns true if user enters Y/y or false if user enters N/n
// It will spin until the user enters a y/n or Y/N
bool readBool(const char prompt[]);
//compares 2 character arrays; returns true if they are the same, false if they are different
bool compareCharArray(char cArray1[], char cArray2[]);
//this function takes the user input and stores it into a character array (I made this a function when I was already nearly done, so it is not used in places that it could have been had I made it earlier)
void charArrayInput(char array[], string prompt);