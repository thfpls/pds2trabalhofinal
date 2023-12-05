#include "aluguel.hpp"
#include "livro.hpp"
#include "acervo.hpp"

Aluguel::Aluguel(std::string titulo, std::string email)
    : prazo(1), multa(0.0),titulo(titulo), email(email) {}

void Aluguel::definirPrazo(int dias) {
    prazo = dias;
}

void Aluguel::aumentarPrazo(int dias) {
    prazo += dias;
}

void Aluguel::definirMulta(double novaMulta) {
    multa = novaMulta;
}

int Aluguel::getPrazoDevolucao() {
    return prazo;
}

std::string Aluguel::getTitulo() const{
     return titulo;
}

void Aluguel::deCSV(const std::string& linha){
  std::istringstream ss(linha);
  std::string aux;

  //std::cout << "deCSV "<< linha << std::endl;
  std::getline(ss,titulo,',');
  std::getline(ss,email,',');
  std::getline(ss,aux,',');
  prazo = std::stoi(aux);
  std::getline(ss,aux,',');
  multa = std::stod(aux);
}

std::string Aluguel::paraCSV() const{
  std::ostringstream oss;

  oss << titulo << ", "
      << email << ", "
      << prazo << ", "
      << multa;

  return oss.str();
}

