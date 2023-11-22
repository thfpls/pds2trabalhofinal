#include "aluno.hpp"
#include <iostream>
#include <fstream>

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula)
    : Perfil_usuario(nome, email), _matricula(matricula)
{
    // Mantém o papel padrão como ALUNO
    _papel = ALUNO;
}

const std::string& Aluno::getMatricula() const
{
    return _matricula;
}

void Aluno::emprestarLivro(const std::string& titulo) {
   // _livros_emprestados.pushback(titulo);
}

void Aluno::devolverLivro(const std::string& titulo) {

}
const std::vector <std::string>& Aluno::getLivrosEmprestados() const {
    return _livros_emprestados; 
}

int Aluno::salvar_aluno() {
    // Cria um objeto ofstream e o associa ao arquivo "usuario.csv"
    std::ofstream arquivo("usuario.csv", std::ios::out | std::ios::app);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo CSV.\n";
        return -1; // Retorna um código de erro, se necessário
    }

    // Escreve as informações do aluno no arquivo CSV
    arquivo << "ALUNO," << getNome_usuario() << "," << getEmail_usuario() << "," << getMatricula() << "\n";

    // Fecha o arquivo automaticamente ao sair do escopo
    // devido à utilização do objeto std::ofstream

    return 0; // Retorna 0 para indicar sucesso
}
