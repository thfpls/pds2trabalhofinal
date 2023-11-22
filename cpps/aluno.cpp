//aluno.cpp
#include "aluno.hpp"
#include <iostream>
#include <fstream>
#include <string>

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

void Aluno::criarEsalvarNovoAluno() {
    // Solicitar informações do usuário
    std::string nome, email, matricula;

    std::cout << "Digite o nome do aluno: ";
    std::getline(std::cin, nome);

    std::cout << "Digite o email do aluno: ";
    std::getline(std::cin, email);

    std::cout << "Digite a matrícula do aluno: ";
    std::getline(std::cin, matricula);

    // Criar um aluno dinamicamente com base nas informações do usuário
    Aluno novoAluno(nome, email, matricula);

    // Salvar as informações do aluno no arquivo CSV
    if (novoAluno.salvar_aluno() == 0) {
        std::cout << "Aluno salvo no arquivo CSV com sucesso.\n";
    }
    else {
        std::cerr << "Erro ao salvar o aluno no arquivo CSV.\n";
    }
}
