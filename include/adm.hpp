// adm.hpp
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "perfilUsuario.hpp"
#include <iostream>
#include <string>

class Administrador : public PerfilUsuario
{
private:
    std::string _nome_adm;
    std::string _email_adm;

public:
    Administrador(const std::string& nome, const std::string& email);

    int salvarAdm();
    bool admJaExiste() const;

    static void cadastroAdm();
};

#endif // ADMINISTRADOR_HPP
