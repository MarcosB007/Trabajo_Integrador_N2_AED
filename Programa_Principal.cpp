#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int MenuPrincipal();
int MenuConsultorio();
int MenuAsistente();
int MenuAdministracion();

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
				 	   	
				 	   	case 1: 
				 	   	break;
				 	   	
				 	   	case 2:
			 	   		break;
			 	   		
			 	   		case 3:
			 	   		break;
   			   		   //agregar llamado a las correspondientes funciones
						}
				 	}while(opc =! 4);
			break;
			
			case 2: do{
				 	   opc = MenuAsistente();
					   
					   switch(opc){
					   	
					   	case 1:
				   		break;
				   		
				   		case 2:
			   			break;
			   			
			   			case 3:
		   				break;
		   				
		   				case 4:
	   					break;
					   	
					   }
				
					}while(opc != 5);
			break;
			
			case 3:	do{
				 	    opc = MenuAdministracion();
				 		
				 		switch(opc){
			 			
			 			case 1:
		 				break;
		 				
		 				case 2:
	 					break;
			 			
			 			case 3:
		 				break;
		 				
		 				case 4:
	 					break;
	 					}	
				 	
				 	}while(opc != 5);
			
			break;
		}
		
	}while(opcion !=4);
	
	system("\n\npause");
}

int MenuPrincipal(){
	system("cls");
	int opc;
	printf("1 --> MODULO CONSULTORIO\n");
	printf("2 --> MODULO DEL ASISTENTE\n");
	printf("3 --> MODULO DE ADMINISTRACION\n");
	scanf("%d", &opc);
	return opc;
}

int MenuConsultorio(){
	
	system("cls");
	int opc;
	printf("1.- Iniciar sesion\n");
	printf("2.- Visualizar Lista de Espera de Turnos\n");
	printf("3.- Registrar Evolución de la Mascota\n\n");
	printf("4.- Cerrar la aplicación\n");
	scanf("%d", &opc);
	return opc;
	
}

int MenuAsistente(){
	
	system("cls");
	int opc;
	printf("1.- Iniciar sesion\n");
	printf("2.- Registrar mascota\n");
	printf("3.- Registrar turno\n");
	printf("4.- Listado de Atenciones por Veterinario y Fecha \n\n");
	printf("5.- Cerrar la aplicación\n");
	scanf("%d", &opc);
	return opc;
}

int MenuAdministracion(){
	
	system("cls");
	int opc;
	printf("1.- Registrar Vetrinario\n");
	printf("2.- Registrar Usuario Asitente\n");
	printf("3.- Atenciones por veterinarios\n");
	printf("4.- Ranking de Veterinarios por Atenciones\n\n");
	printf("5.- Cerrar la aplicación\n");
	scanf("%d", &opc);
	return opc;
	
}


