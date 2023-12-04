#include "const.hpp"
#include <gerenciarUsuario.hpp>

int main(){
  
  GerenciarUsuario gu;

  gu.carregarUsuarios(ARQUSUARIO);
  gu.imprimirPerfis();
  gu.inserirUsuario();
  gu.imprimirPerfis();
  gu.salvarUsuarios(ARQUSUARIO);
  gu.inserirUsuario();
  gu.imprimirPerfis();
  gu.salvarUsuarios(ARQUSUARIO);

  return 0;
}
