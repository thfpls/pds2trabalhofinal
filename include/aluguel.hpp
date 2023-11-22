#include "livro.hpp"
#include "gerenciarAluguel.hpp"

#include <string>

class Aluguel {
  public:
  // @brief conferir se algum livro está alugado, checando com a função de livro.hpp
  void checarDisponibilidade (std:: string Titulo; std:: string Disponibilidade);

  // @brief alterar o status de ALUGADO para DISPONÍVEL, após um aluguel ser efetuado
  void mudarStatus (std:: string Titulo; std:: string Disponibilidade; std:: string Usuario;
  std:: string Prazo)

  private:
