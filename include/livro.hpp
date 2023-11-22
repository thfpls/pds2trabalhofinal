#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro {
public:
    Livro(const std::string& titulo, const std::string& autor, int anoPublicacao);

    // @brief informações necessárias que o livro terá
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAnoPublicacao() const;
    bool estaAlugado() const;
    std::string getStatus() const;

    // @brief funções de alteração dos dados existentes de um livro
    void alterarLivro(const std::string& novoTitulo, const std::string& novoAutor, int novoAnoPublicacao);

private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
    bool alugado;
};

#endif // LIVRO_HPP
