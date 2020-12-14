#include "Estructuras.h"

void user(FILE *usuario, cadena &aux);
void password(FILE *usuario, cadena &password);


void AtencionVeterinario(FILE *archTurnos) //aqui
{
	//char Lectura;
	int Band = 0;
	turnos T;
	char matriculAux[50];
	
	system ("cls");
	printf ("\t****************************************************\n");
	printf ("\t* ATENCIONES QUE ESTAN REALIZANDO LOS VETERINARIOS *\n");
	printf ("\t****************************************************\n\n");
	
	do
	{
		printf ("Ingrese la matricula del Veterinario: ");
		_flushall();
		gets(matriculAux);
		
		rewind (archTurnos);
		fread (&T,sizeof(turnos),1,archTurnos);
		while (!feof(archTurnos))
		{
			if (strcmp(T.MatriculaVet, matriculAux) == 0 && T.turnoAtendido == true)
			{
				//system ("cls");
				//printf ("\tEl Veterinario fue Encontrado\n");
				printf ("\nMatricula del Veterinario: %s",T.MatriculaVet);
				printf ("\nDNI del dueño: %d",T.DNI_dueno);
				printf ("\nDetalles de la Atencion: %s\n\n",T.detalleAtencion);
				Band = 1;
				//break;
			}
			fread (&T,sizeof(turnos),1,archTurnos); 
		}
		if(Band == 0){
			printf("\nNo se encontraron resultados para la matricula ingresada: ");
		}
	}while (Band == 0);
	system ("pause");
}

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
		fread(&lect, sizeof(Usuarios), 1, usuario);	   			
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
			
			fread(&lect, sizeof(Usuarios), 1, usuario);
		}
		if(b == false){
			printf("\nNombre de usuario o contrasenia incorrecto.Vuelva a intentarlo...\n\n");
			system ("pause");
			system ("cls");
		}
	}while(b != true);
	
}

void IndentificarVeterinario(FILE *veterinarios, bool &salida){
	
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
		
		rewind(veterinarios);			
		fread(&lect, sizeof(lect), 1, veterinarios);	   			
		while(!feof(veterinarios)){
			
			if(strcmp(lect.matricula,matricula) == 0){
				if(strcmp(lect.Contrasena,contr) == 0){
					b = true;
					salida = true;
					break;	
				}
			}
			
			fread(&lect, sizeof(lect), 1, veterinarios);
		}
		if(b == false){
			printf("\nMatricula o contrasenia incorrecta. Vuelva a intentar");
		}
	}while(b != true);
}

void registrar(FILE *usuario, int num){
	
	usuario = fopen("Usuarios.dat","a+b");
	
	cadena nombre, contr;
	Usuarios lectura;
	system ("cls");
	printf("\nREGISTRARSE\n");
	printf("\nNombre y Apellido: ");
	_flushall();
	gets(lectura.Apellido_Y_Nombre);
	
	system ("cls");
	printf ("\tNOMBRE DE USUARIO:\n");
	printf("\n\tAVISOS IMPORTANTES!\n\n");
	printf("\na) El nombre de usuario debe tener entre 6 y 10 caracteres");
	printf("\nb) Debe comenzar con una letra minuscula");
	printf("\nc) Tener al menos 2 letras mayusculas");
	printf("\nd) Tener como maximo 3 digitos\n");
	user(usuario, nombre);
	strcpy(lectura.nomUsuario, nombre);
	printf ("\nUsuario Creado...\n\n");
	system ("pause");
	system ("cls");
 	printf("\tCREAR CONTRASEÑA:\n");
	printf("\n\tAVISOS IMPORTANTES!\n\n");
	printf("\na)Debera contener al menos una letra mayuscula, una letra minuscula y un numero. ");
	printf("\nb)No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos. ");
	printf("\nc)Debera tener entre 6 y 32 caracteres");
	printf("\nd)No debe tener mas de 3 caracteres numericos consecutivos. ");
	printf("\ne)No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas\n");
	password(usuario, contr);
	strcpy(lectura.contrasenia,contr);
	if(num == 1){
		lectura.admin = true;
	}
	else{
		lectura.admin = false;
	}
	
	fwrite(&lectura, sizeof(Usuarios), 1, usuario);
	fclose(usuario);
}

void user(FILE *usuario, cadena &aux){
	
	
	bool bandera = false;
	
	do{
		int longitud, contadorMayus=0, contadorNum=0;
		printf("\nIngrese su nombre de usuario: ");
		gets(aux);
		longitud = strlen(aux);
		
		if (longitud > 5 && longitud < 11)
		{
			if (aux[0] >= 'a' && aux[0] <= 'z')
			{
				for (int i=0; i<longitud; i++)
				{
					if (aux[i] >= 'A' && aux[i] <= 'Z')
					{
						contadorMayus++;
					}
					else
					{
						if (aux[i] >= '0' && aux[i] <= '9')
						{
							contadorNum++;
						}
					}
				}
				if (contadorMayus > 1 && contadorNum < 4)
				{
					bandera = true;
				}
			}
		}
		if(bandera == false){
			printf("\nEl nombre de usuario ingresado no cumple con alguna de las condiciones dadas.");
			printf("\nVuelva a intentar.\n\n");
		}
	}while(bandera == false);
}
	


void password(FILE *usuario, cadena &password)
{
	int Mayus,Minus,Num,Signos,NumConsecutivos,letrasCons;
	bool Band = false;
	cadena passAux;
	
	do{
		Mayus = 0, Minus = 0, Num = 0, Signos = 0, NumConsecutivos = 0, letrasCons = 1;
		
		printf("\nIngrese su contrasenia: ");
		gets(passAux);
		strcpy(password, passAux);

		for(int i=0; i<strlen(passAux); i++)
		{
			if (passAux[i] >='A' && passAux[i] <='Z')
			{
			Mayus++;		
			} 
			else 
			{
				if (passAux[i] >='a' && passAux[i] <='z')
				{
				 Minus++;	
				}
				else
				{
					if (passAux[i] >= '0' && passAux[i] <= '9')
					{
						Num++;
						NumConsecutivos++;
					}
					else
					{
						Signos++;
					}
				}
	 		}
		}
		strlwr(passAux);
		
		for(int i=0; i<strlen(passAux); i++)
		{
			if (passAux[i] >= 'a' && passAux[i] <= 'z')
			{
			   if(i>0 && passAux[i-1]>'9' && passAux[i]==passAux[i-1] + 1)
			   {
			   		letrasCons++;
			   } 			
			}
		}	
		if (Mayus >= 1 && Minus >= 1 && Num >= 1 && Signos == 0 && letrasCons != 2 && NumConsecutivos <= 3)
		{
			Band = true;
		}	
	}while(Band == false);
	 
}











