#include <iostream>
#include "include/graph.hpp"

void exec(float hz){
  mc::principal objprincipal(hz, 0.0, 0.0);
}

int main(){
//  mc::principal objprincipal(3.0f);
  
  float hz;

  std::cout << "\n Digite a frequência: ";
  std::cin >> hz; std::cout << "" << std::endl;

  exec(hz);

  return 0;
}
