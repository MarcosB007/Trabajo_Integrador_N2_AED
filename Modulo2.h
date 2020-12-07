
 #include "Estructuras.h"


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
	
	
	
	
char MenuAsistente(){
	
	int opc;
	
	do{
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
		scanf("%d", &opc);
		
		switch(opc){
			case 1: 
			break;
			
			case 2:
				CargarMascotas(Mascotas);
			system("PAUSE");
				
			break;
			
			case 3: 
			cargaTurnos(ArchTurnos);
				system("PAUSE");
			
			break;
			
			case 4:
				ListarTurno (Turnos);
			system("PAUSE");
			break;
			case 5:
				printf("Cerrando Modulo\n");
		}
	}while(opc != 5 );
	
}



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
	
	//FILE *Turnos = fopen("Turnos.dat", "r+b");
	bool MatriculaCorrec;
	
	printf("\n\t**************************************************************");
	printf("\n\t Registro de Turnos");
	printf("\n\t**************************************************************");
	do{
		MatriculaCorrec = true;
	printf("Ingrese la matricula del veterinario:");
	scanf("%d" &T.MatriculaVet);
	if(VerificarMat(T.MatriculaVet)){
		printf("La matricula no corresponde a un veterinario registrado");
		MatriculaCorrec = false;
		getch();
	}
		
	}while(!MatriculaCorrec);

	printf("Ingrese la fecha del turno");
	printf("Ingrese el dia:\n");
	scanf("%d", &T.f_turnos.dia);
	printf("Ingrese el mes:\n");
	scanf("%d", &T.f_turnos.mes);
	printf("Ingrese el año:\n");
	scanf("%d", &T.f_turnos.anio);
	printf("Ingrese el DNI del Dueño:");
	scanf("%d", &T.DNI_dueno);
    printf("Detalle la razon del turno:\n");
	 scanf("%s"&T.detalleAtencion);
	system("cls");
	
	fread (&T, sizeof (T), 1, ArchTurnos);

			 	  
	            
	
	}

	
	


void ListarTurno (File *Turnos){
	Turnos = fopen("Turnos.dat", "r");
	Turnos T;
	
	fread(&T, sizeof(T),1,Turnos);
	
	while(!feof(Turnos)){
		if(!feof(Turnos)){
			system("cls");
	printf("\n**************************************************************");
	printf("\n\t\t Lista de turnos");
	printf("\n**************************************************************");
	printf("Matricula del veterinario:%d\n",T.MatriculaVet);
	printf("Dia: %d\n", T.f_turnos.dia);
	printf("Mes: %d\n",T.f_turnos.mes);
	printf("Año: %d\n",T.f_turnos.anio );
	
	fread(&T, sizeof(Turnos),1,Turnos)
			
		}
	}
	getch();
	fclose(Turnos);
	system("cls");
}
	
