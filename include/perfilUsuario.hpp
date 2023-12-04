// perfil_usuario.hpp
#ifndef PERFILUSUARIO_HPP
#define PERFILUSUARIO_HPP

#include <iostream>

/// @brief Enumeração que representa o papel do usuário
enum Papel_do_usuario
{
    ADMIN, 
    ALUNO 
};

 /// @brief Classe base que representa o perfil de um usuário
class PerfilUsuario
{
private:
    std::string _nome_perfil_usuario;  
    std::string _email_perfil_usuario; 
    int _livrosAlugados;
protected:
    Papel_do_usuario _papel; 
public:
    
     /// @brief Construtor da classe PerfilUsuario
     /// @param nome Nome do usuário
     /// @param email E-mail do usuário
    PerfilUsuario(const std::string& nome, const std::string& email, const int livros);

    /// @brief Destrutor virtual da classe PerfilUsuario
    virtual ~PerfilUsuario();

     /// @brief Obtém o nome do usuário
     /// @return Nome do usuário
    const std::string& getNomeUsuario() const;

     /// @brief Obtém o e-mail do usuário
     // @return E-mail do usuário
    const std::string& getEmailUsuario() const;

     /// @brief Obtém o número de livros alugados
     // @return livros alugados 
    int getLivrosAlugados() const;

     /// @brief Obtém o papel do usuário
     /// @return Papel do usuário (ADMIN ou ALUNO)
    Papel_do_usuario getPapelUsuario() const;

     /// @brief Define o nome do usuário
     /// @return nenhum
    void setNomeUsuario(std::string nome);

     /// @brief Defin o e-mail do usuário
     // @return nenhum
    void setEmailUsuario(std::string email);

     /// @brief Define o número de livros alugados
     // @return nenhum
    void setLivrosAlugados(int livrosAlugados);

     /// @brief Define o papel do usuário (ADMIN ou ALUNO)
     /// @return nenhum 
    void setPapelUsuario(Papel_do_usuario papel);

    /// @brief Converte o papel do usuário para uma string
    ///@return String representando o papel do usuário
    std::string papelToString() const;

    void deCSV(const std::string& linha);

    void deCIN();

    std::string paraCSV();
    // para tornar a classe polimorfica

    virtual void apenasparatornarpolimorfica() const;
};

#endif // PERFILUSUARIO_HPP
