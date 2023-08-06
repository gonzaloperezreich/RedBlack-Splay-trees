#include <iostream>
#include "RedBlack.cpp"  // Incluye Red Black Trees
using namespace std;

//Crea una vector aleatorio con numeros de [1,n] de tamaño m
vector<long long> generarPermutacionAleatoria(long long m, long long n) {
    int r = m/n;

    vector<long long> conjunto(m);
    for (long long i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            conjunto[j + i*r] = i + 1;
        }
    }
    
    // Generar una semilla aleatoria para el generador de números aleatorios
    random_device rd;
    mt19937 g(rd());
    
    // Mezclar los elementos del vector aleatoriamente
    shuffle(conjunto.begin(), conjunto.end(), g);
    
    // Retornar el vector permutado
    return conjunto;
}

int main(int argc, char** argv) { //Recibe x
    int x= strtod(argv[1], nullptr);
	long long M = pow(2, 28);
    long long N = pow(2, x);
    cout << "generamos permutaciones: "<< endl;
    //Generamos permutacion para insertar
    vector<long long> insertar = generarPermutacionAleatoria(N, N);
    
    //Generamos permutación para buscar
    vector<long long> buscar = generarPermutacionAleatoria(M, N);
    
    RBTree t;

    cout << "empieza insercion: "<< endl;
    // Insertamos los elementos en el red black tree
    for(long long i=1; i<N; i++){
        t.insert(insertar[i]);
    };
    
    clock_t start = clock();
    // Buscamos los elementos en el red black tree
    cout << "empieza busqueda: "<< endl;
    for(long long i=1; i<M; i++){
        t.searchTree(buscar[i]);
    };
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de busqueda: " << elapsed_time << " segundos" << endl;
	return 0;
}
