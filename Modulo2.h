
typedef char cadena [45];

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
 	fecha f_turnos;
 };


//char dibujarMenu();
void cargar(FILE *arch);
void cargaTurnos(FILE *arch);



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
  }
	
	
	
	
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
}*/



	void carga(FILE *arch){
		Datosmascota Dm;
	
	 
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
	fwrite (&Dm, sizeof (Dm), 1, arch);
		
}
void cargaTurnos(FILE *arch){
	turnos T;
	
	printf("\n\t**************************************************************");
	printf("\n\t Registro de Turnos");
	printf("\n\t**************************************************************");
	printf("Ingrese la matricula del veterinario");
	scanf("%s" &T.MatriculaVet);
	printf("Ingrese el DNI del Dueño:");
	scanf("%d", &T.DNI_dueno);
	printf("Ingrese la fecha del turno");
	printf("Ingrese el dia:\n");
	scanf("%d", &T.f_turnos.dia);
	printf("Ingrese el mes:\n");
	scanf("%d", &T.f_turnos.mes);
	printf("Ingrese el año:\n");
	scanf("%d", &T.f_turnos.anio);
	printf("Detalle la razon del turno:\n");
	scanf("%s"&T.detalleAtencion);
	
	fwrite (&T, sizeof (T), 1, arch);
}


	
	
