EJECUTAR
sh ejecutar.sh

g++ generadorDeNumeros.cpp -o generadorDeNumeros
g++ quicksortSecuencial.cpp -o quicksortSecuencial -std=c++11
g++ quicksortParalela.cpp -o quicksortParalela -std=c++11 -fopenmp

./generadorDeNumeros <#numeros>
./quicksortParalela
./quicksortSecuencial

CORTO:
PRUEBA1: 10
PRUEBA2: 100
PRUEBA3:1,000
PRUEBA4:10,000
PRUEBA5:100,000
PRUEBA:1,000,000
