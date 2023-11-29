#include "perfilUsuario.hpp"
#include "aluno.hpp"
//implementar o construtor

PerfilUsuario::PerfilUsuario(const std::string& nome, const std::string& email) : _nome_perfil_usuario(nome), _email_perfil_usuario(email), _papel(ALUNO)
{
}

//métodos
const std::string& PerfilUsuario::getNomeUsuario() const {
    return _nome_perfil_usuario;
}

const std::string& PerfilUsuario::getEmailUsuario() const {
    return _email_perfil_usuario;
}

PapelDoUsuario PerfilUsuario::getPapelUsuario() const {
    return _papel;
}

std::string PerfilUsuario::papelToString() const {
    return (_papel == ADMIN) ? "ADMIN" : "ALUNO";
}
// destrutor virtual
PerfilUsuario::~PerfilUsuario() {

}
