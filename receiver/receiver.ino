


//#include <Configuration.h>
#include "Commands.h"
#include "Devices.h"
#include <Time.h>
#include <vector>
#include <sstream>
//#include <string>




using namespace std;

SoftwareSerial radio = SoftwareSerial(rxPin, txPin);
  
typedef map<string, Device> deviceInfo;
deviceInfo devices;
// devices["01"] = {3, 5, 6};
devices["01"] = (Device) new RGBPWM(3, 5, 6);
devices["02"] = (Device) new RGBPWM(9, 10, 11);


void setup() {
  radio.begin(RADIO_BAUDRATE);
}

istringstream radioStream;

void loop() {
  //parse serial input
  while(radio.available())
  {
    char received = radio.read();
    radioStream << received;
    
    if(received=='\n'){//have received whole command, pass command
      //get the address (the first substring)
      string address;
      string command;
      radiostream >> address;
      getline(radiostream, command);
      
      //if address is the multicast address
      if( address.compare(MULTICAST_ADDRESS) ){
        for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
          it->last.processCommand(command);
        }
      }
      
      //if it is the address of a device being monitored
      for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
        if( address.compare(it->first) != 0 ){ //it matches address of a monitored device
          it->last.processCommand(command);
          break; //???
        }
      }
    } 
  }
  
  for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
    it->last.update(now());
  }
}
  
