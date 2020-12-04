#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

void opciones();
void cargarVeterinario ();


void opciones()
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
			case 1:
				cargarVeterinario();
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


void cargarVeterinario ()
{
	int cantidad=0;
	persona per;
	bool primerLetra = false;
	int Band = 0;
	
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
		int contadorLetra=0,contadorNumero=0;
			
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
				Band = 1;
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
	}while (Band == 0);
	
	do
	{
		int	CantMayus=0, CantMinus=0,Signos=0,Numeros=0;
		
		system ("cls");
		printf ("\tINGRESE UNA CONTRASENA PARA EL USUARIO %s\n\n",per.Usuario);
		printf ("Cosas a tener en cuenta al crear la contrasena\n\n");
		printf ("a) Debe tener al menos una letra mayuscula, una minuscula, y un numero\n");
		printf ("b) No puede contener caracteres especiales como puntos, acentos y espacios. Solo caracteres alfanumericos\n");
		printf ("c) Debe tener entre 6 y 32 caracteres\n");
		printf ("d) No debe tener mas de 3 caracteres numericos consecutivos\n");
		printf ("e) No debe tener dos caracteres consecutivos de forma ascendente\n");
		printf ("\n\nIngrese la Contrasena: ");
		scanf ("%s",&per.Contrasena);
		
		cantidad = strlen(per.Contrasena);
		
		if (cantidad >= 6 && cantidad <= 32)
		{
			for (int i=0; i<cantidad; i++)
			{
				if (per.Contrasena[i] >= 65 && per.Contrasena[i] <= 90)
				{
					CantMayus++;
				}
				if (per.Contrasena[i] >= 97 && per.Contrasena[i] <= 122)
				{
					CantMinus++;
				}
				if (per.Contrasena[i] > 31 && per.Contrasena[i] < 48 || per.Contrasena[i] > 57 && per.Contrasena[i] < 65
				|| per.Contrasena[i] > 90 && per.Contrasena[i] < 97 || per.Contrasena[i] > 122 && per.Contrasena[i] <=255)
				{
					Signos++;
				}
				if (per.Contrasena[i] >= 48 && per.Contrasena[i] <= 57)
				{
					Numeros++;
				}
			}
			if (CantMayus >= 1  && CantMinus >= 1 && Signos == 0 && Numeros >= 1)
			{
				printf ("\n\nEl Usuario y Contrasena fue Registrado\n");
				per.ValidarUsuario = true;	
			}
			else 
			{
				printf ("\n[ERROR]: La contrasena ingresada no es valida. Vuelva a ingresar...\n\n");
				system ("pause");
			}
		}
		else
		{
			printf ("\nLa contrasena ingresada es muy larga, o muy corta. Vuelva a ingresar...\n\n");
			system ("pause");
		}
	}while (per.ValidarUsuario == false);
}