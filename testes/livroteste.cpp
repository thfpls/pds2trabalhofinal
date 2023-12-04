#include "livro.hpp" 

int main(){
  Livro l1("livro1", "a1", 2001);
  Livro l2("livro2", "a2", 2002);
  l2.deCIN();

  std::cout << l1.getTitulo() << std::endl;
  std::cout << l1.getAutor() << std::endl;
  std::cout << l1.getAnoPublicacao() << std::endl;


  std::string aux = l2.paraCSV();
  std::cout << aux << std::endl;
  aux = l1.paraCSV();
  std::cout << aux << std::endl;

  l2.deCSV(aux);
  std::cout << l2.getTitulo() << std::endl;
    
  aux = l2.paraCSV();
  std::cout << aux << std::endl;
 
  return 0;
}
