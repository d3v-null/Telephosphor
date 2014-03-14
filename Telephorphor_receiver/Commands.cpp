
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
  // Hold( int T, string V ) : Command() {
    // this.T = T;
    // this.V = V;
  // }
  Hold( string parameters ) : Command() {
    istringstream iss(parameters);
    iss >> this.T;
    iss >> this.V;
  }
}

class Transition : Command {
  int     T;
  string  V1;
  string  V2;
  
  public:
  // Transition(int T, string V1, string V2) : Command() {
    // this.T = T;
    // this.V1 = V1;
    // this.V2 = V2;
  // }
  
  Transition(string parameters){
    istringstream iss(parameters);
    iss >> this.T;
    iss >> this.V1;
    iss >> this.V2;
  }
}