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
	rewind(usuarios);
	//verifica si ya hay un usuario registrado
	fread(&lectura, sizeof(lectura), 1, usuarios);
	while(!feof(usuarios)){
		
		verificar = true;
		
		fread(&lectura, sizeof(lectura), 1, usuarios);
	}
	//caso que no exista ningun usuario, permite cargar uno
	if(verificar == false){
		registrar(usuarios);
		verificar = true;
	}
	else{
		
		do{
		   rewind(usuarios);
		   printf("\nINICIO DE SESION\n");
		   printf("\nNmbre de usuario: ");
		   _flushall();
		   gets(nombreUsuario);
		
		   Usuarios lect;
			   				
			fread(&lect, sizeof(lect), 1, usuarios);
			   				
			while(!feof(usuarios)){
			   					
				if(lect.nomUsuario == nombreUsuario){
					verificar = true;
				break;
				}
			
				fread(&lect, sizeof(lect), 1, usuarios);
			}
			if(verificar == false){
				printf("Nombre de usuario incorrecto.");
			}
			
		}while(verificar == false);
	}
	
	
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

void registrar(FILE *usuario){
	
	Usuarios admin, lectura;;
	int longitud, contadorMayus=0, contadorNum=0;
	bool bandera = false;
		
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
	
	
	do{
		printf("\nIngrese su nombre de usuario: ");
		gets(admin.nomUsuario);
		longitud = strlen(admin.nomUsuario);
		if(longitud > 5 && longitud < 11){
		
			if(admin.nomUsuario[0] > 97 && admin.nomUsuario[0] < 123){
			
				for(int i=0; i<strlen(admin.nomUsuario); i++){
					//printf("%c", admin.nomUsuario[i]);
				
					if(admin.nomUsuario[i] > 64 && admin.nomUsuario[i] < 91){
					contadorMayus+=1;
					}
				}
			
					if(contadorMayus > 1){
						for(int i=0; i<strlen(admin.nomUsuario); i++){
							//printf("%c", admin.nomUsuario[i]);
				
			 				if(admin.nomUsuario[i] > 47 && admin.nomUsuario[i] < 58){
			   					contadorNum+=1;
							}
						}
						
						if(contadorNum < 4){
			   			    bandera = true;
			   				
			   				/*rewind(usuario);
			   				fread(&lectura, sizeof(lectura), 1, usuario);
			   				
			   				while(!feof(usuario)){
			   					
			   					if(strcmp(admin.nomUsuario, lectura.nomUsuario) == 0){
			   						bandera = false;
								}
									
			   					fread(&lectura, sizeof(lectura), 1, usuario);*/
							}
			   				//valida que no exista un usuario igual
						}
					}
			}
		if(bandera == false){
			printf("\nEl nombre de usuario ingresado no cumple con alguna de las condiciones dadas.");
			printf("\nVuelva a intentar.");
		}
	}while(bandera == false);
	
	fwrite(&admin, sizeof(admin), 1, usuario);
}







