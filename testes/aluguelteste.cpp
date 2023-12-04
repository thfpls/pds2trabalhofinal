#include "aluguel.hpp"

int main(){

  Aluguel al1("t1","a@a");
  Aluguel al2("t2","b@b");

  std::cout << al1.paraCSV() << std::endl;
  std::cout << al2.paraCSV() << std::endl;

  return 0;
}
