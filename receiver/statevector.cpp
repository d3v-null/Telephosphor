#include <statevector.h>

Statevector::Statevector(vector<int> kernel){
  this.kernel = kernel;
}
Statevector Statevector::operator+= (const Statevector& rhs) {
  for(vector<int>::iterator itb