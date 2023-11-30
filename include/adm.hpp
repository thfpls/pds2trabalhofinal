// adm.hpp
#ifndef ADMINISTRADOR_HPP
#define ADMINISTRADOR_HPP

#include "perfilUsuario.hpp"
#include <iostream>
#include <string>


 ///@brief Classe que representa um Administrador, derivada da classe PerfilUsuario.
class Administrador : public PerfilUsuario
{
private:
    std::string _nome_adm; 
    std::string _email_adm; 

public:
    
     /// @brief Construtor da classe Administrador.
     /// @param nome Nome do Administrador.
     /// @param email E-mail do Administrador.
    Administrador(const std::string& nome, const std::string& email);

     /// @brief Salva as informações do Administrador em um arquivo CSV.
     /// @return 0 em caso de sucesso, -1 em caso de falha.
    int salvarAdm();

     /// @brief Verifica se um Administrador já existe no arquivo CSV.
     /// @return True se o Administrador já existe, False caso contrário
    bool admJaExiste() const;

    
     /// @brief Realiza o cadastro de um novo Administrador.
    static void cadastroAdm();
};

#endif // ADMINISTRADOR_HPP
