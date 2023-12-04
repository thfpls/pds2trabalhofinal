#include "acervo.hpp"

int main(){
  AcervoBiblioteca ac, ac1;

  ac.inserirLivro();
  ac.inserirLivro();
  ac.verAcervo();
  ac.buscarLivro();
  Livro l1 = ac.localizarLivro("t1");
  l1.setAutor("a1a");
  ac.atualizarLivro(l1);
  ac.verAcervo();
  ac.salvarAcervo("livros.csv");
}
