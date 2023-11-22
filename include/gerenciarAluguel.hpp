#include "aluguel.hpp"
#include "livro.hpp"
#include "perfil_de_usuario.hpp"

#include <string>

class gerenciarAluguel{
    public:
        //alocar um livro, mudando sua chave no map do acervo para alugado
        void alugarLivro(std::string Titulo, int prazo);

        //alocar um livro, mudando sua chave no map do acervo para não alugado
        void devolverLivro(std::string Titulo);

        //aumenta o prazo estabelecido para o aluguel
        void aumentarPrazo(int prazo, int novoPrazo);

        //estipula uma multa para um usuário 
        void definirMulta(int multa, std::string nome);

};
