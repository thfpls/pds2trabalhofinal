#include "sistema.hpp"
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <limits>

//Sistema::Sistema(){}

void Sistema::inicia_sistema(){
  
  std::cout << "Ola! Bem vindo, Administrador \n" << std:: endl;

  std::cout << "Se identifique:" << std::endl; 

  Administrador adm("","", 0);

  //adm.cadastroAdm();// vou ter q adaptar pra caso ja tenha cadastro 

  std::cout << "O que deseja fazer?" << std:: endl;

  menu_principal(); 
}

void Sistema::menu_principal() {
    int opcoes_menu_principal=0;
    while(opcoes_menu_principal!=4){
      std::cout << "Menu Principal \n" << std::endl;
      std::cout << "1. Gerenciar Aluno \n" << std::endl;
      std::cout << "2. Gerenciar Livro \n" << std::endl;
      std::cout << "3. Gerenciar Aluguel\n" << std::endl;
      std::cout << "4. Sair do programa \n" << std::endl;
      std::cin >> opcoes_menu_principal;

      switch (opcoes_menu_principal) {
      case 1:
          std::cout << "Gerenciar Aluno: \n" << std::endl;
          menu_aluno();
          break;
      case 2:
          std::cout << "Gerenciar Livro: \n" << std::endl;
	  menu_livro();
          break;
      case 3:
          std::cout << "Gerenciar Aluguel: \n" << std::endl;
	  menu_aluguel();
          break;
      }
    }
}

void Sistema::menu_aluno() {
  int opcoes_menu_aluno = 0;
  std::string email;
  GerenciarUsuario gu;
  while(opcoes_menu_aluno !=4){
    std::cout << "Menu Aluno: \n" << std::endl;
    std::cout << "1. Inserir Aluno \n" << std::endl;
    std::cout << "2. Remover Aluno \n" << std::endl;
    std::cout << "3. Listar Alunos \n" << std::endl;
    std::cout << "4. Menu principal \n" << std::endl;
    std::cin >> opcoes_menu_aluno;
    switch (opcoes_menu_aluno) {
      case 1:
        std::cout << "Inserir Aluno \n\n" << std::endl;
        gu.carregarUsuarios(ARQUSUARIO);
        gu.inserirUsuario();
        gu.salvarUsuarios(ARQUSUARIO);
      break;
      case 2:
        std::cout << "Remover Aluno \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o email do usuario a remover \n" << std::endl;
        getline(std::cin,email);
	gu.deletarPerfil(email);
      break;
      case 3:
        std::cout << "Listar Alunos \n\n" << std::endl;
        gu.carregarUsuarios(ARQUSUARIO);
        gu.imprimirPerfis();
      break;
    }
  }
  return;
}

void Sistema::menu_livro() {
  std::string titulo;
  Livro l1("","",0);
  AcervoBiblioteca ac;
  int opcoes_menu_livro = 0;
  while(opcoes_menu_livro !=4){
    std::cout << "Menu Livro: \n" << std::endl;
    std::cout << "1. Inserir Livro \n" << std::endl;
    std::cout << "2. Localizar Livro \n" << std::endl;
    std::cout << "3. Listar Livros \n" << std::endl;
    std::cout << "4. Menu principal \n" << std::endl;
    std::cin >> opcoes_menu_livro;

    switch (opcoes_menu_livro) {
      case 1:
        std::cout << "Inserir Livro \n\n" << std::endl;
        ac.carregarAcervo(ARQLIVRO); 
	ac.inserirLivro();
	ac.salvarAcervo(ARQLIVRO);
      break;
      case 2:
        std::cout << "Localizar Livro \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o titulo do livro a localizar \n" << std::endl;
        getline(std::cin,titulo);
        ac.carregarAcervo(ARQLIVRO); 
        l1 = ac.localizarLivro(titulo);
	std::cout << l1.paraCSV() << std::endl;
      break;
      case 3:
        std::cout << "Listar Livros \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ac.carregarAcervo(ARQLIVRO); 
        ac.verAcervo();
      break;
    }
  }
  return;
}

void Sistema::menu_aluguel() {
  GerenciarAluguel ga;
  std::string titulo, email,aux;
  int dias;
  double multa;
  int opcoes_menu_aluguel = 0;
  while(opcoes_menu_aluguel !=6){
    std::cout << "Menu Aluguel: \n" << std::endl;
    std::cout << "1. Alugar Livro \n" << std::endl;
    std::cout << "2. Devolver Livro \n" << std::endl;
    std::cout << "3. Listar Alugueis \n" << std::endl;
    std::cout << "4. Estender Prazo Devolucao \n" << std::endl;
    std::cout << "5. Aplicar Multa \n" << std::endl;
    std::cout << "6. Menu principal \n" << std::endl;
    std::cin >> opcoes_menu_aluguel;

    switch (opcoes_menu_aluguel) {
      case 1:
        std::cout << "Alugar Livro \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o titulo do livro a alugar \n" << std::endl;
        getline(std::cin,titulo);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o email do usuario \n" << std::endl;
        getline(std::cin,email);
        ga.alugarLivro(titulo,email); 
      break;
      case 2:
        std::cout << "Devolver Livro \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o titulo do livro a devolver \n" << std::endl;
        getline(std::cin,titulo);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ga.devolverLivro(titulo); 
      break;
      case 3:
        std::cout << "Listar Alugueis \n\n" << std::endl;
        ga.listarAluguel(ARQALUGUEL);
      break;
      case 4:
        std::cout << "Estender Prazo Devolucao \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o titulo do livro a estender prazo\n"<<std::endl;
        getline(std::cin,titulo);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o numero de dias\n"<<std::endl;
        getline(std::cin,aux);
	dias = std::stoi(aux);
        ga.aumentarPrazo(titulo,dias); 
      break;
      case 5:
        std::cout << "Aplicar Multa \n\n" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o titulo do livro a aplicar multa\n"<<std::endl;
        getline(std::cin,titulo);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Digite o valor da multa\n"<<std::endl;
        getline(std::cin,aux);
	multa = std::stod(aux);
        ga.definirMulta(titulo,multa); 
      break;
    }
  }
  return;
}

