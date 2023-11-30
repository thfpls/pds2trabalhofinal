// aluno.hpp
#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "perfilUsuario.hpp"
#include <vector>
#include <string>

///@brief Classe que representa um Aluno, derivada da classe PerfilUsuario.
class Aluno : public PerfilUsuario {
private:
    std::string _matricula; 
    std::vector<std::string> _livros_emprestados; 

public:
    
     /// @brief Construtor da classe Aluno.
     /// @param nome Nome do Aluno.
     /// @param email E-mail do Aluno.
     /// @param matricula Matrícula do Aluno.
    Aluno(const std::string& nome, const std::string& email, const std::string& matricula);

     /// @brief Obtém a matrícula do Aluno.
     // @return Matrícula do Aluno.
    const std::string& getMatricula() const;
    
     /// @brief Obtém a lista de livros emprestados pelo Aluno.
     /// @return Lista de livros emprestados pelo Aluno
    const std::vector<std::string>& getLivrosEmprestados() const;

     /// @brief Salva as informações do Aluno em um arquivo CSV.
     /// @return 0 em caso de sucesso, -1 em caso de falha.
    int salvarAluno() const;

     /// @brief Verifica se um Aluno já existe no arquivo CSV.
     /// @return True se o Aluno já existe, False caso contrário.
    bool alunoJaExiste() const;

     /// @brief Realiza o cadastro de um novo Aluno.
    static void cadastroAluno();
};

#endif // ALUNO_HPP
