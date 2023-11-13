#include "usuario.h"

#include <string>

class Gerenciar_usuario {
  public:
  /*
  * @brief deleta o usuario pelo id
  /*

  void deletar_perfil (std::string email);

  // verificar se existe algum perfil com esse email
  // se existir, passar por todo o arquivo onde vai ser armazenado os perfis existentes ate encontrar o email de entrada
  // quando encontrar, remover todos os livros que estão emprestados dos alugados e excluir todas as informações de cadastro desse perfil

  /*
  * @brief exibir o cadastro pelo id 
  /*

  char exibir_perfil (std::string email);

  //verificar se existe algum perfil com esse email
  //se existir, passar por todo o arquivo onde vai ser armazenado os perfis existentes ate encontrar o email de entrada
  //quando encontrar, imprimir todos os dados cadastrados na classe usuario desse perfil

  /*
  * @brief alterar os dados de um perfil
  /*

  bool alterar_perfil (std::string email);
