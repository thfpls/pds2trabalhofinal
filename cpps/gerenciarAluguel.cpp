#include "gerenciarAluguel.hpp"
#include "gerenciarUsuario.hpp"
#include "adm.hpp"
#include "aluno.hpp"
#include "aluguel.hpp"
#include "acervo.hpp"
#include <iostream>
#include <algorithm>

void GerenciarAluguel::listarAluguel(std::string nomeArquivo){
    std::ifstream arq(nomeArquivo);

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arq, linha)) {
	std::cout << linha << std::endl;
    }

    arq.close();
    return;
}


void GerenciarAluguel::carregarAluguel(std::string nomeArquivo){
    std::ifstream arq(nomeArquivo);

    if (!arq.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    carteira.clear();
    std::string linha;
    while (std::getline(arq, linha)) {
        Aluguel a("","");
	a.deCSV(linha);
	carteira.push_back(a);
    }

    arq.close();
    return;
}


void GerenciarAluguel::salvarAluguel(std::string nomeArquivo){
    std::ofstream arquivoTemp(ARQALUGUELTEMP);

    if (!arquivoTemp.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << nomeArquivo << std::endl;
        return;
    }

    for (auto& aluguel : carteira) {
      std::string linha = aluguel.paraCSV();
      arquivoTemp << linha << std::endl;
    }

    std::remove(nomeArquivo.c_str());
    std::rename(ARQALUGUELTEMP,nomeArquivo.c_str());

    return;
}


void GerenciarAluguel::alugarLivro(const std::string& titulo, const std::string & email) {

    AcervoBiblioteca ac;
    ac.carregarAcervo(ARQLIVRO);
    Livro liv = ac.localizarLivro(titulo);
    GerenciarUsuario gu;
    gu.carregarUsuarios(ARQUSUARIO);
    if (liv.getTitulo()!= ""){
      std::cout << liv.paraCSV() << std::endl;
      if (!liv.estaAlugado()){
        liv.alugar();
        ac.atualizarLivro(liv);
	ac.verAcervo();
	ac.salvarAcervo(ARQLIVRO);

        std::ofstream arquivo(ARQALUGUEL, std::ios::out | std::ios::app);
        if (arquivo.is_open()) {
          arquivo << titulo << "," << email << ",1,0.0" << "\n";
          arquivo.close();
        } else {
          std::cerr << "Erro ao abrir o arquivo de alugueis." << std::endl;
        }

        std::cout << "Livro alugado com sucesso." << std::endl;
      } else {
        std::cout << "Livro indisponível para aluguel." << std::endl;
      }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }

}

void GerenciarAluguel::devolverLivro(const std::string& titulo) {
    AcervoBiblioteca ac;
    ac.carregarAcervo(ARQLIVRO);
    Livro liv = ac.localizarLivro(titulo);
    if (liv.getTitulo()!= ""){
      if (liv.estaAlugado()){
        liv.devolver();
        ac.atualizarLivro(liv);
	ac.verAcervo();
	ac.salvarAcervo(ARQLIVRO);

        std::ifstream arquivoOriginal(ARQALUGUEL);
        std::ofstream arquivoTemporario(ARQALUGUELTEMP);

        if (arquivoOriginal.is_open() && arquivoTemporario.is_open()) {
          std::string linha;
          while (std::getline(arquivoOriginal, linha)) {
            std::istringstream iss(linha);
            std::string livroAlugado;
            std::getline(iss, livroAlugado, ',');

            if (livroAlugado != titulo) {
              arquivoTemporario << linha << "\n";
            }
          }

          arquivoOriginal.close();
          arquivoTemporario.close();

          // Remove o arquivo original e renomeia o temporário
          std::remove(ARQALUGUEL);
          std::rename(ARQALUGUELTEMP, ARQALUGUEL);

          std::cout << "Livro devolvido com sucesso." << std::endl;
	} else {
          std::cout << "Livro nao estava alugado." << std::endl;
	}
       } else {
        std::cout << "Livro indisponível para aluguel." << std::endl;
      }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::aumentarPrazo(const std::string& titulo, int dias) {
    AcervoBiblioteca ac;
    ac.carregarAcervo(ARQLIVRO);
    Livro liv = ac.localizarLivro(titulo);
    if (liv.getTitulo()!= ""){
      if (liv.estaAlugado()){
        std::string currtit = liv.getTitulo();

        carregarAluguel(ARQALUGUEL);

        auto it = std::find_if(carteira.begin(), carteira.end(), 
	          [currtit](const Aluguel& al) 
		  {return al.getTitulo() == currtit;});

        if (it != carteira.end()) {
          it->aumentarPrazo(dias);
          std::cout << "Prazo aumentado com sucesso." << std::endl;
        } else {
          std::cout << "Livro não encontrado." << std::endl;
        }

	salvarAluguel(ARQALUGUEL);
      } else {
        std::cout << "Livro nao estava alugado." << std::endl;
      }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, double multa) {

    AcervoBiblioteca ac;
    ac.carregarAcervo(ARQLIVRO);
    Livro liv = ac.localizarLivro(titulo);
    if (liv.getTitulo()!= ""){
      if (liv.estaAlugado()){
        std::string currtit = liv.getTitulo();

        carregarAluguel(ARQALUGUEL);

        auto it = std::find_if(carteira.begin(), carteira.end(), 
	          [currtit](const Aluguel& al) 
		  {return al.getTitulo() == currtit;});

        if (it != carteira.end()) {
          it->definirMulta(multa);
          std::cout << "Multa definida com sucesso." << std::endl;
        } else {
          std::cout << "Livro não encontrado." << std::endl;
        }

	salvarAluguel(ARQALUGUEL);
      } else {
        std::cout << "Livro nao estava alugado." << std::endl;
      }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}
