#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <iostream>
#include <string>

/**
 * @brief Representa um objeto Livro.
 *
 * Esta classe encapsula informações sobre um livro, incluindo título, autor,
 * ano de publicação e disponibilidade de aluguel.
 */
class Livro {
public:
    /**
     * @brief Construtor da classe Livro.
     *
     * @param titulo           O título do livro.
     * @param autor            O autor do livro.
     * @param anoPublicacao    O ano de publicação do livro.
     */
    Livro(const std::string& titulo, const std::string& autor, int anoPublicacao);

    /**
     * @brief Obtém o título do livro.
     *
     * @return O título do livro.
     */
    std::string getTitulo() const;

    /**
     * @brief Obtém o autor do livro.
     *
     * @return O autor do livro.
     */
    std::string getAutor() const;

    /**
     * @brief Obtém o ano de publicação do livro.
     *
     * @return O ano de publicação do livro.
     */
    int getAnoPublicacao() const;
    bool getDisponivel() const;

    void setTitulo(const std::string novotitulo);
    void setAutor(const std::string novoautor);
    void setAnoPublicacao(const int novoano);
    void setDisponivel(const bool disp);

    /**
     * @brief Verifica se o livro está disponível para aluguel.
     *
     * @return true se o livro estiver disponível, false caso contrário.
     */
    bool estaAlugado() const;

    /**
     * @brief Altera as informações do livro.
     *
     * @param novoTitulo        O novo título do livro.
     * @param novoAutor         O novo autor do livro.
     * @param novoAnoPublicacao O novo ano de publicação do livro.
     */
    void alterarLivro(const std::string& novoTitulo, const std::string& novoAutor, int novoAnoPublicacao);

    /**
     * @brief Marca o livro como alugado.
     */
    void alugar();

    /**
     * @brief Marca o livro como disponível para aluguel.
     */
    void devolver();

    void deCSV(const std::string& linha);

    void deCIN();

    std::string paraCSV () const;

private:
    std::string titulo;          ///< O título do livro.
    std::string autor;           ///< O autor do livro.
    int anoPublicacao;           ///< O ano de publicação do livro.
    bool disponivel;             ///< Indica se o livro está disponível para aluguel.
};

#endif // LIVRO_HPP
