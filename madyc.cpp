#include <iostream>
#include <map>

int main() {
    std::map<std::pair<int, int>, int> grafo;

    // Agregamos aristas
    grafo[{0, 1}] = 1;
    grafo[{1, 0}] = 1;
    grafo[{1, 2}] = 1;
    grafo[{2, 1}] = 1;

    // Verificar si hay conexión entre 0 y 1
    if (grafo[{0, 1}] == 1)
        std::cout << "Hay conexión entre 0 y 1\n";
    if (grafo[{0,2}] == 1)
        std::cout << "Hay conexión entre 0 y 1\n";

    return 0;
}
