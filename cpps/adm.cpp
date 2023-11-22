// adm.cpp
#include "adm.hpp"
#include <iostream>
#include <fstream>

Administrador::Administrador(const std::string& nome, const std::string& email)
    : Perfil_usuario(nome, email)
{
    // Altera o papel para ADMIN ao criar um Administrador
    _papel = ADMIN;
}

int Administrador::salvar_adm()
{
    // Cria um objeto ofstream e o associa ao arquivo "usuario.csv"
    std::ofstream arquivo("usuario.csv", std::ios::out | std::ios::app);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo CSV.\n";
        return -1; // Retorna um código de erro, se necessário
    }

    // Escreve as informações do administrador no arquivo CSV
    arquivo << "ADMIN," << getNome_usuario()<< "," << getEmail_usuario() << "\n";

    // Fecha o arquivo automaticamente ao sair do escopo
    // devido à utilização do objeto std::ofstream

    return 0; // Retorna 0 para indicar sucesso
}

void Administrador::criarEsalvarNovoAdm()
{
    std::string nome, email;

    // Solicitar informações do administrador
    std::cout << "Digite o nome do administrador: ";
    std::getline(std::cin, nome);

    std::cout << "Digite o email do administrador: ";
    std::getline(std::cin,email);

    //criar um amd dinamicamente

    Administrador novoAdministrador(nome, email); 

    // Salvar as informações do administrador no arquivo CSV
    if (novoAdministrador.salvar_adm() == 0)
    {
        std::cout << "Administrador salvo no arquivo CSV com sucesso.\n";
    }
    else
    {
        std::cerr << "Erro ao salvar o administrador no arquivo CSV.\n";
    }
}
