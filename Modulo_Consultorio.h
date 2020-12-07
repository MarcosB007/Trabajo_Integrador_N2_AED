void registrarVet(FILE *veterinario);

void menuConsultorio(FILE *veterinario)
{
	int opc;
	do
	{
		bool comprobante = false;
		
		system ("cls");
		printf ("\t*************************************");
		printf ("\n\t* MENU DE OPCIONES DEL CONSULTORIO *");
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
				   IndentificarVeterinario(veterinario, comprobante);
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

void registrarVet(FILE *veterinario){
	
	cadena user, password;
	
	printf("\nMatricula: ");
		_flushall();
		gets(user);
		printf("Contrasenia: ");
		gets(password);
	rewind(veterinario);
	
	
	
}






