
void cargaTurnos(FILE *ArchTurnos);
void CargarMascotas(FILE *Mascotas);
void ListarTurno (FILE *ArchTurnos);

void CargarMascotas(FILE *Mascotas){
	
	Datosmascota Dm;
	 
	 printf("\n\t*************************************************************************");
	 printf("\n\t\tIncio del registro de la mascota:");
	 printf("\n\t*************************************************************************");
     printf( "Ingrese el  nombre de la mascota:  \n");
     _flushall();
     gets(Dm.AyN);
     printf("Ingrese domicilio:\n");
     gets(Dm.domicilio);
     printf("Ingrese la localidad:\n");
     gets(Dm.localidad);
     printf( "Ingrese el DNI:\n " );
       scanf( "%d", &Dm.DNI_dueno );
        printf( "El numero celular es:\n " );
         _flushall();
         gets(Dm.telefono);
         printf("Ingrese el peso del animal:\n");
         scanf("%d", &Dm.peso);
         printf("Ingrese la Fecha de nacimiento de la mascota:\n");
         printf("Ingrese el dia:\n");
         scanf("%d", &Dm.f_mascota.dia);
         printf("Ingrese el mes:\n");
         scanf("%d", &Dm.f_mascota.mes);
         printf("Ingrese el año:\n");
         scanf("%d", &Dm.f_mascota.anio);
         
         system("PAUSE"); 
	fwrite (&Dm, sizeof (Datosmascota), 1, Mascotas);
	system("cls");
	fclose(Mascotas);
		
}
void cargaTurnos(FILE *ArchTurnos){
	turnos T;

	int resp=0,i;
	printf("\n\t**************************************************************");
	printf("\n\t Registro de Turnos");
	printf("\n\t**************************************************************");
	printf("Ingrese la fecha del turno");
	printf("Ingrese el dia:\n");
	scanf("%d", &T.f_turnos.dia);
	printf("Ingrese el mes:\n");
	scanf("%d", &T.f_turnos.mes);
	printf("Ingrese el año:\n");
	scanf("%d", &T.f_turnos.anio);
	printf("Ingrese la matricula del veterinario:");
	_flushall();
	gets(T.MatriculaVet);
	printf("Ingrese el DNI del Dueño:");
	scanf("%d", &T.DNI_dueno);
    printf("Detalle la razon del turno:\n");
    _flushall();
	gets(T.detalleAtencion);
	fwrite(&T, sizeof(turnos), 1, ArchTurnos);

	printf("\n*******************************************************");
	printf("\n\t\t El turno ha sido rservado con exito!");
	printf("\n*******************************************************");
	
		
}
	
void ListarTurno (FILE *ArchTurnos){
	turnos T;
	
	fread(&T, sizeof(turnos),1,ArchTurnos);
	
	while(!feof(ArchTurnos)){
		if(!feof(ArchTurnos)){
			system("cls");
	printf("\n**************************************************************");
	printf("\n\t\t Lista de turnos");
	printf("\n**************************************************************");
	printf("Dia: %d", T.f_turnos.dia);
	printf("Mes: %d", T.f_turnos.mes);
	printf("Año: %d", T.f_turnos.anio);
	
	fread(&T, sizeof(turnos),1,ArchTurnos);
			
		}
	}
	fclose(ArchTurnos);
	system("cls");
}
	
	
