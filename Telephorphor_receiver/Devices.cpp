#include <Devices.h>

class Device {
  vector<Command> commandBuffer;
  
  public:
  Device();

  void processCommand(string command){
    //get command code (first string of command)
    string code;
    string parameters;
    istringstream iss(command);
    iss >> code;
    getline(iss, parameters);
    
    
    //process parameters (rest of command)
    if(code.compare("H") == 0){
      commandBuffer.push_back(Hold(parameters));
    } else if(code.compare("T") == 0){
      commandBuffer.push_back(Transition(parameters));
    } else if(code.compare("W") == 0){
      commandBuffer.push_back(Wait(parameters));
    }
  }
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