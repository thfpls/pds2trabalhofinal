#include "Acervo.hpp"
#include <iostream>
#include <fstreram>

void AcervoBiblioteca::inserirLivro(const Livro& livro) {
    acervo.push_back(livro);
}

void AcervoBiblioteca::verAcervo() const {
    if (acervo.empty()) {
        std::cout << "O acervo está vazio." << std::endl;
    } else {
        std::cout << "Acervo da Biblioteca:" << std::endl;
        for (const auto& livro : acervo) {
            std::cout << "Título: " << livro.getTitulo() << ", Autor: " << livro.getAutor()
                      << ", Ano: " << livro.getAnoPublicacao() << ", Estado: "
                      << (livro.estaAlugado() ? "Alugado" : "Disponível") << std::endl;
        }
    }
}
