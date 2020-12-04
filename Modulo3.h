
typedef char cadena [50];

struct fechas
{
	int dia,mes,anio;	
};

struct persona
{
	char ApeyNom[50];
	char Usuario[50];
	int edad;
	int DNI;
	bool ValidarUsuario = false;
	fechas fech;
};

void opciones();
void cargarVeterinario (persona per);

main()
{
	opciones();
}

void opciones()
{
	persona per;
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
			case 1:
				cargarVeterinario(per);
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


void cargarVeterinario (persona per)
{
	bool primerLetra = false;
	
	system ("cls");
	printf ("\tREGISTRAR VETERINARIO\n\n");
	printf ("Apellido y Nombre: ");
	_flushall();
	gets (per.ApeyNom);
	printf ("Edad: ");
	scanf ("%d",&per.edad);
	printf ("DNI: ");
	scanf ("%d",&per.DNI);
	printf ("\nIngrese la fecha de Nacimiento\n\n");
	printf ("Dia: ");
	scanf ("%d",&per.fech.dia);
	printf ("Mes: ");
	scanf ("%d",&per.fech.mes);
	printf ("Anio: ");
	scanf ("%d",&per.fech.anio);
	do
	{
		int cantidad=0,contadorLetra=0,contadorNumero=0;
			
		system ("cls");
		printf ("\tIngrese un Nombre de Usuario para %s\n\n",per.ApeyNom);
		printf ("Cosas a tener en cuenta al crear un usuario\n\n");
		printf ("a) Debe ser un Nombre de 6 a 10 digitos\n");
		printf ("b) Comenzar con una letra Minuscula\n");
		printf ("c) Tener al menos dos letras Mayusculas\n");
		printf ("d) Tener como Maximo tres Numeros");
		printf ("\n\nIngrese el Nombre de Usuario: ");
		scanf ("%s",&per.Usuario);
		
		cantidad = strlen(per.Usuario);
		
		if (cantidad >= 6 && cantidad <= 10)
		{
			if (per.Usuario[0] > 63 && per.Usuario[0] < 91)
			{
				primerLetra = true;
			}
			for (int i=0; i<cantidad; i++)
			{
				if (per.Usuario[i] > 63 && per.Usuario[i] < 91)
				{
					contadorLetra++;
				}
				if (per.Usuario[i] >= 48 && per.Usuario[i] <= 57)
				{
					contadorNumero++;
				}
			}
			if (primerLetra == true && contadorLetra >= 2 && contadorNumero <= 3)
			{
				printf ("\nEl Usuario fue registrado\n");
				per.ValidarUsuario = true;
			}	
			else
			{
				printf ("\n El nombre de usuario NO es valido, vuelva a ingresar...\n\n");
				system ("pause");
			}
		}
		else
		{
			printf ("\nEl Nombre de Usuario es muy corto, o muy largo\n\n");
			system ("pause");
		}
	}while (per.ValidarUsuario == false);
}