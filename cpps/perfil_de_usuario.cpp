#include "perfil_de_usuario.hpp"

unsigned int Perfil_usuario::CONTADOR_ID_perfil_usuario = 0;

Perfil_usuario::~Perfil_usuario() {}

Perfil_usuario::Perfil_usuario(std::string email) : _email_perfil_usuario(email)
{
    _ID_perfil_usuario = CONTADOR_ID_perfil_usuario;
    CONTADOR_ID_perfil_usuario++;
}

Papel_do_usuario Perfil_usuario::get_papel_usuario()
{
    return this->_papel;
}

unsigned int Perfil_usuario::get_ID_perfil_usuario()
{
    return this->_ID_perfil_usuario;
}

std::string Perfil_usuario::get_email_perfil_usuario()
{
    return this->_email_perfil_usuario;
}
