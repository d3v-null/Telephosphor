
#include <string>
using std::string;
string name;




#include "statevector.h"
//#include <signal.h>
typedef string QueueSignal;

using namespace std;

class Command { // abstract base class for commands
  public:
    virtual void parse_parameters( string );
}

class StateCommand : public Command {
  public:
    virtual Statevector get_value( time_t );
    virtual time_t get_lifetime();
}
    
class Hold : public StateCommand {
  int         T;
  statevector V;
}

class Transition : public StateCommand {
  int         T;
  Statevector V1;
  Statevector V2;
}

class TimingCommand : public Command {
  QueueSignal Q;
  virtual QueueSignal getSignal(){
    return Q;
  }
  void parse_parameters(string parameters);
}

class Wait : public TimingCommand {
}

class Resume : public TimingCommand {
}
