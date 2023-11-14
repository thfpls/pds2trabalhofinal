#include "usuario.h"

#include <string>

class Gerenciar_Usuario {
  public:
  /*
  * @brief deleta o usuario pelo id
  /*

  void Deletar_Perfil (std::string email);

  // verificar se existe algum perfil com esse email
  // se existir, passar por todo o arquivo onde vai ser armazenado os perfis existentes ate encontrar o email de entrada
  // quando encontrar, remover todos os livros que estão emprestados dos alugados e excluir todas as informações de cadastro desse perfil

  /*
  * @brief exibir o cadastro pelo id 
  /*

  char Exibir_Perfil (std::string email);

  //verificar se existe algum perfil com esse email
  //se existir, passar por todo o arquivo onde vai ser armazenado os perfis existentes ate encontrar o email de entrada
  //quando encontrar, imprimir todos os dados cadastrados na classe usuario desse perfil

  /*
  * @brief alterar os dados de um perfil
  /*

  bool Alterar_Perfil (std::string email,std::string nome,std::string livros_alugados);

  //verificar se existe algum perfil com o email de entrada
  //se existir, igualas todos os seus dados para os que entram na função acima

  /*
  * @brief imprimir todos os perfis
  /*

  char Imprimir_Perfis ();

  // imprimir todos os cadastros que estão guardados no arquivo

};
