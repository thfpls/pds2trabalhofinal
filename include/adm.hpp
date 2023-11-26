// adm.hpp
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "perfil_usuario.hpp"
#include <iostream>
#include <string>

class Administrador : public Perfil_usuario
{
private:
    std::string _nome_adm;
    std::string _email_adm;

public:
    Administrador(const std::string& nome, const std::string& email);

    int salvar_adm();
    bool admJaExiste() const;

    static void CadastroAdm();
};

#endif // ADMINISTRADOR_HPP
