#ifndef GERENCIAR_ALUGUEL_HPP
#define GERENCIAR_ALUGUEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include "aluguel.hpp"

/**
 * @brief Classe para gerenciar o aluguel de livros.
 *
 * Esta classe fornece funcionalidades para alugar, devolver, aumentar prazo,
 * definir multa e verificar a disponibilidade de livros.
 */
class GerenciarAluguel {
private:
    std::vector<Aluguel> carteira; ///< Lista de livros disponíveis para aluguel.

public:
    /**
     * @brief Aluga um livro específico.
     *
     * @param titulo O título do livro a ser alugado.
     */
    void alugarLivro(const std::string& titulo, const std::string& email);

    /**
     * @brief Devolve um livro previamente alugado.
     *
     * @param titulo O título do livro a ser devolvido.
     */
    void devolverLivro(const std::string& titulo);

    /**
     * @brief Aumenta o prazo de devolução de um livro.
     *
     * @param titulo O título do livro para o qual o prazo será aumentado.
     * @param dias   O número de dias a serem adicionados ao prazo de devolução.
     */
    void aumentarPrazo(const std::string& titulo, int dias);

    /**
     * @brief Define a multa para um livro específico.
     *
     * @param titulo O título do livro para o qual a multa será definida.
     * @param multa  O valor da multa a ser aplicada.
     */
    void definirMulta(const std::string& titulo, double multa);

    /**
     * @brief Verifica a disponibilidade de um livro.
     *
     * @param titulo O título do livro a ser verificado.
     * @return true se o livro estiver disponível, false caso contrário.
     */

     void carregarAluguel(std::string nomeArquivo);

     void listarAluguel(std::string nomeArquivo);

     void salvarAluguel(std::string nomeArquivo);
     
};

#endif // GERENCIAR_ALUGUEL_HPP
