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
	bool verificar = false;
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
				   fclose(turno);
				   if(verificar == true){
				   		
				   		ListarTurnos(turno);
			   			
				   }
				   else{
				   	printf("Debe iniciar sesion.");
				   }
				   turno = fopen("Turnos.dat","a+b");
			break;
			
			case 3:	
				 	fclose(turno);
				 	if(verificar == true){
				   		
				   		evolucionMascota(turno);
						
				   }
				   else{
				   	printf("Debe iniciar sesion.");
				   }
				   turno = fopen("Turnos.dat","a+b");
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
		system("cls");
		printf("\t\t\t\t=======================================\n");
		printf("\t\t\t\t== MENU DE OPCIONES DEL CONSULTORIO  ==\n");
		printf("\t\t\t\t=======================================\n");
		printf("______________________________________________________\n");
		printf("| 1).- Iniciar sesion                                 |\n");
		printf("| 2).- Visualizar Lista de Espera de Turnos           |\n");
		printf("| 3).- Registrar Evolución de la Mascota              |\n");
		printf("| 4).- Cerrar la aplicacion                           |\n");
		printf("|_____________________________________________________|\n");
		printf("\nIngrese una opcion: ");
		scanf ("%d",&opc);
		return opc;
}




