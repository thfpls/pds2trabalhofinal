
#ifndef GERENCIAR_ALUGUEL_HPP
#define GERENCIAR_ALUGUEL_HPP

#include <iostream>
#include <vector>
#include <string>
#include "livro.hpp"

class GerenciarAluguel {
public:
    static std::vector<Livro> livros; 
    //funções para alugar, devolver o livro, aumentar prazo e definir multa, conferir disponibilidade

    static void alugarLivro(const std::string& titulo);
    static void devolverLivro(const std::string& titulo);
    static void aumentarPrazo(const std::string& titulo, int dias);
    static void definirMulta(const std::string& titulo, double multa);
    static bool checarDisponibilidade(const std::string& titulo);
};

#endif // GERENCIAR_ALUGUEL_HPP
