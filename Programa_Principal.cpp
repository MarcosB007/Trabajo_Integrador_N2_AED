#include "VerificarAdmin.h"
#include "Modulo3.h"
//#include "Modulo_Consultorio.h"
//#include "Modulo2.h"

int MenuPrincipal();
void menuAdministrador(FILE *archVet);

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

void menuAdministrador(FILE *archVet)
{
	int opc;
	do
	{
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
		
		switch (opc)
		{
			case 1:	cargarVeterinario(archVet);
				 	printf ("\n\n");
					system ("pause");
				
				break;
			case 2:
				
				break;
			case 3:	
				 	
				
				break;
			case 4:
				
				break;
			case 5:
				printf ("\nSaliendo del programa...\n\n");
				system ("pause");
				break;
			default:
				printf ("\n[Advertencia]: La opcion elegida no es valida, vuelva a ingresar\n\n");
				system ("pause");
		}
	}while (opc != 5);
}









