#include "sistema.hpp"

Sistema::Sistema(){
  
}

void Sistema::inicia_sistema(){
std::cout << "Ola! Bem vindo, Administrador \n"
<< std:: endl;

  std::cout << "O que deseja fazer?"
  << std:: endl;

  carregar_opcoes(); 
}

void Sistema::carregar_opcoes(){
  int entrada_opcoes; 
  std::cout << "1. Cadastrar Estudante \n"
  << std:: endl;
  std::cout << "2. Buscar Livro \n" 
  << std::endl;
  std::cout << "3. Ver Acervo \n"
  << std:: endl;
  std::cout << "4. Configuracoes \n"
  << std:: endl;

  std::cin >> entrada_opcoes;
  
  switch(entrada_opcoes){
    case 1: 
    std::cout << "Cadastrar Estudante \n" 
      << std::endl; 
    
}
