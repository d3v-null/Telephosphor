#include <vector>
#include <sstream>
#include <string>

#include <Configuration.h>
//#include <pwm_colour.h>
using namespace std;

SoftwareSerial radio = SoftwareSerial(rxPin, txPin);

class Command { //base class for commands
  public:
  Command(){
    ;
  }
}
    
class Hold : Command {
  int T;
  string V;
  
  public:
  Hold( int T, string V ) : Command() {
    this.T = T;
    this.V = V;
  }
}

class Transition : Command {
  int T;
  string V1;
  string V2;
  
  private:
  void init(
  
  public:
  Transition(int T, string V1, string V2) : Command() {
    this.T = T;
    this.V1 = V1;
    this.V2 = V2;
  }
  
  Transition(string parameters){
  
}

class Device {
    vector<Command> commandBuffer;
  public:
    Device();
    
    void processCommand(istringstream command){
      //get command code (first string of command)
      string code;
      command >> code;
      
      if(code.compare("H") == 0){
        int T;
        command >> T;
        string V;
        command >> V
        
        
      } else if(code.compare("T") == 0){
        
      } else if(code.compare("P")
      
    void update(){
    }
}    

class PWM : public Device {
  int pin;
}

class RGBPWM : public Device {
  int[3] pins; 
}

class WS2812Chain : public Device {
  int pin;
}
  
typedef map<string, Device, string.compare> deviceInfo;
deviceInfo devices;
devices["01"] = {3, 5, 6};
devices["02"] = {9, 10, 11};


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
    
    if(received=='\n'){//have received whole command, pase command
      //get the address (the first substring)
      string address;
      radiostream >> address;
      
      //if address is the multicast address
      if( address.compare(MULTICAST_ADDRESS) ){
        for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
          it->last.processCommand(radiostream)
      
      //if it is the address of a device being monitored
      for(deviceInfo::iterator it = devices.begin(); it != devices.end(); ++it){
        if( address.compare(it->first) != 0 ){ //it matches address of
        
      
    } else {
      radioStream << received;
    }
    
    
  }
    
  
  if(commandReady){
    //modify pwm values
  }
}
  
