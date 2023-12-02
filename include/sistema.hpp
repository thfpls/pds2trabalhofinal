#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "administrador.hpp"
#include "aluno.hpp"
#include "acervo_biblioteca.hpp"
#include "gerenciar_aluguel.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

/**
 * @brief Classe que representa o sistema da biblioteca.
 */
class Sistema {
public:
    /**
     * @brief Construtor padrão da classe Sistema.
     */
    Sistema();

     /**
     * @brief Carrega o vetor de livros a partir de um arquivo CSV.
     */
    void carregarVetor();

    /**
     * @brief Inicializa o sistema.
     */
    void inicia_sistema();

    /**
     * @brief Exibe o menu principal e processa as opções escolhidas pelo usuário.
     */
    void menu_principal();

    /**
     * @brief Exibe o menu de busca após a realização de uma busca por livro.
     */
    void menu_de_busca();

private:
    /**
     * @brief Adiciona um livro ao vetor de livros.
     *
     * @param titulo Título do livro.
     * @param autor Autor do livro.
     * @param ano Ano de publicação do livro.
     */
    void botarNoVetor(const std::string& titulo, const std::string& autor, int ano);
};

#endif // SISTEMA_HPP
