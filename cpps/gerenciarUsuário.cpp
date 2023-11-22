#include "gerenciarUsuário.hpp"

void gerenciarUsuario::deletarPerfil (std::string _email){
    
// verifica se o id não é do próprio admin, e depois se existe algum usuario com esse id
    if (this->get_email_perfil_usuario() == email)
    {
        throw id_invalido_e();
    }
    else
    {

        // bool b = true;
        //  for(todos os usuario do bd) if(usuario.get_ID_perfil_usuario()==id) b = false;
        // if (b)
        //    throw id_nao_existe_e();

        /*for(*todos os usuario do bd) {
            if(id do usuario == id) {
                if(usuario for aluno) devolver todos os livros que estão com o aluno
                deletar o usuario
            }
        }*/

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

void Admin::consultar_acervo(std::string)
{
    // nao pode acontecer nada aqui, admin nao liga pra livro
}

Admin::~Admin()
{
}
