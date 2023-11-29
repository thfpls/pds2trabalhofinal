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
    arquivo << "ADMIN," << getNome_usuario() << "," << getEmail_usuario() << "\n";

    // Fecha o arquivo automaticamente ao sair do escopo
    // devido à utilização do objeto std::ofstream

    return 0; // Retorna 0 para indicar sucesso
}

bool Administrador::admJaExiste() const {
    // Abre o arquivo CSV para leitura
    std::ifstream arquivo("usuario.csv");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo CSV.\n";
        return false;
    }

    // Formato esperado: PAPEL,NOME,EMAIL;
    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Use um stringstream para separar os campos da linha
        std::istringstream iss(linha);
        std::string papel, nomeArquivo, emailArquivo;

        // Leitura dos campos da linha
        std::getline(iss, papel, ',');
        std::getline(iss, nomeArquivo, ',');
        std::getline(iss, emailArquivo, ',');

        // Comparação com os parâmetros fornecidos
        if (papel == "ADMIN" && getNome_usuario() == nomeArquivo && getEmail_usuario() == emailArquivo) {
            // Adm encontrado, feche o arquivo e retorne true
            arquivo.close();
            return true;
        }
    }

    // Fecha o arquivo
    arquivo.close();

    // Se não encontrar uma correspondência, retorne false
    return false;
}

void Administrador::CadastroAdm() {
    // Solicitar informações do usuário
    std::string nome, email;

    // Verificar o nome (permitir letras e espaços)
    while (true) {
        std::cout << "Digite o nome do administrador: ";
        std::getline(std::cin, nome);

        bool nomeValido = true;
        for (char c : nome) {
            if (!std::isalpha(c) && !std::isspace(c)) {
                nomeValido = false;
                break;
            }
        }

        if (nomeValido) {
            break;
        }

        std::cout << "Nome inválido. Use apenas letras e espaços. Tente novamente.\n";
    }

    // Verificar a matrícula (permitir apenas números)


    // Solicitar o email do aluno
    std::cout << "Digite o email do administrador: ";
    std::getline(std::cin, email);

    // Criar um aluno dinamicamente com base nas informações do usuário
    Administrador novoAdm(nome, email);


    // Verificar se o aluno já existe
    if (novoAdm.admJaExiste()) {
        std::cerr << "Aluno já existe no arquivo CSV.\n";
        return;
    }

    // Salvar as informações do aluno no arquivo CSV
    if (novoAdm.salvar_adm() == 0) {
        std::cout << "Aluno salvo no arquivo CSV com sucesso.\n";
    }
    else {
        std::cerr << "Erro ao salvar o aluno no arquivo CSV.\n";
    }

}
