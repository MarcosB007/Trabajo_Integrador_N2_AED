void ListarTurnos(FILE *archTurnos, FILE *archMascotas, int D, int M, int A);

void menuConsultorio(FILE *veterinario, FILE *archTurnos, FILE *archMascotas)
{
	int opc;
	do
	{
		bool comprobante = false;
		int D=0, M=0, A=0;
		
		system ("cls");
		printf ("\t*************************************");
		printf ("\n\t* MENU DE OPCIONES DEL CONSULTORIO *");
		printf ("\n\t*************************************\n");
		printf("1.- Iniciar sesion\n");
		printf("2.- Visualizar Lista de Espera de Turnos\n");
		printf("3.- Registrar Evolución de la Mascota\n\n");
		printf("4.- Cerrar la aplicación\n");
		printf("\nIngrese una opcion: ");
		scanf ("%d",&opc);
		
		switch (opc)
		{
			case 1:
				   IndentificarVeterinario(veterinario, comprobante);
				break;
			case 2: if(comprobante == true){
   				 		
   				 		printf("\nIngrese la fecha de hoy para visualizar los turnos");
   				 		printf("\nDia: ");
   				 		scanf("%d", &D);
						printf("\nMes: ");
   				 		scanf("%d", &M);	
						printf("\nAnio: ");
   				 		scanf("%d", &A);		   
				 	}
				
				break;
			case 3:
				
				break;
			case 4:
				printf ("\nSaliendo del programa...\n\n");
				system ("pause");
				break;
			default:
				printf ("\n[Advertencia]: La opcion elegida no es valida, vuelva a ingresar\n\n");
				system ("pause");
		}
	}while (opc != 4);
	
}

void ListarTurnos(FILE *archTurnos, FILE *archMascotas, int D, int M, int A){
	
	turnos lectura;
	Datosmascota lectMasct;
	
	rewind(archTurnos);
	
	fread(&lectura, sizeof(turnos), 1, archTurnos);
	
	while(!feof(archTurnos)){
		
		if(lectura.f_turnos.anio == A && lectura.f_turnos.mes == M && lectura.f_turnos.dia == D){
			
			rewind(archMascotas);
			fread(&lectMasct, sizeof(Datosmascota), 1, archMascotas);
			
			while(!feof(archMascotas)){
				
				if(lectura.DNI_dueno == lectMasct.DNI_dueno){
					
					printf("Apellido y Nombre: %s", lectMasct.AyN);
					printf("Domicilio: %s", lectMasct.domicilio);
					printf("DNI: %d", lectMasct.DNI_dueno);
					printf("Localidad: %s", lectMasct.localidad);
					printf("Peso: %.2f", lectMasct.peso);
					printf("Telefono: %s", lectMasct.telefono);
					
				}
				
				fread(&lectMasct, sizeof(Datosmascota), 1, archMascotas);
			}
			
		}
		
		fread(&lectura, sizeof(turnos), 1, archTurnos);
	}
	
	
}





