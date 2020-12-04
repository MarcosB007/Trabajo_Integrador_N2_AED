#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "VerificarAdmin.h"

int MenuPrincipal();

bool verificar = false;

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	char lectura;
	
	rewind(usuarios);
	fread(&lectura, sizeof(lectura), 1, usuarios);
	while(!feof(usuarios)){
		
		verificar = true;
		
		fread(&lectura, sizeof(lectura), 1, usuarios);
	}
	
	if(verificar == false){
		registrar(usuarios);
		verificar = true;
	}
	system("cls");
	
	InicioSesion(usuarios);
	
	int opcion;
	int opc;
	
	if(verificar == true){
	
	do{
	
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1: 
			break;
			
			case 2:
			break;
			
			case 3:	
			break;
		}
		
	}while(opcion !=4);
	
	}
	else{
		printf("Nombre de usuario o contraseña incorrecta.");
	}
	
	fclose(usuarios);
	system("\n\npause");
}

int MenuPrincipal(){
	system("cls");
	int opc;
	printf("1.- MODULO CONSULTORIO\n");
	printf("2.- MODULO DEL ASISTENTE\n");
	printf("3.- MODULO DE ADMINISTRACION\n");
	printf("4.- SALIR");
	scanf("%d", &opc);
	return opc;
}

/*int MenuConsultorio(){
	
	system("cls");
	int opc;
	printf("1.- Iniciar sesion\n");
	printf("2.- Visualizar Lista de Espera de Turnos\n");
	printf("3.- Registrar Evolución de la Mascota\n\n");
	printf("4.- Cerrar la aplicación\n");
	scanf("%d", &opc);
	return opc;
	
}*/











