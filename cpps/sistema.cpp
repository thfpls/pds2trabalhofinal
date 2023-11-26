#include "sistema.hpp"

Sistema::Sistema(){
  
}

void Sistema::inicia_sistema(){
std::cout << "Ola! Bem vindo, Administrador \n"
<< std:: endl;

  std::cout << "Se identifique:" // nao sei se isso é a melhor coisa, é pq na foto do theo tem cadastrar adm ou usuario primeiro 
  << std:: endl;

  Administrador::criarEsalvarNovoAdm();// vou ter q adaptar pra caso ja tenha cadastro 

  std::cout << "O que deseja fazer?"
  << std:: endl;

  menu_principal(); 
}

void Sistema::menu_principal() {
    int opções_menu_principal;
    std::cout << "1. Cadastrar Estudante \n"
        << std::endl;
    std::cout << "2. Buscar Livro \n"
        << std::endl;
    std::cout << "3. Ver Acervo \n"
        << std::endl;
    std::cout << "4. Configuracoes \n"
        << std::endl;
    std::cout << "5. Sair do programa \n"
        << std::endl;

    std::cin >> opções_menu_principal;



    switch (opções_menu_principal) {
    case 1:
        std::cout << "Cadastrar Estudante: \n"
            << std::endl;
        Aluno::CadastroAluno();
        break;

    case 2:
        std::cout << "Buscar Livro: \n"
            << std::endl;
        AcervoBiblioteca::verAcervo(); //acho que é isso CONFERIR
        break;
    case 3:
        std::cout << "Ver Acervo: \n"
            << std::endl;
        //chama a função e interface de busca
        break;
    case 4: //nao sei se vai existir
        break;
    case 5:
        // sair do programa; 
        break;
     default:// colocar pra voltar no menu principal
    }
}

void Sistema::menu_de_busca() {
    int opções_pós_busca;
    std::cout << "1. Alugar livro \n"
        << std::endl;
    std::cout << "2. Alterar dado do livro \n"
        << std::endl;
    std::cout << "3. Realizar outra busca \n"
        << std::endl;
    std::cout << "4. Voltar ao menu principal \n"
        << std::endl;
  
    std::cin >> opções_pós_busca;

  switch (opções_pós_busca){
    case 1:
    std::cout << "Alugar livro: \n"
        << std::endl;
    GerenciarAluguel::alugarLivro()// Vai dar problema, pensar como vai colocar 

    case 2:
    std::cout << "Alterar dado do livro: \n"
    << std::endl;
    
}
