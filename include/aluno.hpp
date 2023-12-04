#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "perfilUsuario.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

//@brief Classe que representa um Aluno, derivada da classe PerfilUsuario
 
 // A classe Aluno possui funcionalidades específicas para alunos,
 // como salvar informações no arquivo CSV, verificar se um aluno já existe
 // e realizar o cadastro de um novo aluno
class Aluno : public PerfilUsuario {
public:

     // @brief Construtor da classe Aluno.
     // @param nome O nome do aluno.
     // @param email O email do aluno.
     // @param matricula A matrícula do aluno.
    Aluno(const std::string& nome, const std::string& email, const int livros);

     // @brief Salva as informações do aluno no arquivo CSV
     // @return 0 em caso de sucesso, 1 em caso de erro.
    int salvarAluno() const;

  
     // @brief Verifica se um aluno com as mesmas informações já existe.
     // @return true se o aluno já existe, false caso contrário.
    bool alunoJaExiste() const;

 
     // @brief Realiza o cadastro de um novo aluno.
     // Solicita informações do usuário, verifica se o aluno já existe
     // e, se não existir, salva as informações no arquivo CSV.
    void cadastroAluno();
};

#endif // ALUNO_HPP
