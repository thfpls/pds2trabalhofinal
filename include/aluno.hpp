//aluno.hpp
#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "perfil_usuario.hpp"
#include <vector>
#include <string>

class Aluno : public Perfil_usuario {
private:
    std::string _matricula;
    std::vector < std::string> _livros_emprestados; //armazena os titulos dos livros emprestados

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula);

    const std::string& getMatricula() const;

    // Adicione métodos específicos de Aluno, se necessário

    void emprestarLivro(const std::string& titulo);
    void devolverLivro(const std::string& titulo);

    /////////////
    const std::vector <std::string > & getLivrosEmprestados() const; 

    int salvar_aluno(); 

    static void criarEsalvarNovoAluno();
};
#endif // ALUNO_HPP
