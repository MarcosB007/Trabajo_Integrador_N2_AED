#include "Estructuras.h"

void IndentificarVeterinario(FILE *Vet, char vet[50]);
void ListarTurnos(FILE *archTurnos, FILE *archMascotas, int D, int M, int A);
void atenderMascota(FILE *archMascotas, char nombreApellido, bool &bandera);

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
					if(lectMasct.atendido == false){
						
						printf("\nApellido y Nombre: %s", lectMasct.AyN);
						printf("\nDomicilio: %s", lectMasct.domicilio);
						printf("\nDNI: %d", lectMasct.DNI_dueno);
						printf("\nLocalidad: %s", lectMasct.localidad);
						printf("\nPeso: %.2f", lectMasct.peso);
						printf("\nTelefono: %s\n", lectMasct.telefono);			  	
					}
				}
				
				fread(&lectMasct, sizeof(Datosmascota), 1, archMascotas);
			}
			
		}
		
		fread(&lectura, sizeof(turnos), 1, archTurnos);
	}
}

void atenderMascota(FILE *archMascotas, char nombreApellido[50], bool &bandera){
	
	rewind(archMascotas);
	Datosmascota mascota;
	
	fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	while(!feof(archMascotas)){
		
		if(strcmp(mascota.AyN, nombreApellido) == 0){
			mascota.atendido = true;
			bandera = true;
			break;
		}
		
		fread(&mascota, sizeof(Datosmascota), 1, archMascotas);
	}
	
	if(bandera == false){
		printf("\nEl nombre de la mascota ingresado no tiene turno para este dia.\n");
	}
	
	fwrite(&mascota, sizeof(Datosmascota), 1, archMascotas);
	printf("Mascota atendida.");
	
}





