#include "Livro.hpp"

Livro::Livro(const std::string& titulo, const std::string& autor, int anoPublicacao)
    : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao), alugado(false) {}

std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

bool Livro::estaAlugado() const {
    return alugado;
}

void Livro::alterarLivro(const std::string& novoTitulo, const std::string& novoAutor, int novoAnoPublicacao) {
    titulo = novoTitulo;
    autor = novoAutor;
    anoPublicacao = novoAnoPublicacao;
}

void Livro::alugar() {
    alugado = true;
}

void Livro::devolver() {
    alugado = false;
}
