#include <iostream>
enum Papel_do_usuario
{
    ADMIN,
    ALUNO
};

class Perfil_usuario
{
private:
    // esses 3 precisam estar relacionados no banco de dados
    static unsigned int CONTADOR_ID_perfil_usuario;
    unsigned int _ID_perfil_usuario;
    std::string _email_perfil_usuario;

protected:
    Papel_do_usuario _papel;

public:
    Perfil_usuario(std::string);
    unsigned int get_ID_perfil_usuario();
    std::string get_email_perfil_usuario();
    // virtual
    Papel_do_usuario get_papel_usuario();
   // virtual void consultar_acervo(std::string) = 0;
    // destrutor
    virtual ~Perfil_usuario();
};

#endif
