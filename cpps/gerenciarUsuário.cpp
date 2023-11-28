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

void gerenciarUsuario::alterarPerfil (std::string _email, std::string _nome, std::string _livrosAlugados){
    std::ifstream arquivo_usuarios("files/usuarios.csv");
    std::ofstream arquivo_usuariost("temporario.csv");  // Arquivo temporário para armazenar as alterações

    if (!arquivo_usuarios.is_open() || !arquivo_usuariost.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return;
    }

    std::string linha;
    std::vector<std::string> linhasAlteradas;

    while (getline(arquivo_usuarios, linha)) {
        std::istringstream streamLinha(linha);
        std::string valor;

        std::vector<std::string> valoresLinha;
        while (getline(streamLinha, valor, ',')) {
            valoresLinha.push_back(valor);
        }

        // Suponha que o nome está na primeira coluna
        if (valoresLinha.size() > 0 && valoresLinha[0] == nome) {
            // Altera os dados do perfil
            valoresLinha[1] = novoPerfil.nome;
            valoresLinha[2] = novoPerfil.sobrenome;
            // Adicione mais linhas para outros campos conforme necessário

            // Atualiza a linha com os novos valores
            std::ostringstream linhaAtualizada;
            for (const auto& v : valoresLinha) {
                linhaAtualizada << std::quoted(v) << ",";
            }

            linhasAlteradas.push_back(linhaAtualizada.str());
        } else {
            linhasAlteradas.push_back(linha);
        }
    }

    arquivoEntrada.close();

    // Escreve as linhas alteradas no arquivo temporário
    for (const auto& linha : linhasAlteradas) {
        arquivoSaida << linha << std::endl;
    }

    arquivoSaida.close();

    // Renomeia o arquivo temporário para substituir o original
    std::rename("temporario.csv", nomeArquivo.c_str());
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
