#include <list>
#include <string>
#include <vector>

#include "perfil_de_usuario"

class Aluno : public Perfil_usuario
{
private:
    std::vector<Exemplar *> livros_com_aluno;

public:
   //Constroi um aluno.
    Aluno(std::string email);

    virtual ~Aluno();

     *// @brief Mostra todos os livros emprestados.
    void get_livros_com_aluno();

     //@brief Pega o numero de livros que o aluno possui.
    int get_n_exemplares();

    void consultar_acervo(std::string) override;

    int salvar_aluno_no_arquivo();

    void imprime_aluno();

};

#endif
