
#include "gerenciarAluguel.hpp"

std::vector<Livro> GerenciarAluguel::livros;

void GerenciarAluguel::aumentarPrazo(const std::string& titulo, int dias) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo && livro.estaAlugado();
    });

    if (it != livros.end()) {
        it->aumentarPrazo(dias);
        std::cout << "Prazo de devolução do livro '" << titulo << "' aumentado para " << it->getPrazoDevolucao() << " dias." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado ou não está alugado." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, double multa) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo && livro.estaAlugado();
    });

    if (it != livros.end()) {
        it->definirMulta(multa);
        std::cout << "Multa para o livro '" << titulo << "' definida como " << multa << "." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado ou não está alugado." << std::endl;
    }
}
