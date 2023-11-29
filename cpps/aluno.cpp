// aluno.cpp
#include "aluno.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

Aluno::Aluno(const std::string& nome, const std::string& email, const std::string& matricula)
    : PerfilUsuario(nome, email), _matricula(matricula)
{
    _papel = ALUNO;
}

const std::string& Aluno::getMatricula() const {
    return _matricula;
}


int Aluno::salvarAluno() const {
    // Abre o arquivo CSV para escrita (modo append)
    std::ofstream arquivo("usuario.csv", std::ios::out | std::ios::app);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo CSV para escrita.\n";
        return -1;
    }

    // Escreve as informações do aluno no arquivo CSV
    arquivo << "ALUNO," << getNomeUsuario() << "," << getEmailUsuario() << "," << getMatricula() << "\n";

    // Fecha o arquivo automaticamente ao sair do escopo
    // devido à utilização do objeto std::ofstream

    return 0; // Retorna 0 para indicar sucesso
}

bool Aluno::alunoJaExiste() const {
    // Abre o arquivo CSV para leitura
    std::ifstream arquivo("usuario.csv");

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo CSV.\n";
        return false;
    }

    // Formato esperado: PAPEL,NOME,EMAIL,MATRICULA
    std::string linha;
    while (std::getline(arquivo, linha)) {
        // Use um stringstream para separar os campos da linha
        std::istringstream iss(linha);
        std::string papel, nomeArquivo, emailArquivo, matriculaArquivo;

        // Leitura dos campos da linha
        std::getline(iss, papel, ',');
        std::getline(iss, nomeArquivo, ',');
        std::getline(iss, emailArquivo, ',');
        std::getline(iss, matriculaArquivo, ',');

        // Comparação com os parâmetros fornecidos
        if (papel == "ALUNO" && getNomeUsuario() == nomeArquivo && getEmailUsuario() == emailArquivo && getMatricula() == matriculaArquivo) {
            // Aluno encontrado, feche o arquivo e retorne true
            arquivo.close();
            return true;
        }
    }

    // Fecha o arquivo
    arquivo.close();

    // Se não encontrar uma correspondência, retorne false
    return false;
}

void Aluno::cadastroAluno() {
    // Solicitar informações do usuário
    std::string nome, email, matricula;

    // Verificar o nome (permitir letras e espaços)
    while (true) {
        std::cout << "Digite o nome do aluno: ";
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
    while (true) {
        std::cout << "Digite a matrícula do aluno (apenas números): ";
        std::getline(std::cin, matricula);

        bool matriculaValida = true;
        for (char c : matricula) {
            if (!std::isdigit(c)) {
                matriculaValida = false;
                break;
            }
        }

        if (matriculaValida) {
            break;
        }

        std::cout << "Matrícula inválida. Tente novamente.\n";
    }

    // Solicitar o email do aluno
    std::cout << "Digite o email do aluno: ";
    std::getline(std::cin, email);

    // Criar um aluno dinamicamente com base nas informações do usuário
    Aluno novoAluno(nome, email, matricula);


    // Verificar se o aluno já existe
    if (novoAluno.alunoJaExiste()) {
        std::cerr << "Aluno já existe no arquivo CSV.\n";
        return;
    }

    // Salvar as informações do aluno no arquivo CSV
    if (novoAluno.salvarAluno() == 0) {
        std::cout << "Aluno salvo no arquivo CSV com sucesso.\n";
    }
    else {
        std::cerr << "Erro ao salvar o aluno no arquivo CSV.\n";
    }

}
