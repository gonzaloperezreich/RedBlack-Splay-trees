#include "RedBlack.cpp"
using namespace std;

//Se crea la función f
long long f(long long i, double alpha) {
	long long x= floor(pow(i,alpha));
	return x;
}

//Se obtiene el valor SUMM
long long SUMM(long long N, double alpha) {
	long long x=0;
	for(int i=0; i<N;i++) {
		x+= f(i,alpha);
	}
	return x;
}

//Se obtiene la función phi, una versión normalizada de f
long long phi(long long i, long long suma,double alpha, long long M) {
	long long x= f(i,alpha);
	long long res = (M*x/suma);
	return res; 
}

//Crea una vector aleatorio con numeros de [1,n] de tamaño n
vector<long long> generarPermutacionAleatoria(long long n) {
    // Crear un vector con los elementos del conjunto [1, n]
    vector<long long> conjunto(n);
    for (long long i = 0; i < n; i++) {
        conjunto[i] = i + 1;
    }
    
    // Generar una semilla aleatoria para el generador de números aleatorios
    random_device rd;
    mt19937 g(rd());
    
    // Mezclar los elementos del vector aleatoriamente
    shuffle(conjunto.begin(), conjunto.end(), g);
    
    // Retornar el vector permutado
    return conjunto;
}


int main(int argc, char** argv) { //recibe x, alpha
    int x= strtod(argv[1], nullptr);
    long long N = pow(2,x);
    double alpha = strtod(argv[2], nullptr);
    long long M = pow(2,28);
	long long suma= SUMM(N,alpha);
	cout << "Valor de la suma: " << suma <<'\n';
    
	vector<long long> permutation = generarPermutacionAleatoria(N);
	vector<long long> newArray;
    newArray.reserve(static_cast<size_t>(M));
	// Índice para recorrer el vector de permutación
     for (size_t i = 0; i < permutation.size(); ++i) {
        long long element = permutation[i];
        //cout << "el elemento " << element << ' ';
        long long repetitions = phi(i, suma,alpha,M);
        //cout << "aparecerá "<< repetitions << " veces en el nuevo vector"<< '\n';
		// Inserta el elemento 'repetitions' veces en el nuevo vector
        for (long long j = 0; j < repetitions; ++j) {
            newArray.push_back(element);
        }
    }
    cout << "tamaño del arreglo nuevo es :" << newArray.size() << '\n';
    //--------------------------------------------------------------------> acá ya tenemos un vector desequilibrado, solo falta permutarlo sobre sí mismo
	// Semilla para el generador de números aleatorios
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    // Realiza la permutación aleatoria
    shuffle(newArray.begin(), newArray.end(), default_random_engine(seed));
    cout << "arreglo con skew permutado listo " << '\n';
    //-------------------------------------------------------------------> acá ya tenemos los verctore
    
    RBTree t;
    // Insertamos los elementos en el spay tree
    cout << "comienza el insert " << '\n';
    clock_t insert = clock();
    for(long long i=1; i<N; i++){
        t.insert(permutation[i]);
    };

    clock_t start = clock();
    double elapsed_time1 = double(start-insert) / CLOCKS_PER_SEC;
    cout << "Tiempo de insercion: " << elapsed_time1 << " segundos" << endl;
    // Buscamos los elementos en el spay tree
    cout << "comienza la busqueda " << '\n';
    for(long long i=1; i<M; i++){
        t.searchTree(newArray[i]);
    };
    
    clock_t end = clock();
    double elapsed_time = double(end - start) / CLOCKS_PER_SEC;
    cout << "Tiempo de busqueda: " << elapsed_time << " segundos" << endl;
	
    
    return 0;

}
