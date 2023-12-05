#ifndef ACERVO_BIBLIOTECA_HPP
#define ACERVO_BIBLIOTECA_HPP

#include "const.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "livro.hpp"

/**
 * @brief Classe para gerenciar o acervo de uma biblioteca.
 *
 * A classe AcervoBiblioteca permite a inserção, visualização, busca e armazenamento
 * de livros em um acervo, utilizando um arquivo CSV como persistência.
 */
class AcervoBiblioteca {
public:
    void carregarAcervo(std::string nomeArquivo);
    void salvarAcervo(std::string nomeArquivo);
    /**
     * @brief Insere um novo livro no acervo.
     *
     * Permite ao usuário inserir um novo livro no acervo, verificando se o livro
     * já existe antes de adicioná-lo.
     */
    void inserirLivro();

    /**
     * @brief Exibe o acervo da biblioteca.
     *
     * Mostra no console os detalhes de todos os livros presentes no acervo.
     */
    void verAcervo() const;

    /**
     * @brief Busca por um livro no acervo com base no título.
     *
     * Solicita ao usuário o título do livro desejado e exibe as informações se encontrado.
     */
    void buscarLivro() const;

    Livro localizarLivro(const std::string titulo) const;

    void atualizarLivro(const Livro liv) ;


private:
    /**
     * @brief Armazena os livros presentes no acervo.
     */
    std::vector<Livro> acervo;

    /**
     * @brief Insere um livro no vetor acervo.
     *
     * @param titulo          O título do livro.
     * @param autor           O autor do livro.
     * @param anoPublicacao   O ano de publicação do livro.
     */
    void inserirNoVetor(std::string titulo, std::string autor, int anoPublicacao);
};

#endif // ACERVO_BIBLIOTECA_HPP
