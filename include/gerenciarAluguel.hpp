#ifndef GERENCIAR_ALUGUEL_HPP
#define GERENCIAR_ALUGUEL_HPP

#include <map>
#include <string>
#include <iostream>

class GerenciarAluguel {
public:
    // Adiciona um livro ao mapa de livros alugados
    void alugarLivro(const std::string& titulo, const std::string& disponibilidade);

    // Remove um livro do mapa de livros alugados
    void devolverLivro(const std::string& titulo, const std::string& disponibilidade);

    // Aumenta o prazo de devolução para um livro específico
    void aumentarPrazo(const std::string& titulo, const std::string& disponibilidade, int dias);

    // Define uma multa para um livro específico
    void definirMulta(const std::string& titulo, const std::string& disponibilidade, double multa);

private:
    // Mapa para armazenar livros alugados, a chave é uma combinação de título e disponibilidade
    std::map<std::pair<std::string, std::string>, std::pair<int, double>> livrosAlugados;
};

#endif // GERENCIAR_ALUGUEL_HPP
