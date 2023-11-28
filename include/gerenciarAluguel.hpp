#ifndef GERENCIAR_ALUGUEL_HPP
#define GERENCIAR_ALUGUEL_HPP

#include <iostream>
#include <map>
#include <string>

class GerenciarAluguel {
public:
    //mapa que guarda os livros alugados
    static std::map<std::pair<std::string, std::string>, std::pair<int, double>> livrosAlugados;

    //aloca um livro, considerando seu título e conferindo sua disponibilidade - adiciona aos alugados
    static void alugarLivro(const std::string& titulo, const std::string& disponibilidade);

    //aloca um livro, considerando seu título e sua disponibilidade - remove do mapa de alugados
    static void devolverLivro(const std::string& titulo, const std::string& disponibilidade);

    //muda o valor do prazo de aluguel de um livro
    static void aumentarPrazo(const std::string& titulo, const std::string& disponibilidade, int dias);

    //difine uma multa baseado no prazo estipulado
    static void definirMulta(const std::string& titulo, const std::string& disponibilidade, double multa);

};

#endif // GERENCIAR_ALUGUEL_HPP
