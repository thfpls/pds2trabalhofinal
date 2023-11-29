// gerenciarAluguel.cpp
#include "gerenciarAluguel.hpp"
#include <iostream>
#include <algorithm>

std::vector<Livro> GerenciarAluguel::livros;

void GerenciarAluguel::alugarLivro(const std::string& titulo) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        if (!it->estaAlugado()) {
            it->alugar();
            std::cout << "Livro alugado com sucesso." << std::endl;
        } else {
            std::cout << "Livro indisponível para aluguel, já está alugado." << std::endl;
        }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::devolverLivro(const std::string& titulo) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        if (it->estaAlugado()) {
            it->devolver();
            std::cout << "Livro devolvido com sucesso." << std::endl;
        } else {
            std::cout << "Livro não está alugado, não pode ser devolvido." << std::endl;
        }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::aumentarPrazo(const std::string& titulo, int dias) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        it->aumentarPrazo(dias);
        std::cout << "Prazo aumentado com sucesso." << std::endl;
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, double multa) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        it->definirMulta(multa);
        std::cout << "Multa definida com sucesso." << std::endl;
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

bool GerenciarAluguel::checarDisponibilidade(const std::string& titulo) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        return !it->estaAlugado();
    } else {
        std::cout << "Livro não encontrado." << std::endl;
        return false;
    }
}
