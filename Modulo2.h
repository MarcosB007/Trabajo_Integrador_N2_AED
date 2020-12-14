
void cargaTurnos(FILE *ArchTurnos, FILE *ArchVeterinario, FILE *arcMascotas);
void CargarMascotas(FILE *Mascotas);
void ListarTurno (FILE *ArchTurnos, FILE *ArchVeterinario);

void CargarMascotas(FILE *Mascotas){
	
	fclose(Mascotas);
	Mascotas = fopen("Mascotas.dat","ab");
	
	Datosmascota Dm;
	 system("cls");
	 printf("\t\t\t\t=========================\n");
	 printf("\t\t\t\t==  CARGA DE MASCOTAS  ==\n");
	 printf("\t\t\t\t=========================\n");
     printf("\nIngrese el nombre de la mascota:");
     _flushall();
     gets(Dm.AyN);
     printf("\nDomicilio: ");
     gets(Dm.domicilio);
     printf("\nLocalidad: ");
     gets(Dm.localidad);
     printf( "\nDNI del dueno de la mascota: ");
       scanf( "%d", &Dm.DNI_dueno );
        printf( "\nNumero celular: ");
         _flushall();
         gets(Dm.telefono);
         printf("\nPeso de la mascota: ");
         scanf("%d", &Dm.peso);
         printf("\nFecha de nacimiento de la mascota:");
         printf("\nDia:");
         scanf("%d", &Dm.f_mascota.dia);
         printf("\nMes:");
         scanf("%d", &Dm.f_mascota.mes);
         printf("\nAnio:");
         scanf("%d", &Dm.f_mascota.anio);
         Dm.edad = 2020 - Dm.f_mascota.anio;
         
         
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
	printf("\t\t\t\t\t==========================\n");
	printf("\t\t\t\t\t==  Registro de Turnos  ==\n");
	printf("\t\t\t\t\t==========================\n");
	
	do{
		
		printf("\nIngrese la matricula del veterinario: ");
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
				printf("\nDia:");
				scanf("%d", &T.f_turnos.dia);
				printf("\nMes:");
				scanf("%d", &T.f_turnos.mes);
				printf("\nAnio:");
				scanf("%d", &T.f_turnos.anio);
				T.turnoAtendido = false;
				strcpy(T.detalleAtencion,"\0");
				fwrite(&T, sizeof(turnos), 1, ArchTurnos);
				
				printf("\nEl turno ha sido rservado con exito!");
				printf("\n====================================");
				
				b = true;
			}
			fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
		}
		
		if(b == false){
			printf("Este numero de DNI no esta registrado. ");
		}
		
	}while(bandera != true);
	fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	
}

	
void ListarTurno (FILE *ArchTurnos, FILE *ArchVeterinario){
	turnos T;
	char matriculAux[50];
	int dia, mes, anio;
	int num;
    bool bandera = false, b = false;
    
    system("cls");
	printf("\t\t\t\t\t=========================\n");
	printf("\t\t\t\t\t==  LISTADO DE TURNOS  ==\n");
	printf("\t\t\t\t\t=========================\n");
	
	do{
		printf("\nIngrese la matricula del veterinario:");
		_flushall();
		gets(matriculAux);
		
		printf("\nIngrese una fecha:");
		printf("\nDia:");
		scanf("%d", &dia);
		printf("\nMes:");
		scanf("%d", &mes);
		printf("\nAnio:");
		scanf("%d", &anio);
		
		rewind(ArchTurnos);
		fread (&T,sizeof(turnos), 1, ArchTurnos);
		while(!feof(ArchTurnos)){
			
			if(strcmp(T.MatriculaVet, matriculAux)==0 && T.turnoAtendido == true){
				
				if(T.f_turnos.dia == dia && T.f_turnos.mes == mes && T.f_turnos.anio == anio){
					
					printf("\n__________________________________________________");
					printf("\nMatricula del veterinario: %s",T.MatriculaVet);
					printf("\nFecha de atencion: %d/%d/%d", T.f_turnos.dia, T.f_turnos.mes, T.f_turnos.anio);
					printf("\nDNI de la mascota atendida: %d", T.DNI_dueno);
					printf("\nHistoria clinica: %s", T.detalleAtencion);
					printf("\n___________________________________________________");
					
					bandera = true;
				}
			}
			
			fread (&T,sizeof(turnos), 1, ArchTurnos);
		}
		if (bandera == false){
			printf("\nEsta matricula o fecha no estan registradas.");
			do{
				printf("\nIngrese 1 para intentar nuevamente");
				printf("\nIngrese 0 para salir");
				printf("\n- ");
				scanf("%d", &num);
				system("cls");
			}while(num != 0 && num != 1);	
		}
		
		printf("\n");
		system("pause");
		system("cls");
		
	}while(num != 0 && bandera != true);
	
}
	
		
	

	
