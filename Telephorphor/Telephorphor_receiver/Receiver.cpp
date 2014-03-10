#include <vector>
#include <sstream>
#include <string>

#include <Configuration.h>
#include <pwm_colour.h>
using namespace std;

SoftwareSerial radio = SoftwareSerial(rxPin, txPin);

void setup()
{
  radio.begin(RADIO_BAUDRATE);
}

istringstream radioStream;

void loop()
{
  //parse serial input
  while(radio.available())
  {
    char received = radio.read();
    
    if(received=='\n'){//?;
      //get the first substring
      string sub;
      radiostream >> sub;
      
      //if it is the address of a device being monitored
      for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
        if( sub.compare(it->first) != 0 ){ //it matches device
          
          
      
      
      
      //send response
        
      
    } else {
      radioStream << received;
    }
    
    
  }
    
  
  if(commandReady){
    //modify pwm values
  }
}
  
