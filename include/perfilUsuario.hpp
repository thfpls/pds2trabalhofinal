//perfil_usuario.hpp
#ifndef PERFILUSUARIO_HPP
#define PERFILUSUARIO_HPP
#include <iostream>

class Aluno; 

enum Papel_do_usuario
{
    ADMIN,
    ALUNO
};

class PerfilUsuario
{
private:
    std::string _nome_perfil_usuario;
    std::string _email_perfil_usuario;

protected:
    Papel_do_usuario _papel;

public:
    PerfilUsuario(const std::string& nome, const std::string& email);
   
    const std::string& getNomeUsuario() const;
    const std::string& getEmailUsuario() const;

    Papel_do_usuario getPapelUsuario() const;

    std::string papelToString() const; 

    virtual ~PerfilUsuario();
};
#endif // PERFIL_USUARIO_HPP
