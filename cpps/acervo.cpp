#include "acervo.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>

void AcervoBiblioteca::carregarAcervo(std::string nomeArquivo){
    std::ifstream arq(nomeArquivo);

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }
    acervo.clear();
    std::string linha;
    while (std::getline(arq, linha)) {
        Livro l("","",0);
	l.deCSV(linha);
	acervo.push_back(l);
    }

    arq.close();
    return;
}

void AcervoBiblioteca::salvarAcervo(std::string nomeArquivo){
    std::ofstream arquivoTemp(ARQLIVROTEMP);

    if (!arquivoTemp.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    for (auto& livro : acervo) {
      std::string linha = livro.paraCSV();
      arquivoTemp << linha << std::endl;
    }

    std::remove(nomeArquivo.c_str());
    std::rename(ARQLIVROTEMP,nomeArquivo.c_str());

    return;
}

void AcervoBiblioteca::inserirLivro() {
    using namespace std;

    Livro l1("","",0);
    l1.deCIN();
        
    // declara uma variavel booleana pra indicar se o livro ja existe
    bool existe = false;

    for (const auto& livro : this->acervo) {
      if (livro.getTitulo() == l1.getTitulo()){
	existe = true;
	break;
      }
    }
    if (!existe){
	acervo.push_back(l1);
	salvarAcervo(ARQLIVRO);
    }
    return;
}

void AcervoBiblioteca::verAcervo() const {
    if (acervo.empty()) {
        std::cout << "O acervo está vazio." << std::endl;
    } else {
        std::cout << "Acervo da Biblioteca:" << std::endl;
        for (auto& livro : this->acervo) {
	    std::string linha = livro.paraCSV();
            std::cout << linha << std::endl;
        }
    }
}

void AcervoBiblioteca::buscarLivro() const {
    using namespace std;

    // Declara variável para armazenar o título a ser buscado
    string titulo;
    std::cout << "Digite o título do livro a ser buscado: ";
    getline(std::cin, titulo);

    // Realiza a busca no acervo pelo título
    bool encontrado = false;
    for (auto& livro : acervo) {
        if (livro.getTitulo() == titulo) {
	    std::string linha = livro.paraCSV();
            // Exibe as informações do livro encontrado
            std::cout << "Livro encontrado no acervo:" << endl;
            std::cout << linha << std::endl;
            encontrado = true;
            break; // Para a busca após encontrar o primeiro livro com o título correspondente
        }
    }

    if (!encontrado) {
        std::cout << "Livro não encontrado no acervo." << endl;
    }
}

Livro AcervoBiblioteca::localizarLivro(const std::string titulo) const {
    using namespace std;

    // Realiza a busca no acervo pelo título
    bool encontrado = false;
    for (auto& livro : acervo) {
        if (livro.getTitulo() == titulo) {
            encontrado = true;
	    return livro;
        }
    }

    if (!encontrado) {
        std::cout << "Livro não encontrado no acervo." << endl;
    }

    Livro l1("","",0);
    return l1;
}

void AcervoBiblioteca::atualizarLivro(const Livro l) {
    using namespace std;
    string currtit = l.getTitulo();

    auto it = std::find_if(acervo.begin(), acervo.end(),
                           [currtit](const Livro& livro)
			   {return livro.getTitulo() == currtit;});
    bool encontrado = false;
    if (it!=acervo.end()){
      it->setTitulo(l.getTitulo()); 
      it->setAutor(l.getAutor()); 
      it->setAnoPublicacao(l.getAnoPublicacao()); 
      it->setDisponivel(l.getDisponivel());
      encontrado = true;
    }

    if (!encontrado) {
        std::cout << "Livro não encontrado no acervo." << endl;
    }

    return;
}

void AcervoBiblioteca::inserirNoVetor(std::string titulo, std::string autor, int anoPublicacao) {
    // Cria um objeto da classe Livro com os parâmetros
    Livro livro(titulo, autor, anoPublicacao);
    // Insere o objeto no final do vetor
    acervo.push_back(livro);
    // Imprime uma mensagem de confirmação
    std::cout << "Livro inserido no acervo com sucesso.\n";
};
