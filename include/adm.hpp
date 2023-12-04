#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "perfilUsuario.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


 // @brief Classe que representa um Administrador, derivada da classe PerfilUsuario
 
 // A classe Administrador possui funcionalidades específicas para administradores,
 // como salvar informações no arquivo CSV, verificar se um administrador já existe
 // e realizar o cadastro de um novo administrador

class Administrador : public PerfilUsuario {
public:
     // @brief Construtor da classe Administrador
     // @param nome O nome do administrador
     // @param email O email do administrador
    Administrador(const std::string& nome, const std::string& email, const int livros);

     // @brief Salva as informações do administrador no arquivo CSV.
     // @return 0 em caso de sucesso, -1 em caso de erro.
    int salvarAdm();

     // @brief Verifica se um administrador com as mesmas informações já existe.
     // @return true se o administrador já existe, false caso contrário.
    bool admJaExiste() const;

     // @brief Realiza o cadastro de um novo administrador.
     // Solicita informações do usuário, verifica se o administrador já existe
     // e, se não existir, salva as informações no arquivo CSV.
    void cadastroAdm();
};

#endif // ADMINISTRADOR_HPP
