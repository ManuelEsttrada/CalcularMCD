/**
*@file mcd.c 
*@brief Este programa calcula el MCD entre dos numeros  
*@author Equipo Ecuaciones diferenciales
*@date 18 Ago 2022
**/

//DECLARACIÓN DE BIBLIOTECAS
#include <stdio.h>
#include <time.h>

//PROTOTIPOS DE FUNCIÓN
int calcularMCD(int num1, int num2);
int recursivo(int num1, int num2);

//VARIABLES GLOBALES 
int contador1=0, contador2=0; 

//MAIN
int main(){
	int numero1, numero2, resultado=0;

    	printf("\n---MCD MEDIANTE ALGORITMO DE EUCLIDES ---\n");
    	printf("\nEste programa cálcula y compara la eficiencia\ndel algoritmo de Euclides para el MCD mediante\n iteraciones y recursividad\n");
		printf("\nEscribe el primer numero: ");
		scanf(" %d", &numero1);  
    	printf("\nEscribe el segundo numero: ");
		scanf(" %d", &numero2);
        printf("\nITERATIVO\n");
    	clock_t marca1 = clock();
		resultado=calcularMCD(numero1, numero2);
		clock_t marca2 = clock();
        printf("\nIteraciones: %i\n", contador1);
        printf("\nEl MCD de %d y %d es: %d\n", numero1, numero2, resultado);
		printf("Tiempo de ejecución: %f segundos\n", (double)(marca2 - marca1) / CLOCKS_PER_SEC);
        printf("\nRECURSIVO\n");
    	clock_t marca3 = clock();
        resultado=recursivo(numero1, numero2);
    	clock_t marca4 = clock();
        printf("\nIteraciones: %i\n", contador2);
        printf("\nEl MCD de %d y %d es: %d\n", numero1, numero2, resultado);
    	printf("Tiempo de ejecución: %f segundos\n", (double)(marca4 - marca3) / CLOCKS_PER_SEC);
        printf("\n----------------------------------------\n");

return 0;
}
/**
*@brief Esta función calcula el MCD  de dos numeros
	mediante iteraciones
*@author Equipo Ecuaciones diferenciales
*@date 18 Ago 2022
*@param num1, dato entero para en dividendo
*@param num2, dato entero para en divisor
*@return num1, dato entero para el MCD
**/
int calcularMCD(int num1, int num2){
	int temp;
		while(num2 != 0){//Se valida que el residuo o el primer numero no sea cero
			contador1++;
			temp=num2;//se guarda temporalmente num2
			num2=num1%num2;
			num1=temp;//se asigna num2 para ahora ser el dividendo
		}
	return num1;
}

/**
*@brief Esta función calcula el MCD  de dos numeros
	mediante recursividad
*@author Equipo Ecuaciones diferenciales
*@date 18 Ago 2022
*@param num1, dato entero para en dividendo
*@param num2, dato entero para en divisor
*@return auxiliar, dato entero para el MCD
**/
int recursivo(int num1, int num2){
	int  auxiliar;
		if(num2==0){//Ae valida que el residuo no sea cero
			return num1;
		}
		contador2++;
		auxiliar=recursivo(num2, num1%num2);//Se hace llamado recursivo con num2 y e residuo
	return auxiliar;
}
