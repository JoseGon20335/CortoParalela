g++ generadorDeNumeros.cpp -o generadorDeNumeros
g++ quicksortSecuencial.cpp -o quicksortSecuencial -std=c++11
g++ quicksortParalela.cpp -o quicksortParalela -std=c++11 -fopenmp

./generadorDeNumeros 10
./quicksortParalela
./quicksortSecuencial
