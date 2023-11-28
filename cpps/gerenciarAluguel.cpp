#include "gerenciarAluguel.hpp"

std::map<std::pair<std::string, std::string>, std::pair<int, double>> GerenciarAluguel::livrosAlugados;

void GerenciarAluguel::alugarLivro(const std::string& titulo, const std::string& disponibilidade) {
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);
    livrosAlugados[chaveLivro] = std::make_pair(7, 0.0);

    std::cout << "Livro '" << titulo << "' alugado com sucesso." << std::endl;
}

void GerenciarAluguel::devolverLivro(const std::string& titulo, const std::string& disponibilidade) {
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        livrosAlugados.erase(it);
        std::cout << "Livro '" << titulo << "' devolvido com sucesso." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}

void GerenciarAluguel::aumentarPrazo(const std::string& titulo, const std::string& disponibilidade, int dias) {
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        it->second.first += dias;
        std::cout << "Prazo de devolução do livro '" << titulo << "' aumentado para " << it->second.first << " dias." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, const std::string& disponibilidade, double multa) {
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        it->second.second = multa;
        std::cout << "Multa para o livro '" << titulo << "' definida como " << multa << "." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}
