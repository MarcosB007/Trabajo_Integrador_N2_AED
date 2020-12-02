#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[50];

struct Usuarios{
	char Apellido_Y_Nombre[60];
	char nomUsuario[10];
	char contrasenia[10];
};

int MenuPrincipal();
int MenuConsultorio();
int MenuAsistente();
int MenuAdministracion();
void registrar(FILE *usuario);

bool verificar = false;

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	char lectura;
	cadena nombreUsuario, contr;
	
	//verifica si ya hay un usuario registrado
	fread(&lectura, sizeof(lectura), 1, usuarios);
	while(!feof(usuarios)){
		
		verificar = true;
		
		fread(&lectura, sizeof(lectura), 1, usuarios);
	}
	//caso contrario, permite cargar un usuario
	if(verificar == false){
		registrar(usuarios);
	}
	else{
		printf("\nINICIO DE SESION\n");
		printf("\nNmbre de usuario: ");
		_flushall();
		gets(nombreUsuario);
		//comprobar nombre de usuario
		printf("\nContraseña: ");
		gets(contr);
		//comprobar contraseña
	}
	
	
	int opcion;
	int opc;
	if(verificar == true){

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
	
	}
	fclose(usuarios);
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

void registrar(FILE *usuario){
	
	Usuarios admin;
		
	printf("\nREGISTRARSE\n");
	printf("\nNombre y Apellido: ");
	_flushall();
	gets(admin.Apellido_Y_Nombre);
	
	printf("\nNombre de Usuario: ");
	printf("\nAVISOS IMPORTANTES!\n");
	printf("\nEl nombre de usuario debe tener entre 6 y 10 caracteres");
	printf("\nDebe comenzar con una letra minuscula");
	printf("\nTener al menos 2 letras mayusculas");
	printf("\nTener como maximo 3 digitos");
	printf("\nIngrese su nombre de usuario: ");
	gets(admin.nomUsuario);
	//validar las restricciones
	
	printf("\nContraseña: ");
	printf("\nAVISOS IMPORTANTES!\n");
	printf("\nDeberá contener al menos una letra mayúscula, una letra minúscula y un número");
	printf("\nNo podrá contener ningún carácter de puntuación, ni acentos, ni espacios. Sólo caracteres alfanuméricos. ");
	printf("\nDeberá tener entre 6 y 32 caracteres.");
	printf("\nNo debe tener más de 3 caracteres numéricos consecutivos.");
	printf("\nNo debe tener 2 caracteres consecutivos que refieran a letras alfabéticamente consecutivas (ascendentemente).");
	gets(admin.contrasenia);
	//validar restricciones
	fwrite(&admin, sizeof(admin), 1, usuario);
}







