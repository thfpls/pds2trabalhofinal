#include <perfilUsuario.hpp>
#include <aluno.hpp>
#include <adm.hpp>

int main(){
  
  Aluno al1("","",0);
  Administrador ad1("","",0);

  al1.deCIN();
  ad1.deCIN();

  std::string aux = al1.paraCSV();
  std::cout << aux << std::endl;
  std::string aux1 = ad1.paraCSV();
  std::cout << aux1 << std::endl;

  return 0;
}
