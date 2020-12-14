#include "Estructuras.h"

void user(FILE *usuario, cadena &aux);
void password(FILE *usuario, cadena &password);
void RankingAtenciones(FILE *archTurnos, FILE *archVeterinarios);
int cantidadTurnos(FILE *archTurnos, char matricula[50]);

void RankingAtenciones(FILE *archTurnos, FILE *archVeterinarios){
	
	archVeterinarios = fopen("Veterinarios.dat","a+b");
	archTurnos = fopen("Turnos.dat","a+b");
	
	rewind(archTurnos);
	rewind(archVeterinarios);
	int i=0, b=0;
	cadena matriculas[50];
	int cantidades[50];
	turnos turno;
	Veterinario vet;
	
	fread(&vet, sizeof(Veterinario), 1, archVeterinarios);
	while(!feof(archVeterinarios)){
		
		strcpy(matriculas[i], vet.matricula);
		cantidades[i] = cantidadTurnos(archTurnos, vet.matricula);
		
		i++;
		fread(&vet, sizeof(Veterinario), 1, archVeterinarios);
	}
	
	int n=i, auxC=0;
	char auxM[50];
	
	do{
		b=0;
		for(i=0; i<n-1;i++){
		
			if(cantidades[i] < cantidades[i+1]){
				auxC=cantidades[i];
				cantidades[i] = cantidades[i+1];
				cantidades[i+1] = auxC;
			
				strcpy(auxM, matriculas[i]);
				strcpy(matriculas[i], matriculas[i+1]);
				strcpy(matriculas[i+1], auxM);
				b=1;
			}		
		}
		
	}while(b == 1);
	
	printf("\t\t\t\t\t=================================\n");
	printf("\t\t\t\t\t===   RANKING DE ATENCIONES   ===\n");
	printf("\t\t\t\t\t=================================\n");
	
	for(i=0; i<n; i++){
		printf("\n\nVeterinario matricula %s, tiene %d atenciones\n", matriculas[i], cantidades[i]);
		printf("____________________________________________________");
	}
	system("pause");
	fclose(archTurnos);
	fclose(archVeterinarios);
}

int cantidadTurnos(FILE *archTurnos, char matricula[50]){
	
	rewind(archTurnos);
	turnos turno;
	int cant=0;
	fread(&turno, sizeof(turnos), 1, archTurnos);
	while(!feof(archTurnos)){
		
		if(strcmp(turno.MatriculaVet, matricula) == 0 && turno.turnoAtendido == true){
			cant++;
		}
		
		fread(&turno, sizeof(turnos), 1, archTurnos);
	}
	return cant;
}


void AtencionVeterinario(FILE *archTurnos) //aqui
{
	//char Lectura;
	int Band = 0;
	turnos T;
	char matriculAux[50];
	
	system ("cls");
	printf("\t\t\t============================================================\n");
	printf("\t\t\t===   ATENCIONES QUE ESTAN REALIZANDO LOS VETERINARIOS   ===\n");
	printf("\t\t\t============================================================\n");
	
	do
	{
		printf ("Ingrese la matricula del Veterinario: ");
		_flushall();
		gets(matriculAux);
		
		rewind (archTurnos);
		fread (&T,sizeof(turnos),1,archTurnos);
		while (!feof(archTurnos))
		{
			if (strcmp(T.MatriculaVet, matriculAux) == 0 && T.turnoAtendido == true){
				
				printf ("\nMatricula del Veterinario: %s",T.MatriculaVet);
				printf ("\nDNI del dueño: %d",T.DNI_dueno);
				printf ("\nDetalles de la Atencion: %s\n\n",T.detalleAtencion);
				Band = 0;
			}
			fread (&T,sizeof(turnos),1,archTurnos); 
		}
		if(Band == 0){
			printf("\nNo se encontraron resultados para la matricula ingresada.\n");
			system("pause");
			system("cls");
			printf("\ningrese 1 para intentar nuevamente");
			printf("\nIngrese 0 para salir");
			scanf("%d", &Band);
		}
	}while (Band == 1);
	system ("pause");
}

void InicioSesion(FILE *usuario, int num){
	
	cadena nombreUsuario, contr;
	Usuarios lect;
	
	bool b = false;
	int n=0;
	
	do{
		system("cls");
		printf("\t\t\t\t\t============================\n");
		printf("\t\t\t\t\t===   INICIO DE SESION   ===\n");
		printf("\t\t\t\t\t============================\n");
		
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
			printf("\nNombre de usuario o contrasenia incorrecto.\n");
			system ("pause");
			do{
				system ("cls");
				printf("\nIngrese 1 para volver a intentar.");
				printf("\nIngrese 0 para salir.");
				scanf("%d", &n);
				
				if(num == 1)b = false;
				else b = true;
				
			}while(n != 1 && n != 0);
		}
	}while(b != true);
	
}

void IndentificarVeterinario(FILE *veterinarios, bool &salida){
	
	cadena matricula, contr;
	Veterinario lect;
	
	bool b = false;
	do{
		system("cls");
		printf("\t\t\t\t\t============================\n");
		printf("\t\t\t\t\t===   INICIO DE SESION   ===\n");
		printf("\t\t\t\t\t============================\n");
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
	
	printf("\t\t\t\t\t=======================\n");
	printf("\t\t\t\t\t===   REGISTRARSE   ===\n");
	printf("\t\t\t\t\t=======================\n");
	
	printf("\nNombre y Apellido: ");
	_flushall();
	gets(lectura.Apellido_Y_Nombre);
	
	system("cls");
	printf("____________________________________________________________________\n");
	printf("| NOMBRE DE USUARIO:                                                |\n");
	printf("| AVISOS IMPORTANTES!                                               |\n");
	printf("| a) El nombre de usuario debe tener entre 6 y 10 caracteres        |\n");
	printf("| b) Debe comenzar con una letra minuscula                          |\n");
	printf("| c) Tener al menos 2 letras mayusculas                             |\n");
	printf("| d) Tener como maximo 3 digitos                                    |\n");
	printf("|___________________________________________________________________|\n");
	
	user(usuario, nombre);
	strcpy(lectura.nomUsuario, nombre);
	printf ("\nUsuario Creado...\n\n");
	system ("pause");
	system ("cls");
	printf("__________________________________________________________________________________________________________________\n");
 	printf("| CONTRASEÑA                                                                                                      |\n");
	printf("| AVISOS IMPORTANTES!                                                                                             |\n");
	printf("| a)Debera contener al menos una letra mayuscula, una letra minuscula y un numero.                                |\n");
	printf("| b)No podra contener ningun caracter de puntuacion, ni acentos, ni espacios. Solo caracteres alfanumericos.      |\n");
	printf("| c)Debera tener entre 6 y 32 caracteres                                                                          |\n");
	printf("| d)No debe tener mas de 3 caracteres numericos consecutivos.                                                     |\n");
	printf("| e)No debe tener 2 caracteres consecutivos que refieran a letras alfabeticamente consecutivas                    |\n");
	printf("|_________________________________________________________________________________________________________________|\n");
	
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











