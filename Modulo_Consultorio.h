typedef char cadena [50];

struct fechas
{
	int dia,mes,anio;	
};

struct persona
{
	char ApeyNom[50];
	char Usuario[50];
	char Contrasena[50];
	int edad;
	int DNI;
	bool ValidarUsuario = false;
	fechas fech;
};

void menuConsultorio()
{
	int opc;
	do
	{
		system ("cls");
		printf ("\t*************************************");
		printf ("\n\t* MENU DE OPCIONES DE ADMINISTRADOR *");
		printf ("\n\t*************************************\n");
		printf("1.- Iniciar sesion\n");
		printf("2.- Visualizar Lista de Espera de Turnos\n");
		printf("3.- Registrar Evolución de la Mascota\n\n");
		printf("4.- Cerrar la aplicación\n");
		printf("\nIngrese una opcion: ");
		scanf ("%d",&opc);
		
		switch (opc)
		{
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			case 4:
				printf ("\nSaliendo del programa...\n\n");
				system ("pause");
				break;
			default:
				printf ("\n[Advertencia]: La opcion elegida no es valida, vuelva a ingresar\n\n");
				system ("pause");
		}
	}while (opc != 4);
	
}
