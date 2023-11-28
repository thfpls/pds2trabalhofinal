#include "gerenciarAluguel.hpp"

void GerenciarAluguel::alugarLivro(const std::string& titulo, const std::string& disponibilidade) {
    // Cria uma chave para o livro usando título e disponibilidade
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    // Adiciona o livro ao mapa de livros alugados com prazo de devolução inicial de 7 dias e multa inicial de 0
    livrosAlugados[chaveLivro] = std::make_pair(7, 0.0);

    std::cout << "Livro '" << titulo << "' alugado com sucesso." << std::endl;
}

void GerenciarAluguel::devolverLivro(const std::string& titulo, const std::string& disponibilidade) {
    // Criação de  uma chave para o livro usando título e disponibilidade
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    // Verificação de se o livro está presente no mapa
    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        // Remove o livro do mapa
        livrosAlugados.erase(it);
        std::cout << "Livro '" << titulo << "' devolvido com sucesso." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}

void GerenciarAluguel::aumentarPrazo(const std::string& titulo, const std::string& disponibilidade, int dias) {
    // Criação de uma chave para o livro usando título e disponibilidade
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    // Verifica se o livro está presente no mapa
    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        // Aumenta o prazo de devolução
        it->second.first += dias;
        std::cout << "Prazo de devolução do livro '" << titulo << "' aumentado para " << it->second.first << " dias." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, const std::string& disponibilidade, double multa) {
    // Criação de uma chave para o livro usando título e disponibilidade
    std::pair<std::string, std::string> chaveLivro = std::make_pair(titulo, disponibilidade);

    // Verificação de se o livro está presente no mapa
    auto it = livrosAlugados.find(chaveLivro);
    if (it != livrosAlugados.end()) {
        // Define a multa para o livro
        it->second.second = multa;
        std::cout << "Multa para o livro '" << titulo << "' definida como " << multa << "." << std::endl;
    } else {
        std::cout << "Livro '" << titulo << "' não encontrado no sistema de aluguel." << std::endl;
    }
}
