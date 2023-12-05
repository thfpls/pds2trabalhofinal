#include "livro.hpp"
#include "acervo.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

Livro::Livro(const std::string& titulo, const std::string& autor, int anoPublicacao)
    : titulo(titulo), autor(autor), anoPublicacao(anoPublicacao), disponivel(true) {}

void Livro::alugar() {
    if (!disponivel) {
        std::cout << "Livro indisponível para aluguel." << std::endl;
    } else {
        disponivel = false;
        // GerenciarAluguel::alugarLivro(titulo);  // Adiciona o livro à lista de livros alugados
        std::cout << "Livro alugado com sucesso." << std::endl;
    }
}

void Livro::devolver() {
    if (disponivel) {
        std::cout << "Livro já está disponível, não pode ser devolvido." << std::endl;
    } else {
        disponivel = true;
        //GerenciarAluguel::devolverLivro(titulo);  // Remove o livro da lista de livros alugados
        std::cout << "Livro devolvido com sucesso." << std::endl;
    }
}

std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

int Livro::getAnoPublicacao() const {
    return anoPublicacao;
}

bool Livro::getDisponivel() const {
    return disponivel;
}


void Livro::setTitulo(const std::string novotitulo) {
    titulo = novotitulo;
    return;
}

void Livro::setAutor(const std::string novoautor) {
    autor = novoautor;
    return;
}

void Livro::setAnoPublicacao(const int novoano) {
    anoPublicacao = novoano;
    return;
}

void Livro::setDisponivel(const bool disp) {
    disponivel = disp;
    return;
}

bool Livro::estaAlugado() const {
    return !disponivel;
}

void Livro::alterarLivro(const std::string& novoTitulo, const std::string& novoAutor, int novoAnoPublicacao) {
    using namespace std;

    titulo = novoTitulo;
    autor = novoAutor;
    anoPublicacao = novoAnoPublicacao;

    cout << "Livro alterado com sucesso." << endl;
}

void Livro::deCSV(const std::string& linha){
  std::istringstream ss(linha);
  std::string aux;

  std::getline(ss,titulo,',');
  std::getline(ss,autor,',');
  std::getline(ss,aux,',');
  anoPublicacao = std::stoi(aux);
  std::getline(ss,aux,',');
  //remover espacos em branco
  aux.erase(std::remove_if(aux.begin(), aux.end(), ::isspace), aux.end());
  disponivel = (aux == "D" ? true : false); 
}

std::string Livro::paraCSV() const{
  std::ostringstream oss;

  oss << titulo << ", "
      << autor << ", "
      << anoPublicacao << ", "
      << (disponivel ? "D" : "I");

  return oss.str();
}

void Livro::deCIN(){
  using namespace std;
  string aux;

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cout << "Digite o título: ";
  getline(cin, titulo);
  cout << "Digite o autor: ";
  getline(cin, autor);
  cout << "Digite o ano de publicacao: ";
  if (cin >> anoPublicacao){
    disponivel = true;
  } else {
    std::cout << "Ano invalido" << std::endl;
  }
  std::cin.get();
}
