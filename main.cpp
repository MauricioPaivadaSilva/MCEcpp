#include <iostream>
#include "include/graph.hpp"

void exec(float hz, float num1, float num2){
  mc::principal objprincipal(hz, num1, num2);
}

int main(){
//  mc::principal objprincipal(3.0f);
  
  float hz, num1, num2;

  std::cout << "\n Digite a frequência: ";
  std::cin >> hz; std::cout << "" << std::endl;

  std::cout <<"\n Digite o primeiro valor para o vetor complexo: "; std::cin >> num1; std::cout << "" << std::endl;
  std::cout <<"\n Digite o segundo valor para o vetor complexo: "; std::cin >> num2; std::cout << "" << std::endl;

  exec(hz, num1, num2);

  return 0;
}
