#include "Estructuras.h"

void IndentificarVeterinario(FILE *Vet, bool &salida);
void ListarTurnos(FILE *archTurnos, FILE *archMascotas, int D, int M, int A);

void IndentificarVeterinario(FILE *Vet, bool &salida){
	
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
					salida = true;
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
					
					printf("\nApellido y Nombre: %s", lectMasct.AyN);
					printf("\nDomicilio: %s", lectMasct.domicilio);
					printf("\nDNI: %d", lectMasct.DNI_dueno);
					printf("\nLocalidad: %s", lectMasct.localidad);
					printf("\nPeso: %.2f", lectMasct.peso);
					printf("\nTelefono: %s\n", lectMasct.telefono);
					
				}
				
				fread(&lectMasct, sizeof(Datosmascota), 1, archMascotas);
			}
			
		}
		
		fread(&lectura, sizeof(turnos), 1, archTurnos);
	}
	
	
}



