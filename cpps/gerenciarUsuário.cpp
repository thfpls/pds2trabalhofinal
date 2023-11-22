#include "gerenciarUsuário.hpp"

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
    email=_email;
    nome=_nome;
    livrosAlugados=_livrosAlugados;
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

