#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo3.h"

int MenuPrincipal();
void cargarVeterinario(FILE *veterinarios);

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
				 	AtencionVeterinario(turnos); //aqui
			break;
			
			case 4: 
				 	RankingAtenciones(turnos, veterinarios);
			break;
			
			case 5:
					printf ("\nSaliendo del programa...\n\n");
			break;
			
			default:
					printf ("\nLa opcion elegida no es valida. Vuelva a intentarlo...\n\n");
					system ("pause");
					system ("cls");
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
		printf ("\t\t\t\t==========================================\n");
		printf ("\t\t\t\t==   MENU DE OPCIONES DE ADMINISTRADOR  ==\n");
		printf ("\t\t\t\t==========================================\n");
		printf ("________________________________________________\n");
		printf ("| 1) Registrar un Nuevo Veterinario             |\n");
		printf ("| 2) Registrar un Nuevo Usuario Asistente       |\n");
		printf ("| 3) Atenciones por Veterinario                 |\n");
		printf ("| 4) Ranking de Veterinarios por Atencion       |\n");
		printf ("| 5) Cerrar Aplicacion                          |\n");
		printf ("|_______________________________________________|\n");
		printf ("\nOpcion: ");
		scanf ("%d",&opc);
		return opc;
}

void cargarVeterinario(FILE *veterinarios)
{	
	Veterinario vet;
	cadena userAux, passAux;
	int cantidad=0;
	bool primerLetra = false;
	int Band = 0;
	
	system ("cls");
	printf ("\t\t\t\t\t================================\n");
	printf ("\t\t\t\t\t==   REGISTRAR VETERINARIO   ===\n");
	printf ("\t\t\t\t\t================================\n");
	printf ("Apellido y Nombre: ");
	_flushall();
	gets (vet.ApeyNom);
	printf ("DNI: ");
	scanf ("%d",&vet.DNI);
	printf("Matricula: ");
	_flushall();
	gets (vet.matricula);
	printf ("\nIngrese la fecha de Nacimiento\n");
	printf ("Dia: ");
	scanf ("%d",&vet.fech.dia);
	printf ("Mes: ");
	scanf ("%d",&vet.fech.mes);
	printf ("Anio: ");
	scanf ("%d",&vet.fech.anio);
	vet.edad = 2020 - vet.fech.anio; 
	_flushall();
	user(veterinarios, userAux);
	strcpy(vet.Usuario,userAux);
	
	password(veterinarios, passAux);
	strcpy(vet.Contrasena, passAux);
	
	fwrite(&vet, sizeof(Veterinario), 1, veterinarios);
	printf("Los datos del veterinario fueron cargados con exito.");
	printf("\n\n");
	system("pause");
	
}
