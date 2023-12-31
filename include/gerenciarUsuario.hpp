#include "const.hpp"
#include "perfilUsuario.hpp"
#include <string>
#include <vector>

class GerenciarUsuario {
  public:

  void carregarUsuarios(std::string nomeArquivo);

  void salvarUsuarios(std::string nomeArquivo);

  void inserirUsuario();

  PerfilUsuario localizarUsuario(std::string email);
  
  // @brief deleta o usuario pelo id
  // @param email do usuario

  void deletarPerfil (std::string _email);

  // verificar se existe algum perfil com esse email
  // se existir, passar por todo o arquivo onde vai ser armazenado os perfis existentes ate encontrar o email de entrada
  // quando encontrar, remover todos os livros que estão emprestados dos alugados e excluir todas as informações de cadastro desse perfil 

  // @brief alterar os dados de um perfil
  // @param email, nome, livros alugados do usuário

  void alterarPerfil (const std::string& email, const std::string& novoNome, const int novosLivrosAlugados);

  //verificar se existe algum perfil com o email de entrada
  //se existir, igualas todos os seus dados para os que entram na função acima

  // @brief imprimir todos os perfis

  void imprimirPerfis ();

private:

std::vector<PerfilUsuario> usuarios;

};
