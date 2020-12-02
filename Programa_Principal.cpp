#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MenuPrincipal();
int MenuConsultorio();

main()
{
	
	int opcion;
	int opc;
	
	do{
	
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1: do{
				 	   opc = MenuConsultorio();
				 	   switch(opc){
   			   		   //agregar llamado a las correspondientes funciones
						}
				 	}while(opc =! 4);
			break;
		}
		
	}while(opcion !=4);
	
	system("\n\npause");
}

int MenuPrincipal(){
	system("cls");
	int opc;
	printf("1 --> MODULO CONSULTORIO");
	printf("1 --> MODULO DEL ASISTENTE");
	printf("1 --> MODULO DE ADMINISTRACION");
	scanf("%d", &opc);
	return opc;
}

int MenuConsultorio(){
	
	system("cls");
	int opc;
	printf("1.- Iniciar sesion");
	printf("2.- Visualizar Lista de Espera de Turnos");
	printf("3.- Registrar Evolución de la Mascota\n");
	printf("4.- Cerrar la aplicación");
	scanf("%d", &opc);
	return opc;
	
}






