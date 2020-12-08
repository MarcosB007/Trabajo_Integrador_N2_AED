#include "Estructuras.h"

void user(FILE *respArch, cadena &aux);
void password(FILE *respArch, cadena &password);

void InicioSesion(FILE *usuario, int num){
	
	cadena nombreUsuario, contr;
	Usuarios lect;
	
	bool b = false;
	do{
		printf("\nINICIO DE SESION\n");
		printf("\nNombre de usuario: ");
		_flushall();
		gets(nombreUsuario);
		printf("Contrasenia: ");
		gets(contr);
		
		rewind(usuario);			
		fread(&lect, sizeof(lect), 1, usuario);	   			
		while(!feof(usuario)){
			
			if(num == 1 && lect.admin == true){
				
				if(strcmp(lect.nomUsuario,nombreUsuario) == 0){
					if(strcmp(lect.contrasenia,contr) == 0){
						b = true;
						break;	
					}
				}
			}
			if(num == 0 && lect.admin == false){
				
				if(strcmp(lect.nomUsuario,nombreUsuario) == 0){
					if(strcmp(lect.contrasenia,contr) == 0){
						b = true;
						break;	
					}
				}
			}
			
			fread(&lect, sizeof(lect), 1, usuario);
		}
		if(b == false){
			printf("Nombre de usuario o contrasenia incorrecto.");
		}
	}while(b != true);
	
}

void IndentificarVeterinario(FILE *Vet, bool &salida){
	
	cadena matricula, contr;
	Veterinario lect;
	
	rewind(Vet);
	
	bool b = false;
	do{
		printf("\nINICIO DE SESION\n");
		printf("\nMatricula: ");
		_flushall();
		gets(matricula);
		printf("Contrasenia: ");
		gets(contr);
		
					
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
	}while(b != false);
}

void registrar(FILE *usuario, int num){
	
	cadena nombre, contr;
	Usuarios admin, lectura;
	int longitud, contadorMayus=0, contadorNum=0;
	bool bandera = false;
		
	printf("\nREGISTRARSE\n");
	printf("\nNombre y Apellido: ");
	_flushall();
	gets(admin.Apellido_Y_Nombre);
	
	printf("\nNombre de Usuario: ");
	printf("\nAVISOS IMPORTANTES!\n");
	printf("\nEl nombre de usuario debe tener entre 6 y 10 caracteres");
	printf("\nDebe comenzar con una letra minuscula");
	printf("\nTener al menos 2 letras mayusculas");
	printf("\nTener como maximo 3 digitos");
	user(usuario, nombre);
	strcpy(admin.nomUsuario, nombre);
	
 	printf("\nContrasenia: ");
	printf("\nAVISOS IMPORTANTES!\n");
	printf("\nDebera contener al menos una letra mayuscula, una letra minuscula y un numero. ");
	printf("\nNo podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos. ");
	printf("\nDebera tener entre 6 y 32 caracteres");
	printf("\nNo debe tener mas de 3 caracteres numericos consecutivos. ");
	printf("\nNo debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas");
	password(usuario, contr);
	strcpy(admin.contrasenia,contr);
	if(num == 1){
		admin.admin = true;
	}
	else{
		admin.admin = false;
	}
	
		 
	
	fwrite(&admin, sizeof(admin), 1, usuario);
}

void user(FILE *respArch, cadena &aux){
	
	int longitud, contadorMayus=0, contadorNum=0;
	bool bandera = false;
	
	do{
		printf("\nIngrese su nombre de usuario: ");
		gets(aux);
		longitud = strlen(aux);
		if(longitud > 5 && longitud < 11){
		
			if(aux[0] > 97 && aux[0] < 123){
				
				for(int i=0; i<strlen(aux); i++){
					
					if(aux[i] > 64 && aux[i] < 91){
					contadorMayus+=1;
					}
			
					if(contadorMayus > 1){
						for(int i=0; i<strlen(aux); i++){
				
			 				if(aux[i] > 47 && aux[i] < 58){
			   					contadorNum+=1;
							}
						}
						if(contadorNum < 4){
			   			    bandera = true;
						}
					}
				}	
			}	
		}
	
		if(bandera == false){
			printf("\nEl nombre de usuario ingresado no cumple con alguna de las condiciones dadas.");
			printf("\nVuelva a intentar.");
		}
	}while(bandera == false);
}

void password(FILE *respArch, cadena &password){
	 
	int may = 0, min = 0, num = 0, otros = 0, numcons = 0, letrasCons = 1;
	cadena passAux;
	
	do{
		printf("\nIngrese su contrasenia: ");
		gets(passAux);
		strcpy(password, passAux);

		for(int i=0; i<strlen(passAux); i++){
			if (passAux[i] >='A' && passAux[i] <='Z'){
			may++;
			numcons = 0;		
			} 
			else if (passAux[i] >='a' && passAux[i] <='z'){
				 min++;
				 numcons = 0;
	 		}
			else if (passAux[i] >= '0' && passAux[i] <='9'){
			 	num++;
				numcons++;	
			    }
			 	else otros++;
			if (numcons == 4){
				
			}
		}
		strlwr(passAux);
		
		for(int i=0; i<strlen(passAux); i++){
			if (passAux[i] >='a' && passAux[i] <='z'){
			   if(i>0 && passAux[i-1]>'9' && passAux[i]==passAux[i-1]+1) letrasCons++;			
			}
		}	
		
	}while(may<1 || 
		   min<1 || 
		   num<1 || 
		   otros!=0 || 
	       strlen(passAux)<6 || 
		   strlen(passAux)>32 || 
		   numcons>3 || letrasCons>1);
	 
}









