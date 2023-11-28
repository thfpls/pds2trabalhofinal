#include "acervo.hpp"
#include <iostream>
#include <fstream>

void AcervoBiblioteca::inserirLivro(const Livro& livro) {
    using namespace std;

    // Declarado o objeto pro arquivo
    ofstream arquivo;

    // abre "acervo.csv" modo de output e append(botar novo no arquivo)
    arquivo.open("acervo.csv", ios::out | ios::app);

    // checa se abriu direitin
    if (arquivo.is_open())
    {
        // declara variaveis pra estocar o input do user
        string titulo, autor, anoPublicacao;

        // Prompt o usuario a botar dados
        cout << "Digite o titulo do livro: ";
        getline(cin, titulo);
        cout << "Digite o nome do autor do livro: ";
        getline(cin, autor);
        cout << "Digite o ano de publicacao do livro: ";
        getline(cin, anoPublicacao);

        // bota o livro no arquivo csv
        arquivo << titulo << ", " << autor << ", " << anoPublicacao << ", " << "1" << "\n";

        // fecha o arquivo
        arquivo.close();

        //bota o livro no runtime
        Livro livro (titulo, autor, anoPublicacao);
        acervo.push_back(livro);
        // atesta o sucesso
        cout << "Livro inserido no acervo com sucesso.\n";
    }
    else
    {
        // mostra erro
        cout << "Erro: Não foi possível abrir o arquivo.\n";
    }

    return 0;
}

void AcervoBiblioteca::verAcervo() const {
    if (acervo.empty()) {
        std::cout << "O acervo está vazio." << std::endl;
    } else {
        std::cout << "Acervo da Biblioteca:" << std::endl;
        for (const auto& livro : acervo) {
            std::cout << "Título: " << livro.getTitulo() << ", Autor: " << livro.getAutor()
                      << ", Ano: " << livro.getAnoPublicacao() << ", Estado: "
                      << (livro.estaAlugado() ? "Alugado" : "Disponível") << std::endl;
        }
    }
}

void AcervoBiblioteca::buscarLivro() const {
    using namespace std;

    // Declara variável para armazenar o título a ser buscado
    string titulo;
    cout << "Digite o título do livro a ser buscado: ";
    getline(cin, titulo);

    // Realiza a busca no acervo pelo título
    bool encontrado = false;
    for (const auto& livro : acervo) {
        if (livro.getTitulo() == titulo) {
            // Exibe as informações do livro encontrado
            cout << "Livro encontrado no acervo:" << endl;
            cout << "Título: " << livro.getTitulo() << ", Autor: " << livro.getAutor()
                 << ", Ano: " << livro.getAnoPublicacao() << ", Estado: "
                 << (livro.estaAlugado() ? "Alugado" : "Disponível") << endl;

            encontrado = true;
            break; // Para a busca após encontrar o primeiro livro com o título correspondente
        }
    }

    if (!encontrado) {
        cout << "Livro não encontrado no acervo." << endl;
    }
}
