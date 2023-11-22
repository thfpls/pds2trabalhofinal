#ifndef ADM_HPP
#define ADM_HPP

//basicamente criar um adm para fim de herança

#include "perfil_usuario.hpp"
#include <iostream>

class Administrador : public Perfil_usuario {
public:
    Administrador(const std::string& nome, const std::string& email);

    int salvar_adm();
}; 
#endif // ADM_HPP
