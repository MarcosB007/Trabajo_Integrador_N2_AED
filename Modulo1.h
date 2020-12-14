#include "Estructuras.h"

void IndentificarVeterinario(FILE *Vet, char vet[50]);
void ListarTurnos(FILE *archTurnos);
void evolucionMascota(FILE *archTurnos);

void IndentificarVeterinario(FILE *Vet, char vet[50]){
	
	cadena matricula, contr;
	Veterinario lect;
	
	bool b = false;
	do{
		system("cls");
		printf("\nINICIO DE SESION\n");
		printf("\nMatricula: ");
		_flushall();
		gets(matricula);
		printf("Contrasenia: ");
		gets(contr);
		
		rewind(Vet);			
		fread(&lect, sizeof(lect), 1, Vet);	   			
		while(!feof(Vet)){
			
			if(strcmp(lect.matricula,matricula) == 0){
				if(strcmp(lect.Contrasena,contr) == 0){
					b = true;
					strcpy(vet,lect.matricula);
					break;	
				}
			}
			
			fread(&lect, sizeof(lect), 1, Vet);
		}
		if(b == false){
			printf("\nMatricula o contrasenia incorrecta. Vuelva a intentar");
		}
	}while(b != true);
}

void ListarTurnos(FILE *archTurnos){
	
	archTurnos = fopen("Turnos.dat","r+b");
	
	system("cls");
	printf("\nLISTADO DE TURNOS\n");
	turnos lectura;
	
	rewind(archTurnos);
	
	fread(&lectura, sizeof(turnos), 1, archTurnos);
	
	while(!feof(archTurnos)){
			
		if(lectura.turnoAtendido == false){
			
			printf("\nMatricula del veterinario: %s", lectura.MatriculaVet);
			printf("\nDNI mascota: %d", lectura.DNI_dueno);
			printf("\nFecha: %d/%d/%d\n", lectura.f_turnos.dia, lectura.f_turnos.mes, lectura.f_turnos.anio);
			//printf("Evolucion de la mascota: %s\n", lectura.detalleAtencion);
		}
		
		fread(&lectura, sizeof(turnos), 1, archTurnos);
	}
	fclose(archTurnos);
}

void evolucionMascota(FILE *archTurnos){
	
	archTurnos = fopen("Turnos.dat","r+b");
	
	char variable[380];
	turnos turno;
	int DNImascota;
	bool bandera = false;
	
	printf("\nIngrese el DNI de la mascota a atender: ");
	scanf("%d", &DNImascota);
	
	rewind(archTurnos);
	
	fread(&turno, sizeof(turnos), 1, archTurnos);
	while(!feof(archTurnos) && bandera == false){
		
		if(turno.DNI_dueno == DNImascota && turno.turnoAtendido == false){
  			
  			fseek(archTurnos, (long)-sizeof(turnos), SEEK_CUR);
  			
			printf("\nDescriba la evolucion de la mascota");
			printf("\n- ");
			_flushall();
			gets(variable);
			
			strcpy(turno.detalleAtencion , variable);
			turno.turnoAtendido = true;
					
			 
			fwrite(&turno, sizeof(turnos), 1, archTurnos);
			fseek(archTurnos,sizeof(archTurnos), SEEK_CUR);
			
			bandera = true;
			
		}
		
		fread(&turno, sizeof(turnos), 1, archTurnos);
		
	}
	
	if(bandera == false){
		printf("\nEl DNI ingresado no existe en los registros.");
	}
	fclose(archTurnos);
}





