#include "sistema.hpp"
#include <vector>
#include <sstream>
#include <string>

Sistema::Sistema(){
  
}

void Sistema::carregarVetor() {
        ifstream arquivo_in;
        arquivo_in.open("acervo.csv", ios::in);

        // checa se abriu direitin
        if (arquivo_in.is_open()) {
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
            botarNoVetor(campos[0], campos[1], stoi(campos[2]));
        }
        }
        else
    {
        // mostra erro
        cout << "Erro: Não foi possível abrir o arquivo.\n";
    }
}

void Sistema::inicia_sistema(){
  
carregarVetor();
  
std::cout << "Ola! Bem vindo, Administrador \n"
<< std:: endl;

  std::cout << "Se identifique:" // nao sei se isso é a melhor coisa, é pq na foto do theo tem cadastrar adm ou usuario primeiro 
  << std:: endl;

  Administrador::cadastroAdm();// vou ter q adaptar pra caso ja tenha cadastro 

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
    std::cout << "4. Inserir Livro \n"
        << std::endl;
    std::cout << "5. Sair do programa \n"
        << std::endl;

    std::cin >> opções_menu_principal;

    switch (opções_menu_principal) {
    case 1:
        std::cout << "Cadastrar Estudante: \n"
        << std::endl;
        Aluno::cadastroAluno();
        menu_principal(); 
        break;
    case 2:
        std::cout << "Buscar Livro: \n"
        << std::endl;
        //rever essa busca
        break;
    case 3:
        std::cout << "Ver Acervo: \n"
        << std::endl;
        AcervoBiblioteca::verAcervo(); 
         menu_principal(); 
        break;
    case 4: 
      std::cout << "Inseriri Livro: \n"
        << std::endl;
      
      //nao sei se vai existir
        break;
    case 5:
        // sair do programa; 
        break;
     default:// colocar pra voltar no menu principal
    }
}

void Sistema::menu_de_busca() { //essa função vai estar após a busca de um livro
    int opções_pós_busca;
    std::cout << "1. Alugar livro \n"
        << std::endl;
    std::cout << "2. Alterar dados do livro \n"
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
    GerenciarAluguel::alugarLivro()// nao vai funcionar so colocar essa função aqui 

    case 2:
    std::cout << "Alterar dado do livro: \n"
    << std::endl;
    Livro::alterarLivro(); //nao vai funcionar so colocar essa função aqui 

    case 3:
     std::cout << "Realizar outra busca: \n"
    << std::endl;
    AcervoBiblioteca::verAcervo(); //rever essa busca
    
}
