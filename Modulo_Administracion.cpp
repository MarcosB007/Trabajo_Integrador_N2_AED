#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct veterinario{
	char ApeNom[60];
	int matricula;
	int DNI;
	char telefono[25];
};

int menuPrincipal();

main(){
	
	veterinario vet;
	
}

int menuPrincipal(){
	int opcion=0;
	system("cls");
	
	printf("1.- Registrar veterinario");
	printf("2.- Registrar usuario asistente");
	printf("3.- Atencion por veterinarios");
	printf("4.- Ranking de veterinarios por atencion\n");
	printf("5.- Cerrar la aplicacion\n");
	
	printf("Ingrese una opcion: ");
	scanf("%d", &opcion);
	return opcion;
}
