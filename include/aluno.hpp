// aluno.hpp
#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "perfilUsuario.hpp"
#include <vector>
#include <string>

class Aluno : public PerfilUsuario {
private:
    std::string _matricula;
    std::vector<std::string> _livros_emprestados;

public:
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula);

    const std::string& getMatricula() const;
    const std::vector<std::string>& getLivrosEmprestados() const;

    int salvarAluno() const;
    bool alunoJaExiste() const;

    static void cadastroAluno();
};

#endif // ALUNO_HPP
