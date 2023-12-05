#ifndef ALUGUELHPP
#define ALUGUELHPP

#include "livro.hpp"
#include "acervo.hpp" 

#include <string>

class Aluguel {
public:

  Aluguel(std::string titulo, std::string email);

  void definirPrazo(int dias);  
  void aumentarPrazo(int dias);  
  void definirMulta(double multa);
  int getPrazoDevolucao();
  std::string getTitulo() const;

  void deCSV(const std::string& linha);

  std::string paraCSV() const;

private:
  int prazo;
  double multa;
  std::string titulo;
  std::string email;
};

#endif
