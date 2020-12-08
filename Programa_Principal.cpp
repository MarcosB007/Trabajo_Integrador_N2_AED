#include "VerificarAdmin.h"
#include "Modulo3.h"
#include "Modulo_Consultorio.h"
#include "Modulo2.h"

int MenuPrincipal();
void menuAdministrador(FILE *archVet);


bool verificar = false;

main()
{
	FILE *usuarios = fopen("Usuarios.dat","a+b");
	FILE *veterinarios = fopen("Veterinarios.dat","a+b");
	FILE *turnos = fopen("Turnos.dat","a+b");
	FILE *mascotas = fopen("Mascotas.dat","a+b");
	int n=1;
	char lectura;
	
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
	
		opcion = MenuPrincipal();
		
		switch(opcion){
			case 1:
	 			   menuConsultorio(veterinarios, turnos, mascotas);
			break;
			
			case 2:
				   MenuAsistente(turnos, mascotas, usuarios);
			break;
			
			case 3:	
				 	menuAdministrador(veterinarios, usuarios);
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







