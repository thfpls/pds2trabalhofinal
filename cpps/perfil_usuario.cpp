#include "perfil_usuario.hpp"
#include "aluno.hpp"
//implementar o construtor

Perfil_usuario::Perfil_usuario(const std::string& nome, const std::string& email) : _nome_perfil_usuario(nome), _email_perfil_usuario(email), _papel(ALUNO)
{
}

//métodos
const std::string& Perfil_usuario::getNomeUsuario() const {
    return _nome_perfil_usuario;
}

const std::string& Perfil_usuario::getEmailUsuario() const {
    return _email_perfil_usuario;
}

Papel_do_usuario Perfil_usuario::getPapelUsuario() const {
    return _papel;
}

std::string Perfil_usuario::papelToString() const {
    return (_papel == ADMIN) ? "ADMIN" : "ALUNO";
}
// destrutor virtual
Perfil_usuario::~Perfil_usuario() {

}
