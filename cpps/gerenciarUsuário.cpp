#include "gerenciarUsuario.hpp"
#include "perfilUsuario.hpp"
#include "aluno.hpp"
#include "adm.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

void GerenciarUsuario::carregarUsuarios(std::string nomeArquivo){
    std::ifstream arq(nomeArquivo);

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    usuarios.clear();
    std::string linha;
    while (std::getline(arq, linha)) {
        if (linha!=""){
          PerfilUsuario u("","",0);
	  u.deCSV(linha);
	  usuarios.push_back(u);
	  std::cout << "carregou " << u.paraCSV() << std::endl;
	  imprimirPerfis();
	}
    }

    arq.close();
    return;
}

void GerenciarUsuario::salvarUsuarios(std::string nomeArquivo){
    std::ofstream arquivoTemp(ARQUSUARIOTEMP);

    if (!arquivoTemp.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    for (auto& usuario : usuarios) {
      std::string linha = usuario.paraCSV();
      arquivoTemp << linha << std::endl;
    }

    std::remove(nomeArquivo.c_str());
    std::rename(ARQUSUARIOTEMP,nomeArquivo.c_str());

    return;
}

PerfilUsuario GerenciarUsuario::localizarUsuario(std::string email){
    using namespace std;

    PerfilUsuario u1("","",0);
        

    for (const auto& usuario : usuarios) {
      if (usuario.getEmailUsuario() == email){
        u1 = usuario; 
	break;
      }
    }
    return u1;
}


void GerenciarUsuario::inserirUsuario(){
    using namespace std;

    PerfilUsuario u1("","",0);
    u1.deCIN();
        
    // declara uma variavel booleana pra indicar se o livro ja existe
    bool existe = false;

    for (const auto& usuario : usuarios) {
      if (usuario.getEmailUsuario() == u1.getEmailUsuario()){
	existe = true;
	break;
      }
    }
    if (!existe){
	usuarios.push_back(u1);
	salvarUsuarios(ARQUSUARIO);
    }
    return;
}


void GerenciarUsuario::deletarPerfil (std::string email){
    
        std::ifstream arquivo_usuarios(ARQUSUARIO);
        std::ofstream arquivo_atualizado(ARQUSUARIOTEMP);
        std::string linha;

        while (std::getline(arquivo_usuarios, linha))
        {
            std::istringstream iss(linha);
            std::string campo;
            bool email_encontrado = false;

            while (std::getline(iss, campo, ','))
            {
                if (campo == email)
                {
                    email_encontrado = true;
                    break;
                }
            }

            if (!email_encontrado)
            {
                arquivo_atualizado << linha << '\n';
            }
        }

        arquivo_usuarios.close();
        arquivo_atualizado.close();

        remove(ARQUSUARIO);
        rename(ARQUSUARIOTEMP,ARQUSUARIO);
}

void alterarPerfil(const std::string& email, const std::string& novoNome, const int novosLivrosAlugados) {
    // Abrir o arquivo CSV
    std::ifstream arquivo_usuarios(ARQUSUARIO);
    if (!arquivo_usuarios.is_open()) {
        std::cout << "Erro ao abrir o arquivo CSV.\n";
        return;
    }

    // Criar um vetor para armazenar os dados do arquivo
    std::vector<PerfilUsuario> usuarios;
    std::string linha;

    // Ler e analisar cada linha do arquivo
    while (std::getline(arquivo_usuarios, linha)) {
        std::istringstream ss(linha);
        std::string email, nome, strlivros;
	int livrosAlugados;

        // Extrair os campos da linha
        std::getline(ss, email, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, strlivros, ',');
        livrosAlugados = std::stoi(strlivros);

        // Criar um objeto Usuario e adicionar ao vetor
	PerfilUsuario usuario(email, nome, livrosAlugados);
        usuarios.push_back(usuario);
    }

    // Fechar o arquivo
    arquivo_usuarios.close();

    // Procurar pelo usuário com o email fornecido
    for (PerfilUsuario& usuario : usuarios) {
        if (usuario.getEmailUsuario() == email) {
            // Alterar os dados do usuário
            usuario.setEmailUsuario(novoNome);
            usuario.setLivrosAlugados(novosLivrosAlugados);
            break; // Parar a busca, pois já encontramos o usuário
        }
    }

    // Abrir o arquivo novamente para escrita
    std::ofstream arquivo_atualizado(ARQUSUARIOTEMP);

    // Escrever os dados atualizados no arquivo
    for (PerfilUsuario& usuario : usuarios) {
        arquivo_atualizado << usuario.getEmailUsuario() << ',' << usuario.getNomeUsuario() << ',' << usuario.getLivrosAlugados() << '\n';
    }

    // Fechar o arquivo de saída
    arquivo_atualizado.close();

    std::cout << "Perfil alterado com sucesso!\n";
}


void GerenciarUsuario::imprimirPerfis (){
    for (auto& usuario : usuarios) {
      std::string linha = usuario.paraCSV();
      std::cout << linha << std::endl;
    }

  /*
    std::ifstream arquivo_usuarios(ARQUSUARIO);
    if (!arquivo_usuarios) {
        std::cout << "Falha ao abrir o arquivo" << std::endl;
        return;
    }

    std::string linha;
    while (getline(arquivo_usuarios, linha)){
        std::cout << linha << std::endl;
    }
    arquivo_usuarios.close();
    */
}
