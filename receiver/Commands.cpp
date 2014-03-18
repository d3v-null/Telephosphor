#include "Commands.h"

#include <istringstream>
#include <statevector.h>

// Command::Command(string parameters) {
  // parse_parameters(parameters);
// }
//void Command::parse_parameters(string parameters) = 0;

// Hold::Hold(string parameters)
void Hold::parse_parameters( string parameters ) {
  istringstream iss(parameters);
  iss >> T;
  iss >> V;
}
time_t Hold::get_lifetime() {
  return T;
}
Statevector Hold::get_value( time_t elapsed ){
  return V;
}

// Transition::Transition(strig parameters) : 
void Transition::parse_parameters( string patameters ){
  istringstream iss(parameters);
  iss >> T;
  iss >> V1;
  iss >> V2;
}
time_t Transition::get_lifetime(){
  return T;
}
Statevector Transition::get_value( time_t elapseed ){
  Statevector D = V2 - V1;
  //assert 0 < T && 0 <= elapsed <= T 
  return V1 + D * (elapsed/T);
}  

void TimingCommad::parse_parameters( string parameters ){
  istringstream iss(parameters);
  iss >> Q;
}
