#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char cadena[50];

struct Usuarios{
	char Apellido_Y_Nombre[60];
	char nomUsuario[10];
	char contrasenia[10];
	bool admin;
};

struct fechas
{
	int dia,mes,anio;	
};

struct Veterinario
{
	char ApeyNom[50];
	char Usuario[50];
	char Contrasena[32];
	char matricula[50];
	int edad;
	int DNI;
	bool ValidarUsuario = false;
	fechas fech;
};

struct Datosmascota{
	char AyN[60];
	char domicilio[60];
	int DNI_dueno;
	char localidad [60];
	float peso;
	char telefono[25];
	fechas f_mascota;
};

struct turnos{
 	char MatriculaVet[50];
 	int DNI_dueno;
 	char detalleAtencion [380];
 	fechas f_turnos;
 };
