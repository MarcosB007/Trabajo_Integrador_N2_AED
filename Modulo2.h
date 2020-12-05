
//typedef char cadenaM2 [45];

struct fecha{
	int dia,mes,anio;
};
struct usuarios{
	char usuario[10];
	char contrasena[10];
	char AyN[60];
};

struct Datosmascota{
	char AyN[60];
	char domicilio[60];
	int DNI_dueno;
	char localidad [60];
	float peso;
	char telefono[25];
	fecha f_mascota;
};
 struct turnos{
 	int MatriculaVet;
 	int DNI_dueno;
 	char detalleAtencion [380];
 	int disponible;
 	fecha f_turnos;
 };


//char dibujarMenu();
//void cargar(FILE *Mascotas);
//void cargaTurnos(FILE *Turnos);
//void ListarTurno (File *Turnos);


  /*FILE *Mascotas = fopen("Marcostas.dat","a+b");
  FILE *Turnos = fopen("Turnos.dat", "a+");
  
  
  if (Mascotas==NULL){
  	printf("El archivo no se pudo crear! Vuelva a intentarlo");
  	return 0;
  }
  char opc;
  do{
  	opc=dibujarMenu;
  	switch (opc){
  		case 1:
  			carga(arch);
  			break;
  			case 2:
  				
  			
	  }
  }*/
	
	
	
	
	char dibujarMenu(){
	
	printf("\n\t*******************************************************************");
	printf("\n\t\tModulo del asistente");
	printf("\n\t*******************************************************************");
	printf("\n 1 --> Iniciar Sesion");
	printf("\n 2 --> Registrar Mascotas");
	printf("\n 3 --> Registrar Turno");
	printf("\n 4 --> Listado de atencion por veterinario y fecha");
	printf("\n 5 --> Cerra la aplicacion");
	printf("\n\t*******************************************************************");
	printf("Ingrese la opcion deseada: \n");
	char opc;
	_flushall();
	scanf("%c", &opc);
	return opc;
}



	void carga(FILE *Mascotas){
		Datosmascota Dm;
	  //FILE *Mascotas = fopen("Marcostas.dat","a+b");
	 
	 printf("\n\t*************************************************************************");
	 printf("\n\t\tIncio del registro de la mascota:");
	 printf("\n\t*************************************************************************");
     printf( "Ingrese el  nombre de la mascota:  \n");
     scanf( "%s", &Dm.AyN );
     printf("Ingrese domicilio:\n");
     scanf("%s", &Dm.domicilio);
     printf("Ingrese la localidad:\n");
     scanf("%d", &Dm.localidad);
     printf( "Ingrese el DNI:\n " );
       scanf( "%d", &Dm.DNI_dueno );
        printf( "El numero celular es:\n " );
         scanf( "%d", &Dm.telefono );
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
	fwrite (&Dm, sizeof (Dm), 1, Mascotas);
	system("cls");
	fclose(Mascotas);
		
}
void cargaTurnos(FILE *ArchTurnos){
	turnos T;
	//FILE *Turnos = fopen("Turnos.dat", "r");
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
	system("cls");
	fread (&T, sizeof (T), 1, ArchTurnos);
	
	while(!feof(ArchTurnos)){
		if(turnos.f_turnos.mes= turnos.f_turnos.dia && resp==0){
			if(turnos.disponible ==0 && resp==0){
				printf("\n*********************************************************");
				printf("\n\t\t\tDatos del turno");
				printf("\n*********************************************************");
				  turnos.disponible=1;
				  printf("Ingrese la matricula del veterinario:");
	              scanf("%s" &T.MatriculaVet);
	              printf("Ingrese el DNI del Dueño:");
	              scanf("%d", &T.DNI_dueno);
             	  printf("Detalle la razon del turno:\n");
	              scanf("%s"&T.detalleAtencion);
	              resp =1;
			}
		}
		
	}
	
	if (resp==1){
		printf("\n*******************************************************");
		printf("\n\t\t El turno ha sido rservado con exito!");
		printf("\n*******************************************************");
	}
	else{
		printf("\n*******************************************************");
		printf("\n\t\t El dia ingresado no esta disponible");
		printf("\n*******************************************************");
	 
	}

	
	
}

void ListarTurno (File *Turnos){
	Turnos = fopen("Turnos.dat", "r");
	Turnos T;
	
	fread(&T, sizeof(Turnos),1,Turnos);
	
	while(!feof(Turnos)){
		if(!feof(Turnos)){
			system("cls");
	printf("\n**************************************************************");
	printf("\n\t\t Lista de turnos");
	printf("\n**************************************************************");
	printf("Dia: %d", turnos.f_turnos.dia);
	printf("Mes: %d", turnos.f_turnos.mes);
	printf("Año: %d", turnos.f_turnos.anio);
	
	fread(&T, sizeof(Turnos),1,Turnos)
			
		}
	}
	getch();
	fclose(Turnos);
	system("cls");
}
	
	
