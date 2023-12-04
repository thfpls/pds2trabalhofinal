#include <gerenciarAluguel.hpp>

int main(){
  GerenciarAluguel ga;

  ga.alugarLivro("t1","b@b"); 
  ga.aumentarPrazo("t1",5);
  ga.definirMulta("t1",10.0);
  ga.salvarAluguel(ARQALUGUEL);
  ga.devolverLivro("t1"); 

  return 0;
}
