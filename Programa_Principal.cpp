#include "VerificarAdmin.h"
#include "Modulo3.h"
#include "Modulo_Consultorio.h"
//#include "Modulo2.h"

int MenuPrincipal();
void menuAdministrador(FILE *archVet);
//void menuConsultorio(FILE *archVet);

bool verificar = false;

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	FILE *veterinarios = fopen("Veterinarios.dat","a+b");
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
	 			   menuConsultorio(veterinarios);
			break;
			
			case 2:
			break;
			
			case 3:	
				 	menuAdministrador(veterinarios);
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
	printf("4.- SALIR\n");
	printf("4.- Ingrese una opcion: ");
	scanf("%d", &opc);
	return opc;
}







