// perfil_usuario.hpp
#ifndef PERFILUSUARIO_HPP
#define PERFILUSUARIO_HPP

#include <iostream>

class Aluno; // Declarando a classe Aluno para evitar referência circular**


/// @brief Enumeração que representa o papel do usuário
enum Papel_do_usuario
{
    ADMIN, 
    ALUNO 
};

 /// @brief Classe base que representa o perfil de um usuário
class PerfilUsuario
{
private:
    std::string _nome_perfil_usuario;  
    std::string _email_perfil_usuario; 
protected:
    Papel_do_usuario _papel; 
public:
    
     /// @brief Construtor da classe PerfilUsuario
     /// @param nome Nome do usuário
     /// @param email E-mail do usuário
    PerfilUsuario(const std::string& nome, const std::string& email);

    /// @brief Destrutor virtual da classe PerfilUsuario
    virtual ~PerfilUsuario();

     /// @brief Obtém o nome do usuário
     /// @return Nome do usuário
    const std::string& getNomeUsuario() const;

     /// @brief Obtém o e-mail do usuário
     // @return E-mail do usuário
    const std::string& getEmailUsuario() const;

     /// @brief Obtém o papel do usuário
     /// @return Papel do usuário (ADMIN ou ALUNO)
    Papel_do_usuario getPapelUsuario() const;

    /// @brief Converte o papel do usuário para uma string
    ///@return String representando o papel do usuário
    std::string papelToString() const;
};

#endif // PERFILUSUARIO_HPP
