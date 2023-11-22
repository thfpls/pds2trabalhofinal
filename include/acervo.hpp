#ifndef ACERVO_HPP
#define ACERVO_HPP

#include <vector>
#include "Livro.hpp"

class AcervoBiblioteca {
public:
    // Adiciona um livro ao acervo
    void inserirLivro(const Livro& livro);

    // Lista todos os livros no acervo
    void verAcervo() const;

private:
    std::vector<Livro> acervo;
};

#endif // ACERVO_HPP
