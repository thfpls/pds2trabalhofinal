#include "Acervo.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Acervo::inserirLivro() {
    using namespace std;

    // Declarado o objeto pro arquivo
    ifstream arquivo_in;

    // abre "acervo.csv" modo de input
    arquivo_in.open("acervo.csv", ios::in);

    // checa se abriu direitin
    if (arquivo_in.is_open())
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
        
           // declara um vetor pra armazenar as linhas do arquivo
        vector<string> linhas;

        // declara uma string pra armazenar uma linha do arquivo
        string linha;

        // le o arquivo e armazena as linhas no vetor
        while (getline(arquivo_in, linha, '\n'))
        {
            linhas.push_back(linha);
        }

        // fecha o arquivo de input
        arquivo_in.close();

        // declara uma variavel booleana pra indicar se o livro ja existe
        bool existe = false;

        // percorre o vetor de linhas
        for (int i = 0; i < linhas.size(); i++)
        {
            // declara um stringstream pra separar os campos do livro
            stringstream ss(linhas[i]);

            // declara um vetor pra armazenar os campos do livro
            vector<string> campos;

            // declara uma string pra armazenar um campo do livro
            string campo;

            // le o stringstream e armazena os campos no vetor
            while (getline(ss, campo, ','))
            {
                campos.push_back(campo);
            }

            // compara os campos do livro com os parametros do usuario
            if (campos[0] == titulo || campos[1] == autor || campos[2] == anoPublicacao)
            {
                // se algum campo for igual, o livro ja existe
                existe = true;

                // mostra uma mensagem de erro
                cout << "Erro: O livro ja existe no acervo.\n";

                // sai do loop
                break;
            }
        }

        if (!existe) {
        // Declarado o objeto pro arquivo
        ofstream arquivo;

        // abre "acervo.csv" modo de output e append(botar novo no arquivo)
    arquivo.open("acervo.csv", ios::out | ios::app);
        
    // checa se abriu direitin
    if (arquivo.is_open())
    {
        // declara variaveis pra estocar o input do user
        string titulo, autor, anoPublicacao;

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
        }
    return;
    }

void Acervo::verAcervo() const {
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

void Acervo::buscarLivro() const {
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
