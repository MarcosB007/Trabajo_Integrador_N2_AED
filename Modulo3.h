
void cargarVeterinario(FILE *archVet);
void cargarUsuarioAsistente(FILE *usuarios);
void AtencionVeterinario (FILE *ArchTurnos);

void menuAdministrador(FILE *archVet, FILE *usuarios)
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
				cargarVeterinario(archVet);
				printf ("\n\n");
				system ("pause");
				break;
			case 2:
				   cargarUsuarioAsistente(usuarios);
				break;
			case 3:
				//AtencionVeterinario(ArchTurnos);
				printf ("\n\n");
				system ("pause");
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


void cargarVeterinario(FILE *archVet)
{	
	Veterinario vet;
	cadena userAux, passAux;
	int cantidad=0;
	bool primerLetra = false;
	int Band = 0;
	
	system ("cls");
	printf ("\tREGISTRAR VETERINARIO\n\n");
	printf ("Apellido y Nombre: ");
	_flushall();
	gets (vet.ApeyNom);
	printf ("DNI: ");
	scanf ("%d",&vet.DNI);
	printf("Matricula: ");
	_flushall();
	gets (vet.matricula);
	printf ("\nIngrese la fecha de Nacimiento\n\n");
	printf ("Dia: ");
	scanf ("%d",&vet.fech.dia);
	printf ("Mes: ");
	scanf ("%d",&vet.fech.mes);
	printf ("Anio: ");
	scanf ("%d",&vet.fech.anio);
	vet.edad = 2020 - vet.fech.anio; 
	
	user(archVet, userAux);
	strcpy(vet.Usuario,userAux);
	
	password(archVet, passAux);
	strcpy(vet.Contrasena, passAux);
	
	fwrite(&vet, sizeof(Veterinario), 1, archVet);
	
}

void cargarUsuarioAsistente(FILE *usuarios){
	
	int n=0;
	registrar(usuarios, n);
}

void AtencionVeterinario (FILE *ArchTurnos)
{
	char Lectura;
	int Band = 0;
	turnos T;
	char matriculAux[50];
	
	system ("cls");
	printf ("******************************************************");
	printf ("\t* ATENCIONES QUE ESTAN REALIZANDO LOS VETERINARIOS *\n");
	printf ("******************************************************\n\n");
	rewind (ArchTurnos);
	do
	{
		printf ("Ingrese la matricula del Veterinario: ");
		scanf ("%d",&matriculAux);
		fread (&Lectura,sizeof(turnos),1,ArchTurnos);
		while (!feof(ArchTurnos))
		{
			if (matriculAux == T.MatriculaVet)
			{
				system ("cls");
				printf ("\tEl Veterinario fue Encontrado\n");
				printf ("\nMatricula del Veterinario: %d",T.MatriculaVet);
				printf ("\nDNI del dueño: %d",T.DNI_dueno);
				printf ("\nDetalles de la Atencion: %s\n\n",T.detalleAtencion);
				Band = 1;
				system ("pause");
				break;
			}
			fread (&Lectura,sizeof(turnos),1,ArchTurnos); 
		}
	}while (Band == 0);
}
