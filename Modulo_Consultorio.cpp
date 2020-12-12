#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Modulo1.h"

int MenuPrincipal();

main()
{
	FILE *veterinarios = fopen("Veterinarios.dat","a+b");
	FILE *turno = fopen("Turnos.dat","a+b");
	FILE *mascotas = fopen("Mascotas.dat","a+b");
	
	int opcion;
	int opc, D, M, A;
	bool verificar = false;
	bool bandera = false;
	char ApeNomMascota[50];
	char veterinarioAtendiendo[50];
	turnos t;
	
	do{
	   
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1:
   				   IndentificarVeterinario(veterinarios, veterinarioAtendiendo);
   				   verificar = true;
			break;
			
			case 2:
				   if(verificar == true){
				   		
				   		ListarTurnos(turno);
			   			
				   }
				   else{
				   	printf("Debe iniciar sesion.");
				   }
			break;
			
			case 3:	
				 	if(verificar == true){
				   		
				   		evolucionMascota(mascotas, turno);
			   			
						/*rewind(turno);
				   		fread(&t, sizeof(turnos), 1, turno);
						while(!feof(turno)){
						if(t.turnoAtendido == true){
							printf("\nmuestra: %s", t.detalleAtencion);
						}
						
						fread(&t, sizeof(turnos), 1, turno);
						system("pause");
						}*/
				   }
				   else{
				   	printf("Debe iniciar sesion.");
				   }
			break;
		}
		printf("\n");
		system("pause");
		
	}while(opcion !=4);
	

	
	fclose(veterinarios);
	fclose(turno);
	fclose(mascotas);
	system("\n\npause");
}

int MenuPrincipal(){
		
		int opc;
		system ("cls");
		printf ("\t*************************************");
		printf ("\n\t* MENU DE OPCIONES DEL CONSULTORIO *");
		printf ("\n\t*************************************\n");
		printf("1.- Iniciar sesion\n");
		printf("2.- Visualizar Lista de Espera de Turnos\n");
		printf("3.- Registrar Evolución de la Mascota\n\n");
		printf("4.- Cerrar la aplicacion\n");
		printf("\nIngrese una opcion: ");
		scanf ("%d",&opc);
		return opc;
}




