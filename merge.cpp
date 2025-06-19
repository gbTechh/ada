#include <iostream>
#include <vector>

// Función para fusionar dos subarreglos ordenados
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Tamaños de los subarreglos
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Crear arreglos temporales
    std::vector<int> L(n1), R(n2);

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Fusionar los arreglos temporales de vuelta al arreglo original
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copiar elementos restantes de L (si hay)
    while (i < n1)
        arr[k++] = L[i++];

    // Copiar elementos restantes de R (si hay)
    while (j < n2)
        arr[k++] = R[j++];
}

// Función principal de Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Dividir el arreglo en mitades
        int mid = left + (right - left) / 2;

        // Aplicar mergeSort recursivamente a cada mitad
        mergeSort(arr, left, mid);       // mitad izquierda
        mergeSort(arr, mid + 1, right);  // mitad derecha

        // Combinar las mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Función auxiliar para imprimir el arreglo
void printArray(const std::vector<int>& arr) {
    for (int val : arr)
        std::cout << val << " ";
    std::cout << "\n";
}

// Función principal
int main() {
    std::vector<int> datos = {12, 11, 13, 5, 6, 7};

    std::cout << "Antes del Merge Sort:\n";
    printArray(datos);

    mergeSort(datos, 0, datos.size() - 1);

    std::cout << "Después del Merge Sort:\n";
    printArray(datos);

    return 0;
}
