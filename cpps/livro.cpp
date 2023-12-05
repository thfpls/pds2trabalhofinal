#include "perfilUsuario.hpp"
#include "aluno.hpp"
#include "adm.hpp" 
#include <algorithm>
#include <iostream>
#include <limits>
//implementar o construtor

PerfilUsuario::PerfilUsuario(const std::string& nome, const std::string& email, const int livros) : _nome_perfil_usuario(nome), _email_perfil_usuario(email), _livrosAlugados(livros), _papel(ALUNO)
{
}

//métodos
const std::string& PerfilUsuario::getNomeUsuario() const {
    return _nome_perfil_usuario;
}

const std::string& PerfilUsuario::getEmailUsuario() const {
    return _email_perfil_usuario;
}

Papel_do_usuario PerfilUsuario::getPapelUsuario() const {
    return _papel;
}

int PerfilUsuario::getLivrosAlugados() const {
    return _livrosAlugados;
}

void PerfilUsuario::setNomeUsuario(std::string nome) {
    _nome_perfil_usuario = nome;
}

void PerfilUsuario::setEmailUsuario(std::string email) {
    _email_perfil_usuario = email;
}

void PerfilUsuario::setPapelUsuario(Papel_do_usuario papel) {
    _papel = papel;
}

void PerfilUsuario::setLivrosAlugados(int livros) {
    _livrosAlugados = livros;
}


std::string PerfilUsuario::papelToString() const {
    return (_papel == ADMIN) ? "ADMIN" : "ALUNO";
}

void PerfilUsuario::deCSV(const std::string& linha){
  std::istringstream ss(linha);
  std::string aux; 

  std::getline(ss,_nome_perfil_usuario,',');
  std::getline(ss,_email_perfil_usuario,',');
  std::getline(ss,aux,',');
  _livrosAlugados = std::stoi(aux);
  std::getline(ss,aux,',');
  //remover espacos em branco
  aux.erase(std::remove_if(aux.begin(), aux.end(), ::isspace), aux.end());
  _papel = (aux == "ADMIN" ? ADMIN : ALUNO); 
}

void PerfilUsuario::deCIN(){
  using namespace std;
  std::string aux; 

  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  cout << "Digite o nome:";
  getline(cin,_nome_perfil_usuario);
  cout << "Digite o email:";
  getline(cin,_email_perfil_usuario);
  cout << "Digite o numero de livros alugados:";
  if (cin >> _livrosAlugados){
    cin.get();
    cout << "ALUNO ou ADMIN:";
    getline(cin,aux);
    aux.erase(remove_if(aux.begin(), aux.end(), ::isspace), aux.end());
    if (aux == "ALUNO"){
      _papel = ALUNO;
    } else {
      _papel = ADMIN;  
    } 
  } else {
    cin.get();
    cout<< "Numero de livros invalido" << endl;
  }
  return;
}


std::string PerfilUsuario::paraCSV(){
  std::ostringstream oss;

  std::string aux = (_papel == ADMIN ? "ADMIN" : "ALUNO");

  oss << _nome_perfil_usuario << ","
      << _email_perfil_usuario << ","
      << _livrosAlugados << ","
      << aux;

  return oss.str();
}

// destrutor virtual
PerfilUsuario::~PerfilUsuario() {
}

void PerfilUsuario::apenasparatornarpolimorfica() const{ }
