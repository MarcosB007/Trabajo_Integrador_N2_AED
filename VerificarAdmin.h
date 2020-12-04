typedef char cadena[50];
	
struct Usuarios{
	char Apellido_Y_Nombre[60];
	char nomUsuario[10];
	char contrasenia[10];
};

void InicioSesion(FILE *usuario){
	
	cadena nombreUsuario, contr;
	Usuarios lect;
	
	bool b = false;
	do{
		printf("\nINICIO DE SESION\n");
		printf("\nNombre de usuario: ");
		_flushall();
		gets(nombreUsuario);
		
		rewind(usuario);			
		fread(&lect, sizeof(lect), 1, usuario);	   			
		while(!feof(usuario)){
			   					
			if(strcmp(lect.nomUsuario,nombreUsuario) == 0){
				b = true;
				break;
			}
			fread(&lect, sizeof(lect), 1, usuario);
		}
		if(b == false){
			printf("Nombre de usuario incorrecto.");
		}
	}while(b != true);
	
	
	
}

void registrar(FILE *usuario){
	
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
	
	
	do{
		printf("\nIngrese su nombre de usuario: ");
		gets(admin.nomUsuario);
		longitud = strlen(admin.nomUsuario);
		if(longitud > 5 && longitud < 11){
		
			if(admin.nomUsuario[0] > 97 && admin.nomUsuario[0] < 123){
				
				for(int i=0; i<strlen(admin.nomUsuario); i++){
					
					if(admin.nomUsuario[i] > 64 && admin.nomUsuario[i] < 91){
					contadorMayus+=1;
					}
			
					if(contadorMayus > 1){
						for(int i=0; i<strlen(admin.nomUsuario); i++){
				
			 				if(admin.nomUsuario[i] > 47 && admin.nomUsuario[i] < 58){
			   					contadorNum+=1;
							}
						}
						if(contadorNum < 4){
			   			    bandera = true;
			   				
			   				rewind(usuario);
			   				fread(&lectura, sizeof(lectura), 1, usuario);
			   				while(!feof(usuario)){
			   					
			   					if(strcmp(admin.nomUsuario, lectura.nomUsuario) == 0){
			   						bandera = false;
								}
			   					fread(&lectura, sizeof(lectura), 1, usuario);
							}
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
	
	fwrite(&admin, sizeof(admin), 1, usuario);
}
