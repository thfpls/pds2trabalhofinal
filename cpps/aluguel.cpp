#include "Aluguel.hpp"
#include "Livro.hpp"

void Aluguel::checarDisponibilidade(const std::string& titulo) {
    for (auto& livro : livros) {
        if (livro.getTitulo() == titulo) {
            if (livro.estaAlugado()) {
                std::cout << "O livro está alugado. Aluguel não disponível." << std::endl;
            } else {
                std::cout << "O livro está disponível para aluguel." << std::endl;
            }
            return;
        }
    }
    std::cout << "Livro não encontrado." << std::endl;
}
