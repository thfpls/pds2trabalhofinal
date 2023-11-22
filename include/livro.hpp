#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>

class Livro {
public:
    Livro(const std::string titulo, const std::string autor, int anoPublicacao);

    // Métodos de acesso
    std::string getTitulo() const;
    std::string getAutor() const;
    int getAnoPublicacao() const;
    bool estaAlugado() const;

    // Métodos de modificação
    void alugar();
    void devolver();

private:
    std::string titulo;
    std::string autor;
    int anoPublicacao;
    bool alugado;
};

#endif // LIVRO_HPP
