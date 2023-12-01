#include "gerenciarAluguel.hpp"
#include "aluguel.cpp"
#include <iostream>
#include <algorithm>

std::vector<Livro> GerenciarAluguel::livros;


void GerenciarAluguel::alugarLivro(const std::string& titulo) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        if (!it->estaAlugado()) {
            it->alugar();

            // Adiciona a informação do aluguel no arquivo CSV
            std::ofstream arquivo("alugueis.csv", std::ios::out | std::ios::app);
            if (arquivo.is_open()) {
                arquivo << titulo << "," << "1" << "\n";
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
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        if (it->estaAlugado()) {
            it->devolver();

            // Remove a informação do aluguel do arquivo CSV temporário
            std::ifstream arquivoOriginal("alugueis.csv");
            std::ofstream arquivoTemporario("alugueis_temp.csv");

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
                std::remove("alugueis.csv");
                std::rename("alugueis_temp.csv", "alugueis.csv");

                std::cout << "Livro devolvido com sucesso." << std::endl;
            } else {
                std::cerr << "Erro ao abrir os arquivos de alugueis." << std::endl;
            }
        } else {
            std::cout << "Livro já está disponível, não pode ser devolvido." << std::endl;
        }
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}
void GerenciarAluguel::aumentarPrazo(const std::string& titulo, int dias) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        it->aumentarPrazo(dias);
        std::cout << "Prazo aumentado com sucesso." << std::endl;
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

void GerenciarAluguel::definirMulta(const std::string& titulo, double multa) {
    auto it = std::find_if(livros.begin(), livros.end(), [titulo](const Livro& livro) {
        return livro.getTitulo() == titulo;
    });

    if (it != livros.end()) {
        it->definirMulta(multa);
        std::cout << "Multa definida com sucesso." << std::endl;
    } else {
        std::cout << "Livro não encontrado." << std::endl;
    }
}

