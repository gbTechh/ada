/*
1. Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un
conjunto de contenedores c1, …, cn cuyos pesos respectivos son p1, …, pn
(expresados también en toneladas). Teniendo en cuenta que la capacidad del
buque es menor que la suma total de los pesos de los contenedores:
a. Diseñe un algoritmo que maximice el número de contenedores cargados.
b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

// Contenedor con peso
struct Contenedor {
    int id;
    double peso;
};

// a) Máximo número de contenedores cargados
void cargarMaxContenedores(std::vector<Contenedor>& contenedores, double capacidad) {
    std::sort(contenedores.begin(), contenedores.end(),
              [](Contenedor a, Contenedor b) { return a.peso < b.peso; });

    double suma = 0;
    std::vector<int> cargados;

    for (auto& c : contenedores) {
        if (suma + c.peso <= capacidad) {
            suma += c.peso;
            cargados.push_back(c.id);
        }
    }

    std::cout << "Contenedores cargados (max número): ";
    for (int id : cargados) std::cout << id << " ";
    std::cout << " | Total cargado: " << suma << " toneladas\n";
}

// b) Máximas toneladas cargadas
void cargarMaxPeso(std::vector<Contenedor>& contenedores, double capacidad) {
    std::sort(contenedores.begin(), contenedores.end(),
              [](Contenedor a, Contenedor b) { return a.peso > b.peso; });

    double suma = 0;
    std::vector<int> cargados;

    for (auto& c : contenedores) {
        if (suma + c.peso <= capacidad) {
            suma += c.peso;
            cargados.push_back(c.id);
        }
    }

    std::cout << "Contenedores cargados (max peso): ";
    for (int id : cargados) std::cout << id << " ";
    std::cout << " | Total cargado: " << suma << " toneladas\n";
}


/*
2. Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si
 megabytes de espacio y la capacidad del disco es D megabytes,
siendo D < ΣSi
. Resuelva las siguientes cuestiones:
a. Diseñe un algoritmo greedy que maximice el número de programas
almacenados en el disco (existe un algoritmo que proporciona una
solución óptima).
b. Diseñe un algoritmo greedy que intente aprovechar al máximo la
capacidad del disco (demuestre que podemos utilizar un algoritmo
greedy que seleccione los programas por orden no creciente para obtener
la solución exacta o encuentre un contraejemplo de lo contrario). 
*/

struct Programa {
    int id;
    int tamaño;
};

// a) Máximo número de programas
void guardarMaxProgramas(std::vector<Programa>& programas, int capacidad) {
    std::sort(programas.begin(), programas.end(),
              [](Programa a, Programa b) { return a.tamaño < b.tamaño; });

    int usado = 0;
    std::vector<int> guardados;

    for (auto& p : programas) {
        if (usado + p.tamaño <= capacidad) {
            usado += p.tamaño;
            guardados.push_back(p.id);
        }
    }

    std::cout << "Programas almacenados (max número): ";
    for (int id : guardados) std::cout << id << " ";
    std::cout << " | Espacio usado: " << usado << " MB\n";
}

// b) Intentar aprovechar al máximo el espacio
void guardarMaxEspacio(std::vector<Programa>& programas, int capacidad) {
    std::sort(programas.begin(), programas.end(),
              [](Programa a, Programa b) { return a.tamaño > b.tamaño; });

    int usado = 0;
    std::vector<int> guardados;

    for (auto& p : programas) {
        if (usado + p.tamaño <= capacidad) {
            usado += p.tamaño;
            guardados.push_back(p.id);
        }
    }

    std::cout << "Programas almacenados (max espacio): ";
    for (int id : guardados) std::cout << id << " ";
    std::cout << " | Espacio usado: " << usado << " MB\n";
}




/*
3. Tenemos que completar un conjunto de n tareas con plazos límite. Cada una de
las tareas consume la misma cantidad de tiempo (una unidad) y, en un instante
determinado, podemos realizar únicamente una tarea. La tarea i tiene como
plazo límite di
 y produce un beneficio gi
 (gi
 > 0) sólo si la tarea se realiza en un
instante de tiempo t ≤ di
.
a. Diseñe un algoritmo greedy que nos permita seleccionar el conjunto de
tareas que nos asegure el mayor beneficio posible.
b. Aplique su algoritmo a la siguiente instancia del problema:
Tarea i 1 2 3 4
 Beneficio gi
 50 10 15 30
Plazo límite di
 2 1 2 1 
*/

#include <set>

struct Tarea {
    int id;
    int beneficio;
    int plazo;
};

// Ordenar por mayor beneficio
bool compararBeneficio(const Tarea& a, const Tarea& b) {
    return a.beneficio > b.beneficio;
}

// a) Algoritmo greedy
void planificarTareas(std::vector<Tarea> tareas) {
    std::sort(tareas.begin(), tareas.end(), compararBeneficio);

    int tiempoMax = 0;
    for (auto& t : tareas)
        tiempoMax = std::max(tiempoMax, t.plazo);

    std::vector<int> calendario(tiempoMax + 1, -1);
    int beneficioTotal = 0;

    for (auto& tarea : tareas) {
        for (int t = tarea.plazo; t >= 1; --t) {
            if (calendario[t] == -1) {
                calendario[t] = tarea.id;
                beneficioTotal += tarea.beneficio;
                break;
            }
        }
    }

    std::cout << "Tareas seleccionadas: ";
    for (int i = 1; i <= tiempoMax; ++i)
        if (calendario[i] != -1)
            std::cout << calendario[i] << " ";
    std::cout << "| Beneficio total: " << beneficioTotal << "\n";
}

// b) Aplicar algoritmo a caso concreto
void pruebaTareasEj3() {
    std::vector<Tarea> tareas = {
        {1, 50, 2},
        {2, 10, 1},
        {3, 15, 2},
        {4, 30, 1}
    };
    planificarTareas(tareas);
}


int main() {
    // Ejercicio 1
    std::vector<Contenedor> contenedores = {{1, 4.5}, {2, 3.0}, {3, 2.0}, {4, 5.5}};
    double capacidad = 10.0;
    cargarMaxContenedores(contenedores, capacidad);
    cargarMaxPeso(contenedores, capacidad);

    // Ejercicio 2
    std::vector<Programa> programas = {{1, 20}, {2, 5}, {3, 15}, {4, 25}};
    int disco = 30;
    guardarMaxProgramas(programas, disco);
    guardarMaxEspacio(programas, disco);

    // Ejercicio 3
    pruebaTareasEj3();

    return 0;
}
