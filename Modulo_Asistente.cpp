#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo3.h"
#include "Modulo2.h"

int MenuPrincipal();

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	FILE *veterinarios = fopen("Veterinarios.dat","a+b");
	FILE *turnos = fopen("Turnos.dat","a+b");
	FILE *mascotas = fopen("Mascotas.dat","a+b");
	
	int opcion;
	int opc, D, M, A, n=0;
	bool verificar = false;
	
	do{
	   system("cls");
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1:
   				   InicioSesion(usuarios, n);
   				   verificar = true;
			break;
			
			case 2:
				   	if(verificar == true){
				  		CargarMascotas(mascotas);
				  	}
				  	else{
				  		printf("Debe iniciar sesion.");
				  	}
			break;
			
			case 3:	
				 	if(verificar == true){
				  		cargaTurnos(turnos, veterinarios, mascotas);
				  	}
				  	else{
				  		printf("Debe iniciar sesion.");
				  	}
			break;
			case 4:
			if(verificar == true){
				ListarTurno(turnos, veterinarios);
			}
			else{
				printf("Debe iniciar sesion.");
			}
			break;
			case 5:
				printf("Saliendo del modulo");
				break;
		}
		
		printf("\n");
		system("pause");
		
	}while(opcion !=5);
	
	
	fclose(usuarios);
	
}

int MenuPrincipal(){
		
		int opc;
		system ("cls");
		printf("\n\t*******************************************************************");
		printf("\n\t\t\t\tModulo del asistente");
		printf("\n\t*******************************************************************");
		printf("\n 1 --> Iniciar Sesion");
		printf("\n 2 --> Registrar Mascotas");
		printf("\n 3 --> Registrar Turno");
		printf("\n 4 --> Listado de atencion por veterinario y fecha");
		printf("\n 5 --> Cerrar modulo");
		printf("\n*******************************************************************");
		printf("\nIngrese la opcion deseada:");
		scanf ("%d",&opc);
		return opc;
}
