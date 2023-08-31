EJECUTAR
sh ejecutar.sh

g++ generadorDeNumeros.cpp -o generadorDeNumeros

g++ quicksortSecuencial.cpp -o quicksortSecuencial -std=c++11

g++ quicksortParalela.cpp -o quicksortParalela -std=c++11 -fopenmp

./generadorDeNumeros <#numeros>

./quicksortParalela

./quicksortSecuencial


--------------------------------------------------------------------------------------------------------------


CORTO:
- PRUEBA1: 10
![image](https://github.com/JoseGon20335/CortoParalela/assets/100246655/447a950c-2712-4496-9f37-8af3001c02d7)

- PRUEBA2: 100
![image](https://github.com/JoseGon20335/CortoParalela/assets/100246655/8607ff49-0766-485b-8db7-1daa4667f5d7)

- PRUEBA3:1,000
![image](https://github.com/JoseGon20335/CortoParalela/assets/100246655/d6e93f04-5f39-443a-b03d-1f228b74e4ac)

- PRUEBA4:10,000
![image](https://github.com/JoseGon20335/CortoParalela/assets/100246655/9b90261e-a6e2-41de-ae60-22bb04ec489b)

- PRUEBA5:100,000
![image](https://github.com/JoseGon20335/CortoParalela/assets/100246655/fcb4dc02-a8cf-4581-9881-b0210fb34d16)
