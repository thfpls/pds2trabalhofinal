#ifndef ACERVO_HPP
#define ACERVO_HPP

#include <vector>
#include "livro.hpp"

class AcervoBiblioteca {
public:
    // Adiciona um livro ao acervo (para o csv e para o vetor no runtime)
    void inserirLivro();

    // Lista todos os livros no acervo
    void verAcervo() const;

private:
    std::vector<Livro> acervo;
};

#endif // ACERVO_HPP
