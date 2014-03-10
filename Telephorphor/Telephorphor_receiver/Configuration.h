#include <string>

//Common
#Define RADIO_BAUDRATE 9600


//Receiver
#define rxPin 0
#define txPin 1

class Operation {
  string opCode;
  
typedef map<string, int[3], string.compare> deviceInfo;
deviceInfo devices;
devices["A"] = {3, 5, 6};
devices["B"] = {9, 10, 11};


//Client

