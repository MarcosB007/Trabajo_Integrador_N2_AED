#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo3.h"

int MenuPrincipal();
void cargarVeterinario(FILE *archVet);

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	FILE *veterinarios = fopen("Veterinarios.dat","a+b");
	FILE *turnos = fopen("Turnos.dat","a+b");
	FILE *mascotas = fopen("Mascotas.dat","a+b");
	
	int n=1;
	bool verificar = false;
	Usuarios lectura;
	
	rewind(usuarios);
	fread(&lectura, sizeof(lectura), 1, usuarios);
	while(!feof(usuarios)){
		
		verificar = true;
		
		fread(&lectura, sizeof(lectura), 1, usuarios);
	}
	
	if(verificar == false){
 		registrar(usuarios, n); 
		verificar = true;
	}
	
	system("cls");
	InicioSesion(usuarios, n);
	
	int opcion;
	int opc;
	
	if(verificar == true){
	
	do{
 	    int n=0; 
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1:
	 			   cargarVeterinario(veterinarios);
			break;
			
			case 2:
				   registrar(usuarios, n);
			break;
			
			case 3:	
				 	AtencionVeterinario(turnos);
			break;
		}
		
	}while(opcion !=5);
	
	}
	
	fclose(usuarios);
	system("\n\npause");
}

int MenuPrincipal(){
		
		int opc;
		system ("cls");
		printf ("\t*************************************");
		printf ("\n\t* MENU DE OPCIONES DE ADMINISTRADOR *");
		printf ("\n\t*************************************\n");
		printf ("\n1) Registrar un Nuevo Veterinario");
		printf ("\n2) Registrar un Nuevo Usuario Asistente");
		printf ("\n3) Atenciones por Veterinario");
		printf ("\n4) Ranking de Veterinarios por Atencion");
		printf ("\n5) Cerrar Aplicacion");
		printf ("\n\nOpcion: ");
		scanf ("%d",&opc);
		return opc;
}

void cargarVeterinario(FILE *archVet)
{	
	Veterinario vet;
	cadena userAux, passAux;
	int cantidad=0;
	bool primerLetra = false;
	int Band = 0;
	
	system ("cls");
	printf ("\tREGISTRAR VETERINARIO\n\n");
	printf ("Apellido y Nombre: ");
	_flushall();
	gets (vet.ApeyNom);
	printf ("DNI: ");
	scanf ("%d",&vet.DNI);
	printf("Matricula: ");
	_flushall();
	gets (vet.matricula);
	printf ("\nIngrese la fecha de Nacimiento\n\n");
	printf ("Dia: ");
	scanf ("%d",&vet.fech.dia);
	printf ("Mes: ");
	scanf ("%d",&vet.fech.mes);
	printf ("Anio: ");
	scanf ("%d",&vet.fech.anio);
	vet.edad = 2020 - vet.fech.anio; 
	
	user(archVet, userAux);
	strcpy(vet.Usuario,userAux);
	
	password(archVet, passAux);
	strcpy(vet.Contrasena, passAux);
	
	fwrite(&vet, sizeof(Veterinario), 1, archVet);
	
}
