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
    // Se o livro não foi encontrado
    std::cout << "Livro não encontrado. Aluguel não efetuado." << std::endl;
}
