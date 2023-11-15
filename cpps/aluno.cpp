#include "../include/aluno.h"

#include <iostream>
#include <iomanip>

Aluno::Aluno(std::string email) : Perfil_usuario(email)
{
    this->_papel = ALUNO;
    salvar_aluno_no_arquivo();
}

Aluno::~Aluno()
{
    for (auto it : livros_com_aluno)
    {
        delete it;
    }
    livros_com_aluno.clear();
}


void Aluno::get_livros_com_aluno()
{
    for (auto it : this->livros_com_aluno)
    {
        std::cout << std::endl
                  << it->get_titulo() << " ," << it->get_autor() << std::endl;
    }
    std::cout << "sem livros" << std::endl;
}

int Aluno::get_n_exemplares()
{
    return this->livros_com_aluno.size();
}

void Aluno::emprestar_livro(Exemplar *livro)
{
    if (this->livros_com_aluno.size() > 5)
        throw ja_possui_mutos_livros_e();
    for (auto l : livros_com_aluno)
    {
        livros_com_aluno.push_back(livro);
    }
}

void Aluno::devolver_livro(int codigo)
{
    bool p = true;
    for (auto l : this->livros_com_aluno)
        if (l->get_codigo() == codigo)
            p = false;
    if (p)
    {
        throw nao_possui_esse_livro_e();
    }

    int i = 0;
    for (auto l : livros_com_aluno)
    {
        if (l->get_codigo() == codigo)
            livros_com_aluno.erase(livros_com_aluno.begin() + i);
        i++;
    }
}

void Aluno::consultar_acervo(std::string titulo) // pro aluno so retorna codigo, titulo e autor, e # exemplares disponiveis
{
    std::ifstream arquivo_acervo("files/acervo.csv");
    if (!arquivo_acervo)
    {
        std::cout << "Falha ao abrir o arquivo" << std::endl;
        return;
    }

    std::string linha;
    while (getline(arquivo_acervo, linha))
    {
        std::istringstream iss(linha);
        std::string codigo, autor, titulo_csv, ano_publicacao, genero;

        if (getline(iss, codigo, ',') &&
            getline(iss, autor, ',') &&
            getline(iss, titulo_csv, ',') &&
            getline(iss, ano_publicacao, ',') &&
            getline(iss, genero, ','))
        {
            if (titulo_csv == titulo)
            {
                int codigo_int = std::stoi(codigo);

                std::cout << "Acervo encontrado:\n";
                std::cout << "Código: " << codigo_int << '\n';
                std::cout << "Título: " << titulo << '\n';
                std::cout << "Autor: " << autor << '\n';
            }
        }
    }

    arquivo_acervo.close();
}


int Aluno::salvar_aluno_no_arquivo()
{
    std::ofstream aluno_out;
    aluno_out.open("usuarios.csv", std::ios_base::app);
    if (!aluno_out)
    {
        std::cout << "arquivo nao existe" << std::endl;
        return 0;
    }
    else
    {
        aluno_out << this->get_ID_perfil_usuario() << ","
                  << this->get_email_perfil_usuario() << "," << this->get_senha_perfil_usuario() << "," << this->get_senha_perfil_usuario() << std::endl;

        aluno_out.close();
        return 1;
    }
}
