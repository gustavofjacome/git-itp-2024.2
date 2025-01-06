#include <iostream>
#include <cstdlib>
#include <ctime>

void jogar();

int main() {
    std::cout << "=== Jogo de Adivinhação ===\n\n";
    char jogarNovamente;

    do {
        jogar();

        std::cout << "\nDeseja jogar novamente? (s/n): ";
        std::cin >> jogarNovamente;
    } while (jogarNovamente == 's' || jogarNovamente == 'S');

    std::cout << "\nObrigado por jogar!\n";
    return 0;
}

void jogar() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Inicializa o gerador de números aleatórios
    int numeroSecreto = std::rand() % 100 + 1; // Número entre 1 e 100
    int palpite;
    int tentativas = 0;

    std::cout << "Eu escolhi um número entre 1 e 100. Tente adivinhar!\n";

    do {
        std::cout << "Seu palpite: ";
        std::cin >> palpite;
        tentativas++;

        if (palpite < numeroSecreto) {
            std::cout << "Muito baixo! Tente novamente.\n";
        } else if (palpite > numeroSecreto) {
            std::cout << "Muito alto! Tente novamente.\n";
        } else {
            std::cout << "Parabéns! Você adivinhou o número em " << tentativas << " tentativas.\n";
        }
    } while (palpite != numeroSecreto);
}
