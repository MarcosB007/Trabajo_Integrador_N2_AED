
void cargaTurnos(FILE *ArchTurnos, FILE *ArchVeterinario, FILE *arcMascotas);
void CargarMascotas(FILE *Mascotas);
void ListarTurno (FILE *ArchTurnos);

void CargarMascotas(FILE *Mascotas){
	
	fclose(Mascotas);
	Mascotas = fopen("Mascotas.dat","ab");
	
	Datosmascota Dm;
	 system("cls");
	 printf("\n\t*************************************************************************");
	 printf("\n\t\tIncio del registro de la mascota:");
	 printf("\n\t*************************************************************************");
     printf( "\nIngrese el  nombre de la mascota:");
     _flushall();
     gets(Dm.AyN);
     printf("\nIngrese domicilio:");
     gets(Dm.domicilio);
     printf("\nIngrese la localidad:");
     gets(Dm.localidad);
     printf( "\nIngrese el DNI del dueno: " );
       scanf( "%d", &Dm.DNI_dueno );
        printf( "\nEl numero celular es:" );
         _flushall();
         gets(Dm.telefono);
         printf("\nIngrese el peso del animal:");
         scanf("%d", &Dm.peso);
         printf("\nIngrese la Fecha de nacimiento de la mascota:");
         printf("\nIngrese el dia:");
         scanf("%d", &Dm.f_mascota.dia);
         printf("\nIngrese el mes:");
         scanf("%d", &Dm.f_mascota.mes);
         printf("\nIngrese el anio:");
         scanf("%d", &Dm.f_mascota.anio);
         
         
         system("PAUSE"); 
	fwrite (&Dm, sizeof (Datosmascota), 1, Mascotas);
	system("cls");
	fclose(Mascotas);
	Mascotas = fopen("Mascotas.dat","a+b");
		
}
void cargaTurnos(FILE *ArchTurnos, FILE *ArchVeterinario, FILE *archMascotas){
	turnos T;
	Veterinario vet;
	Datosmascota mascota;
    char matriculAux[50];
    bool bandera = false, b = false;
	system("cls");
	printf("\n\t**************************************************************");
	printf("\n\t\t\t\t\tRegistro de Turnos");
	printf("\n\t**************************************************************");
	
	do{
		
		printf("\nIngrese la matricula del veterinario:");
		_flushall();
		gets(matriculAux);
		
		rewind(ArchVeterinario);
		fread (&vet,sizeof(Veterinario), 1, ArchVeterinario);
		
		while(!feof(ArchVeterinario)){
			if (strcmp(vet.matricula, matriculAux) == 0){
				
				strcpy(T.MatriculaVet, vet.matricula);
				
				bandera = true;
				break;
			}
			fread (&vet,sizeof(Veterinario), 1, ArchVeterinario);
		}
		if(bandera == false){
			printf("\nEste numero de matricula no existe. Vuelva a intentar\n");
		}
		system("pause");
		system("cls");
		
	}while(bandera != true);
	
	
	do{
		printf("\nIngrese el DNI del Duenio de la mascota:");
		scanf("%d", &T.DNI_dueno);
	
		rewind(archMascotas);
		fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	
		while(!feof(archMascotas)){
		
			if(T.DNI_dueno == mascota.DNI_dueno){
				
				printf("\nIngrese la fecha del turno");
				printf("\nIngrese el dia:");
				scanf("%d", &T.f_turnos.dia);
				printf("\nIngrese el mes:");
				scanf("%d", &T.f_turnos.mes);
				printf("\nIngrese el año:");
				scanf("%d", &T.f_turnos.anio);
				T.turnoAtendido = false;
				fwrite(&T, sizeof(turnos), 1, ArchTurnos);
				b = true;
			}
			fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
		}
		
		if(b == false){
			printf("Este numero de DNI no esta registrado. ");
		}
		
	}while(bandera != true);
	fread(&mascota, sizeof(Datosmascota), 1, archMascotas);

	printf("\n*******************************************************");
	printf("\n\t\t El turno ha sido rservado con exito!");
	printf("\n*******************************************************");
	
}
	
void ListarTurno (FILE *ArchTurnos){
	system("cls");
	printf("\n*******************************************************");
	printf("\n\t\t\tLISTADO DE TURNOS\n");
	printf("\n*******************************************************");
	turnos T;
	rewind(ArchTurnos);
	
	
	fread(&T, sizeof(turnos), 1, ArchTurnos);
	
	while(!feof(ArchTurnos)){
			
		if(T.turnoAtendido == false){
			
			printf("\nMatricula del veterinario: %s", T.MatriculaVet);
			printf("\nFecha:");
			printf("\nDia:%d", T.f_turnos.dia);
			printf("\nMes:%d", T.f_turnos.mes);
			printf("\nAnio:%d", T.f_turnos.anio);
			printf("\n*******************************************************");
		}
		
		fread(&T, sizeof(turnos), 1, ArchTurnos);
	}
}
	
