// aluno.hpp
#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "perfil_usuario.hpp"
#include <vector>
#include <string>

class Aluno : public Perfil_usuario {
private:
    std::string _matricula;
    std::vector<std::string> _livros_emprestados;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula);

    const std::string& getMatricula() const;
    const std::vector<std::string>& getLivrosEmprestados() const;

    int salvar_aluno() const;
    bool alunoJaExiste() const;

    static void CadastroAluno();
};

#endif // ALUNO_HPP
