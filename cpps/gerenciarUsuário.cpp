#include "gerenciarUsuario.hpp"

void gerenciarUsuario::deletarPerfil (std::string _email){
    
// verifica se o id não é do próprio admin, e depois se existe algum usuario com esse id
    if (this->get_email_perfil_usuario() == email)
    {
        throw id_invalido_e();
    }
    else
    {
        std::ifstream arquivo_usuarios("files/usuarios.csv");
        std::ofstream arquivo_atualizado("files/usuarios_temp.csv");
        std::string linha;

        while (getline(arquivo_usuarios, linha))
        {
            std::istringstream iss(linha);
            std::string campo;
            bool email_encontrado = false;

            while (getline(iss, campo, ','))
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

        remove("files/usuarios.csv");
        rename("files/usuarios_temp.csv", "files/usuarios.csv");
    }
}

void alterarPerfil(const std::string& arquivoCSV, const std::string& email, const std::string& novoNome, const std::string& novosLivrosAlugados) {
    // Abrir o arquivo CSV
    std::ifstream arquivo_usuarios("files/usuarios.csv");
    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo CSV.\n";
        return;
    }

    // Criar um vetor para armazenar os dados do arquivo
    std::vector<Usuario> usuarios;
    std::string linha;

    // Ler e analisar cada linha do arquivo
    while (std::getline(arquivo, linha)) {
        std::istringstream ss(linha);
        std::string email, nome, livrosAlugados;

        // Extrair os campos da linha
        std::getline(ss, email, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, livrosAlugados, ',');

        // Criar um objeto Usuario e adicionar ao vetor
        usuarios.push_back({email, nome, livrosAlugados});
    }

    // Fechar o arquivo
    arquivo.close();

    // Procurar pelo usuário com o email fornecido
    for (Usuario& usuario : usuarios) {
        if (usuario.email == email) {
            // Alterar os dados do usuário
            usuario.nome = novoNome;
            usuario.livrosAlugados = novosLivrosAlugados;
            break; // Parar a busca, pois já encontramos o usuário
        }
    }

    // Abrir o arquivo novamente para escrita
    std::ofstream arquivoSaida(arquivoCSV);

    // Escrever os dados atualizados no arquivo
    for (const Usuario& usuario : usuarios) {
        arquivoSaida << usuario.email << ',' << usuario.nome << ',' << usuario.livrosAlugados << '\n';
    }

    // Fechar o arquivo de saída
    arquivoSaida.close();

    std::cout << "Perfil alterado com sucesso!\n";
}


void gerenciarUsuario::imprimirPerfis (){
    std::ifstream arquivo_usuarios("files/usuarios.csv");
    if (!arquivo_usuarios) {
        std::cout << "Falha ao abrir o arquivo" << std::endl;
        return;
    }

    std::string linha;
    while (getline(arquivo_usuarios, linha)){
        std::cout << this->get_email_perfil_usuario() << "," 
                  << this->get_nome_perfil_usuario() << "," 
                  << this->get_livros_alugados_perfil_usuario()<<std::endl;
    }
    arquivo_usuarios.close();
}
