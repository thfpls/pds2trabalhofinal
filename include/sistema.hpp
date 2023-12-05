#ifndef SISTEMA_HPP
#define SISTEMA_HPP

#include "acervo.hpp"
#include "adm.hpp"
#include "aluno.hpp"
#include "aluguel.hpp"
#include "const.hpp"
#include "gerenciarAluguel.hpp"
#include "gerenciarUsuario.hpp"
#include "livro.hpp"
#include "perfilUsuario.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


 // @brief Classe que representa o sistema da biblioteca.
 
class Sistema {
public:
    
     // @brief Construtor padrão da classe Sistema.
     
    Sistema(){};


     /// @brief Inicializa o sistema.
    void inicia_sistema();


     /// @brief Exibe o menu principal e processa as opções escolhidas pelo usuário.

    void menu_principal();


     /// @brief Exibe o menu de gerenciamento de aluno

    void menu_aluno();


     /// @brief Exibe o menu de gerenciamento de livro

    void menu_livro();


     /// @brief Exibe o menu de gerenciamento de aluguel

    void menu_aluguel();

private:
};

#endif // SISTEMA_HPP
