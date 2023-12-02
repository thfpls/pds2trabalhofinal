#ifndef GERENCIAR_ALUGUEL_HPP
#define GERENCIAR_ALUGUEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include "livro.hpp"

/**
 * @brief Classe para gerenciar o aluguel de livros.
 *
 * Esta classe fornece funcionalidades para alugar, devolver, aumentar prazo,
 * definir multa e verificar a disponibilidade de livros.
 */
class GerenciarAluguel {
public:
    static std::vector<Livro> livros; ///< Lista de livros disponíveis para aluguel.

    /**
     * @brief Aluga um livro específico.
     *
     * @param titulo O título do livro a ser alugado.
     */
    static void alugarLivro(const std::string& titulo);

    /**
     * @brief Devolve um livro previamente alugado.
     *
     * @param titulo O título do livro a ser devolvido.
     */
    static void devolverLivro(const std::string& titulo);

    /**
     * @brief Aumenta o prazo de devolução de um livro.
     *
     * @param titulo O título do livro para o qual o prazo será aumentado.
     * @param dias   O número de dias a serem adicionados ao prazo de devolução.
     */
    static void aumentarPrazo(const std::string& titulo, int dias);

    /**
     * @brief Define a multa para um livro específico.
     *
     * @param titulo O título do livro para o qual a multa será definida.
     * @param multa  O valor da multa a ser aplicada.
     */
    static void definirMulta(const std::string& titulo, double multa);

    /**
     * @brief Verifica a disponibilidade de um livro.
     *
     * @param titulo O título do livro a ser verificado.
     * @return true se o livro estiver disponível, false caso contrário.
     */
};

#endif // GERENCIAR_ALUGUEL_HPP
