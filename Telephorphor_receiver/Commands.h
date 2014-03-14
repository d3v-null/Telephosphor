class Command { // base class for commands
  // virtual parse_parameters( string parameters ) { return 0; }
  // virtual 

  public:
  Command();
}
    
class Hold : public Command {
  int     T;
  string  V;
  
  public:
  Hold( string parameters ) : Command() {
    istringstream iss(parameters);
    iss >> this.T;
    iss >> this.V;
  }
}

class Transition : public Command {
  public:  
    int     T;
    string  V1;
    string  V2;
    
    Transition(string parameters){
      istringstream iss(parameters);
      iss >> this.T;
      iss >> this.V1;
      iss >> this.V2;
    }
}

class Wait : public Command {
  public:  
    string  Q;
    
    Wait(string parameters){
      istringstream iss(parameters);
      iss >> this.Q;
  