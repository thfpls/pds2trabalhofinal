#include "livro.hpp"
#include "acervo.hpp"
#include <iostream>

Livro::Livro(const std::string& titulo, const std::string& autor, int anoPublicacao)
    : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao), disponivel(true) {}

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
    return disponivel;
}



void Livro::alterarLivro() {
    using namespace std;

    // Declara variável para armazenar o título do livro a ser alterado
    string titulo;
    cout << "Digite o título do livro a ser alterado: ";
    getline(cin, titulo);

    // Realiza a busca no acervo pelo título
    auto it = std::find_if(acervo.begin(), acervo.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != acervo.end()) {
        // Livro encontrado, solicita as novas informações
        string novoTitulo, novoAutor;
        int novoAnoPublicacao;

        cout << "Digite o novo título: ";
        getline(cin, novoTitulo);
        cout << "Digite o novo autor: ";
        getline(cin, novoAutor);
        cout << "Digite o novo ano de publicacao: ";
        cin >> novoAnoPublicacao;

        // Limpa o buffer do teclado após a leitura do ano
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Altera as informações do livro
        it->alterarLivro(novoTitulo, novoAutor, novoAnoPublicacao);

        cout << "Livro alterado com sucesso." << endl;
    } else {
        cout << "Livro não encontrado no acervo." << endl;
    }
}
