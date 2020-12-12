#include "Estructuras.h"

void IndentificarVeterinario(FILE *Vet, char vet[50]);
void ListarTurnos(FILE *archTurnos);
void evolucionMascota(FILE *archMascotas, FILE *archTurnos);

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
		}
		
		fread(&lectura, sizeof(turnos), 1, archTurnos);
	}
}

void evolucionMascota(FILE *archMascotas, FILE *archTurnos){
	
	fclose(archMascotas);
	fclose(archTurnos);
	archTurnos = fopen("Turnos.dat","r+b");
	archMascotas = fopen("Mascotas.dat","r+b");
	
	rewind(archMascotas);
	rewind(archTurnos);
	Datosmascota mascota;
	turnos turno;
	char nombreMascota[50];
	bool bandera = false;
	
	printf("\nIngrese el nombre de la mascota a atender: ");
	_flushall();
	gets(nombreMascota);
	
	fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	while(!feof(archMascotas)){
		
		if(strcmp(mascota.AyN, nombreMascota) == 0){
			
			
			fread(&turno, sizeof(turnos), 1, archTurnos);
			while(!feof(archTurnos)){
				
				if(mascota.DNI_dueno == turno.DNI_dueno && turno.turnoAtendido == false ){
					
					printf("\nDescriba la evolucion de la mascota");
					printf("\n- ");
					_flushall();
					gets(turno.detalleAtencion);
					bandera = true;
					
					turno.turnoAtendido = true;
					
					fseek(archTurnos, -sizeof(turnos), SEEK_CUR);
					fwrite(&turno, sizeof(turnos), 1, archTurnos);
					
					break;	   
				}
				
				else{
					fread(&turno, sizeof(turnos), 1, archTurnos);
				}
			}
			
		}
		else{
				printf("\nEl nombre ingresado no existe en los registros.");
				break;
			}
			
		fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	}
	
	if(bandera == true){
		fwrite(&turno, sizeof(turnos), 1, archTurnos);
	}

	fclose(archMascotas);
	fclose(archTurnos);
	archTurnos = fopen("Turnos.dat","a+b");
	archMascotas = fopen("Mascotas.dat","a+b");
}





