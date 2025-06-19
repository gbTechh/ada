#include <iostream>
#include <vector>

// Función para dividir (partition)
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Elegimos el último elemento como pivote
    int i = low - 1; // Índice del elemento más pequeño

    for (int j = low; j < high; ++j) {
      if (arr[j] < pivot) {
        ++i;
        std::swap(arr[i], arr[j]); // Coloca los menores del lado izquierdo
      }
    }

    std::swap(arr[i + 1], arr[high]); // Coloca el pivote en su posición final
    return i + 1;
}

// QuickSort: método divide y vencerás
void quickSort(std::vector<int>& arr, int low, int high) {
  if (low < high) {
    // Divide: particiona el arreglo
    int pi = partition(arr, low, high);

    // Vence: aplica recursivamente a las sublistas
    quickSort(arr, low, pi - 1);  // izquierda del pivote
    quickSort(arr, pi + 1, high); // derecha del pivote
  }
}

// Función auxiliar para imprimir el arreglo
void printArray(const std::vector<int>& arr) {
    for (int val : arr)
        std::cout << val << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> datos = {10, 7, 8, 9, 1, 5};
    std::cout << "Antes del QuickSort:\n";
    printArray(datos);

    quickSort(datos, 0, datos.size() - 1);

    std::cout << "Después del QuickSort:\n";
    printArray(datos);

    return 0;
}
