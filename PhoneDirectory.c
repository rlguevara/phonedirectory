/*Universidad Catolica Andres Bello
Escuela de Ingenieria Informatica
Algoritmos y Programacion II
Profesor: Jesus Larez
Alumna: Rosa Linda Guevara
Proyecto 2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_REGISTROS 100 /*Maximo numero de registros*/
#define MAX_CAMPOS 5

struct Nuevo_campo{		/*Estructura de los campos adicionales*/
	char campo1[50]; 
	char campo2[50];
	char campo3[50];
	char campo4[50];
	char campo5[50];
}nuevo_cam[MAX_CAMPOS];

struct {				/*Estructura donde van los datos*/
	char  nombre[20];
	char  apellido[20];
	char  empresa[20];
	char   tel_casa[20];
	char  tel_trabajo[20];
	char  tel_movil[20];
	char email[50];
	char clasifica[50]; //clasificacion en la que va a estar la persona (todos, personales, trabajo)	
	struct Nuevo_campo nuevo;
} reg [MAX_REGISTROS];

int opc,num,num_reg;
int indice[MAX_REGISTROS];	/*Indice donde se guarda el orden de los contactos*/

void Esperar_tecla(){	
	setbuf(stdin,NULL);
	getchar();
	system("clear");
}
/**********************************************************************/
int Validar_letras(char aux[]){		/*Validar solo la entrada de letras en los campos*/
int letra,aux2,i;
							for(i=0; i<num_reg; i++){
								letra=isalpha(aux[i]);

							if(letra!=0){
								aux2=letra;
								}
								else{
								aux2=letra;	
								}
							}
							if(aux2==0){
								printf("La cadena no es valido,vuelva a intentarlo\n");
								return 0;
								}else{
								return 1;}
}
/**********************************************************************/

void rellenar_campos(){		/*Se rellenan los campos y se guarda el directorio en el archivo*/
int i,nume;
char nombre[50],aux[50];

printf("Ingrese el nombre del archivo donde se va a guardar el directorio:\n");
scanf("%s",nombre);

printf("Antes de rellenar los campos, desea anadir algun campo adicional?\n");
scanf("%d",&opc);

if(opc==1){//Coloca el campo adicional en todos los registros
		printf("Introduzca el numero de campos adicionales (max 5):");
		scanf("%d",&num);
}

FILE *fp;
		if((fp=fopen(nombre,"w"))==NULL){
		fprintf(stderr,"leer_productos: no se pudo abrir %s\n",nombre);
		exit(1);}	
		
	for(i=0; i<num_reg; i++){
		printf("___________________________________________________\n");
		
		while(1){
			printf("\nNombre:");		/*Cada campo de tiene un ciclo para poder validar las letras*/
			scanf("%s", reg[i].nombre);
			strcpy(aux,reg[i].nombre);
			if(Validar_letras(aux)==0)
				continue;
			else
				break;
		}
		while(1){
			printf("\nApellido:");
			scanf("%s", reg[i].apellido);
			strcpy(aux,reg[i].apellido);
			if(Validar_letras(aux)==0)
				continue;
			else
				break;
		}

		while(1){
			printf("\nOrganizacion:");
			scanf("%s", reg[i].empresa);
			strcpy(aux,reg[i].empresa);
			if(Validar_letras(aux)==0)
				continue;
			else
				break;
		}
		
		while(1){
			printf("\nTelefono casa:");		/*Validacion para la entrada de numeros*/
			scanf("%s", reg[i].tel_casa);
			nume=atoi(reg[i].tel_casa);
		if(nume!=0 || (strcmp(reg[i].tel_casa,"null")==0)) {
		break;
			}
		}
		while(1){
			printf("\nTelefono trabajo:");
			scanf("%s", reg[i].tel_trabajo);
			nume=atoi(reg[i].tel_trabajo);
		if(nume!=0 || (strcmp(reg[i].tel_trabajo,"null")==0)) {
		break;
			}
		}

		while(1){
			printf("\nTelefono movil:");
			scanf("%s", reg[i].tel_movil);
			nume=atoi(reg[i].tel_movil);
		if(nume!=0 || (strcmp(reg[i].tel_movil,"null")==0)) {
		break;
			}
		}
		while(1){
			printf("\nEmail:");
			scanf("%s", reg[i].email);
			strcpy(aux,reg[i].email);
			if(Validar_letras(aux)==0)
				continue;
			else
				break;
		}
		
		while(1){
			printf("\nClasificacion:");
			scanf("%s", reg[i].clasifica);
			strcpy(aux,reg[i].clasifica);
			if(Validar_letras(aux)==0)
				continue;
			else
				break;
		}
		
		if(opc==1){							/*Se toman los nuevos campos del directorio*/
				if(num==1){
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo1);
				}
				if(num==2){
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo1);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo2);
				}
				if(num==3){
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo1);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo2);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo3);
				}
				if(num==4){
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo1);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo2);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo3);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo4);
				}
				if(num==5){
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo1);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo2);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo3);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo4);
				printf("\nNuevo campo:");
				scanf("%s",nuevo_cam[i].campo5);
				}
		}

		fprintf(fp,"%s ",reg[i].nombre);		/*Se introducen los contactos en el archivo*/
		fprintf(fp,"%s ",reg[i].apellido);		/*Si hay nuevos campos adicionales, se agregan tambien*/
		fprintf(fp,"%s ",reg[i].empresa);
		fprintf(fp,"%s ",reg[i].tel_casa);
		fprintf(fp,"%s ",reg[i].tel_trabajo);
		fprintf(fp,"%s ",reg[i].tel_movil);
		fprintf(fp,"%s ",reg[i].email);
		fprintf(fp,"%s ",reg[i].clasifica);
		if(opc==1){
				if(num==1){
				fprintf(fp,"%s ",nuevo_cam[i].campo1);
				}
				if(num==2){
				fprintf(fp,"%s ",nuevo_cam[i].campo1);
				fprintf(fp,"%s ",nuevo_cam[i].campo2);
				}
				if(num==3){
				fprintf(fp,"%s ",nuevo_cam[i].campo1);
				fprintf(fp,"%s ",nuevo_cam[i].campo2);
				fprintf(fp,"%s ",nuevo_cam[i].campo3);
				}
				if(num==4){
				fprintf(fp,"%s ",nuevo_cam[i].campo1);
				fprintf(fp,"%s ",nuevo_cam[i].campo2);
				fprintf(fp,"%s ",nuevo_cam[i].campo3);
				fprintf(fp,"%s ",nuevo_cam[i].campo4);
				}
				if(num==5){
				fprintf(fp,"%s ",nuevo_cam[i].campo1);
				fprintf(fp,"%s ",nuevo_cam[i].campo2);
				fprintf(fp,"%s ",nuevo_cam[i].campo3);
				fprintf(fp,"%s ",nuevo_cam[i].campo4);
				fprintf(fp,"%s ",nuevo_cam[i].campo5);
				}
			}
		fprintf(fp,"\n");
	}
	fclose(fp);
}
/**********************************************************************/

void mostrar(int i){									/*Muestra los contactos, la diferencia con los anteriores*/
		printf("Nombre (reg %d)%s\n",i, reg[i].nombre);	/*es que no tiene ningun ciclo*/
		printf("Apellido (reg %d)%s\n",i, reg[i].apellido);
		printf("Empresa (reg %d)%s\n",i, reg[i].empresa);
		printf("Telefono casa(reg %d)%s\n",i, reg[i].tel_casa);
		printf("Telefono trabajo(reg %d)%s\n",i, reg[i].tel_trabajo);
		printf("Telefono movil(reg %d)%s\n",i, reg[i].tel_movil);
		printf("Email (reg %d)%s\n",i, reg[i].email);
		printf("Clasificacion (reg %d)%s\n",i, reg[i].clasifica);
		if(num==1){
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo1);
				}
				if(num==2){
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo1);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo2);
				}
				if(num==3){
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo1);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo2);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo3);
				}
				if(num==4){
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo1);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo2);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo3);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo4);
				}
				if(num==5){
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo1);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo2);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo3);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo4);
				printf("Nuevo campo: %s\n",nuevo_cam[i].campo5);
				}
}
	
/**********************************************************************/

void mostrar_rellenar(){			/*Muestra todo los contactos una vez ya cargados*/
int i;
		for(i=0; i<num_reg; i++){
		printf("\n===================================================\n");
		mostrar(i);
		}
		printf("\n");
}

/**********************************************************************/

int *ordenar_nombre(int indice[]){ 		//Ordena por nombre los contactos, de mayor a menor
int i,j,comp;

	for(i=0;i<num_reg;i++)                // inicializa el indice
		indice[i]=i;

	for(i=0; i<num_reg; i++){			//Se utilizo un metodo el ordenamiento Bubblesort
		for(j=num_reg; j>=i; --j){
			comp=strcmp(reg[i].nombre,reg[j].nombre);
			if(comp<0){
				int t=indice[j];
				indice[j]=indice[i];
				indice[i]=t;
				}
			}
		}
	return indice;
}		

int *ordenar_apellido(int indice[]){	//Ordena por apellido los contactos, de mayor a menor
int i,j,comp;
for(i=0;i<num_reg;i++)                // inicializa el indice
		indice[i]=i;

	for(i=0; i<num_reg; i++){			//Se utilizo un metodo el ordenamiento Bubblesort
		for(j=num_reg; j>=i; --j){
			comp=strcmp(reg[i].apellido,reg[j].apellido);
			if(comp<0){
				int t=indice[j];
				indice[j]=indice[i];
				indice[i]=t;
				}
			}
		}
	return indice;
}		
int *ordenar_empresa(int indice[]){		//Ordena por empresa, de mayor a menor
int i,j,comp;

	for(i=0;i<num_reg;i++)                // inicializa el indice
		indice[i]=i;

	for(i=0; i<num_reg; i++){			//Se utilizo un metodo el ordenamiento Bubblesort
		for(j=num_reg; j>=i; --j){
			comp=strcmp(reg[i].empresa,reg[j].empresa);
			if(comp<0){
				int t=indice[j];
				indice[j]=indice[i];
				indice[i]=t;
				}
			}
		}	
	return indice;
}		

void imprimir(int op){		/*Se imprime en pantalla con el orden especificado*/
int n,i;
		
		if(op==1){
		ordenar_nombre(indice);
	
		for(i=0; i<num_reg; i++){
		n=indice[i];
		printf("===================================================\n");
		mostrar(n);
			}
		}
		if(op==2){
		ordenar_apellido(indice);
	
		for(i=0; i<num_reg; i++){
		n=indice[i];
		printf("===================================================\n");
		mostrar(n);
			}
		}
		if(op==3){
		ordenar_empresa(indice);
	
		for(i=0; i<num_reg; i++){
		n=indice[i];
		printf("===================================================\n");
		mostrar(n);
			}
		}
	}
/**********************************************************************/

int verificar(char cadena[], char subcadena[])	/*Verifica si una cadena esta dentro de otra*/
{
    int i, j;
    int l_cadena = strlen(cadena);
    int l_subcadena = strlen(subcadena);

    if(l_cadena < l_subcadena)
      return 0;
    if(cadena[ 0 ]=='\0' && subcadena[ 0 ]=='\0')
       return 1;

    for(i=0; i < l_cadena; i++)
       if(cadena[ i ]==subcadena[ 0 ])
       {
           if(l_cadena-i < l_subcadena)
              return 0;

            for(j=0; j < l_subcadena; j++)
                 if(cadena[ i+j ]!=subcadena[ j ])
                    break;

            if(j==l_subcadena)
               return 1;
       }

    return 0;
}

void buscar(char cadena[]){	/*Busca la palabra por nombre,apellido,organizacion*/
int i;						/*Utiliza la funcion anterior para saber si lo que se esta buscando se encuentra*/
char nom[20],ape[20],emp[20];	
	
	for(i=0; i<num_reg; i++){
		strcpy(nom,reg[i].nombre);
		strcpy(ape,reg[i].apellido);
		strcpy(emp,reg[i].empresa);
			if((verificar(nom,cadena)==1) || (verificar(ape,cadena)==1) || (verificar(emp,cadena)==1)){
				printf("===================================================\n");
				mostrar(i);
				}else{printf("No se ha encontrado ninguna coincidencia\n"); break;}
		}
}		
/**********************************************************************/

void clasificar_registros(char clasificacion[]){	/*Muestra en pantalla por clasificaciones*/
int i,comp;
char todos[10]="todos";	

	for(i=0; i<num_reg; i++){
		comp=strcmp(reg[i].clasifica,clasificacion);
		if(comp==0){
			printf("===================================================\n");
			mostrar(i);
			}
		if(strcmp(clasificacion,todos)==0){
			printf("===================================================\n");
			mostrar(i);
			}
	}
}
/**********************************************************************/

void abrir_archivo(int num){	/*Se carga un archivo ya creado y se trabaja en el programa*/
FILE *fp;
char nombre[50];
int n_reg=0;

	printf("Introduzca el nombre del archivo:\n");
	scanf("%s",nombre);
	
		if((fp=fopen(nombre,"r"))==NULL){
		fprintf(stderr,"No se pudo abrir %s\n",nombre);
		exit(1);}		
	
	while(!feof(fp)){
	fscanf(fp,"%s %s %s %s %s %s %s %s",reg[n_reg].nombre,reg[n_reg].apellido,reg[n_reg].empresa,
	reg[n_reg].tel_casa,reg[n_reg].tel_trabajo,reg[n_reg].tel_movil,reg[n_reg].email,reg[n_reg].clasifica);
	
				if(num==1){
				fscanf(fp,"%s",nuevo_cam[n_reg].campo1);
				}
				if(num==2){
				fscanf(fp,"%s %s",nuevo_cam[n_reg].campo1,nuevo_cam[n_reg].campo2);
				}
				if(num==3){
				fscanf(fp,"%s %s %s",nuevo_cam[n_reg].campo1,nuevo_cam[n_reg].campo2,nuevo_cam[n_reg].campo3);
				}
				if(num==4){
				fscanf(fp,"%s %s %s %s",nuevo_cam[n_reg].campo1,nuevo_cam[n_reg].campo2,nuevo_cam[n_reg].campo3,nuevo_cam[n_reg].campo4);
				}
				if(num==5){
				fscanf(fp,"%s %s %s %s %s",nuevo_cam[n_reg].campo1,nuevo_cam[n_reg].campo2,nuevo_cam[n_reg].campo3,
				nuevo_cam[n_reg].campo4,nuevo_cam[n_reg].campo5);
				}
		n_reg++;
	}
	fclose(fp);			
}
/**********************************************************************/

void clave_rellenar(){	/*Se ingresa la clave para guardarla en el archivo*/
FILE *clav;
char clave[20];

				if((clav=fopen("Clave.txt","w"))==NULL){
					fprintf(stderr,"No se pudo abrir %s\n","Clave.txt");
					exit(1);}	
				printf("Clave para el directorio: ");
				scanf("%s",clave);
				fputs(clave,clav);							
				fclose(clav);	
}

void clave(){	/*Se pide la clave y si no es correcta, no abre el programa*/
FILE *clav;
char clave[20],archclav[20];

				if((clav=fopen("Clave.txt","r"))==NULL){
					fprintf(stderr,"No se pudo abrir %s\n","Clave.txt");
					exit(1);}	
				printf("Clave para ingresar en el directorio: ");
				scanf("%s",clave);
				fscanf(clav,"%s",archclav);
				
				if(strcmp(clave,archclav)==0){
					printf("Cargado con exito\n\n");
					printf("Presione una tecla para continuar\n");
					Esperar_tecla();				
				} 
				else{
				printf("Clave Incorrecta\nSe ha cerrado el programa\n"); 
				exit(0);				
				}		
}
/**********************************************************************/

void encriptar(){	/*Encripta el archivo*/
FILE *arc,*enc;
char car,nombre[20];
   
   printf("Ingrese el nombre del archivo donde se guardo el directorio:\n");
   scanf("%s",nombre);
   printf("\n");

     arc = fopen( nombre, "r" );
     enc = fopen("Encripta.txt","w");
     car=fgetc(arc);
     while(car>0){      
            fputc(car+5,enc);
            car=fgetc(arc);
     }
     fclose(arc);
     fclose(enc);
     
     arc = fopen("Encrita.txt","r");
     enc = fopen( nombre, "w" );
	 car=fgetc(arc);
     while(car>0){      
            fputc(car,enc);
            car=fgetc(arc);
     }  
     fclose(arc);
     fclose(enc);
     
}

void desencriptar(){	/*Desencripta el archivo*/
FILE *arc,*enc;
char car,nombre[20];
   
   printf("Ingrese el nombre del archivo donde se guardo el directorio:\n");
   scanf("%s",nombre);
   
   
	 arc = fopen(nombre,"r");
     enc = fopen( "Encripta.txt", "w" );
     
     car=fgetc(arc);
     while(car>0){      
            fputc(car-5,enc);
            car=fgetc(arc);
     }  
     fclose(arc);
     fclose(enc);
     
     arc = fopen("Encripta.txt","r");
     enc = fopen( nombre, "w" );
	 car=fgetc(arc);
     while(car>0){      
            fputc(car,enc);
            car=fgetc(arc);
     }  
     fclose(arc);
     fclose(enc);
}

/**********************************************************************/

int main(){
int opcion,op,encrip,elegir,menu;
char cadena[20],clasificacion[20];

	printf("Bienvenido\n");
	printf("Elija la opcion que desea implementar:\n");
	printf("1.-Cargar el directorio\n");
	printf("2.-Crear el directorio\n");
	printf("3.-Salir\n");
	scanf("%d",&opcion);
	system("clear");
	
	if(opcion==1){
			
	clave();
	
	printf("El archivo esta encriptado? (Si:1; No:2)\n");
	scanf("%d",&encrip);
	
	if(encrip==1)
		desencriptar();
		
	system("clear");	
	printf("Por favor ingrese los datos que se le preguntan :)");
	printf("\n");
	printf("\n");
	printf("Cual es el numero de registros en el archivo?\n");
	scanf("%d",&num_reg);
	printf("Ingrese el numero de campos adicionales que estan en el archivo:\n");
	scanf("%d",&num);	
	abrir_archivo(num);
	printf("Presione una tecla para continuar\n");
	Esperar_tecla();
	
	Menu:
	while(1){
		printf("Bienvenido!\n");
		printf("Elija un opcion:\n\n");
		printf("1.-Mostrar los contactos segun una categoria\n");
		printf("2.-Ordenar los registros\n");
		printf("3.-Buscar una palabra en los registros\n");
		printf("4.-Salir\n");
		scanf("%d",&elegir);
		system("clear");
		
		if(elegir>=1 && elegir<=4){
		
		if(elegir==1){
			printf("Ingrese la clasificacion que desea ver:");
			scanf("%s",clasificacion);
			clasificar_registros(clasificacion);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu;
			if(menu==2)
				exit(0);
			}
		
		if(elegir==2){
			printf("\nDesea...\n");
			printf("1.-Ordenar el directorio por nombre\n");
			printf("2.-Ordenar el directorio por apellido\n");
			printf("3.-Ordenar el directorio por empresa\n");
			scanf("%d",&op);
			imprimir(op);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu;
			if(menu==2)
				exit(0);
			}
			
		if(elegir==3){
			printf("Ingrese la palabra que desea buscar:\n");
			scanf("%s",cadena);
			buscar(cadena);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu;
			if(menu==2)
				exit(0);
			}
			
		if(elegir==4)
			break;
		}
	}
	}
	if(opcion==2){
		
		clave_rellenar();
		printf("Presione una tecla para continuar\n");
		Esperar_tecla();
		
		printf("Ingrese el numero de registros que se van a guardar\n");
		scanf("%d",&num_reg);
		rellenar_campos();
		encriptar();
		system("clear");
		mostrar_rellenar();
		Esperar_tecla();

	Menu1:
	while(1){
		printf("Bienvenido!\n");
		printf("Elija un opcion:\n\n");
		printf("1.-Mostrar los contactos segun una categoria\n");
		printf("2.-Ordenar los registros\n");
		printf("3.-Buscar una palabra en los registros\n");
		printf("4.-Salir\n");
		scanf("%d",&elegir);
		system("clear");
		
		if(elegir>=1 && elegir<=4){
		
		if(elegir==1){
			printf("Ingrese la clasificacion que desea ver:");
			scanf("%s",clasificacion);
			clasificar_registros(clasificacion);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu1;
			if(menu==2)
				exit(0);
			}
		
		if(elegir==2){
			printf("\nDesea...\n");
			printf("1.-Ordenar el directorio por nombre\n");
			printf("2.-Ordenar el directorio por apellido\n");
			printf("3.-Ordenar el directorio por empresa\n");
			scanf("%d",&op);
			imprimir(op);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu1;
			if(menu==2)
				exit(0);
			}
			
		if(elegir==3){
			printf("Ingrese la palabra que desea buscar:\n");
			scanf("%s",cadena);
			buscar(cadena);
			printf("Presione una tecla para continuar\n");
			Esperar_tecla();
			
			printf("Desea volver al menu?\n");
			printf("1.-Si\n");
			printf("2.-No\n");
			scanf("%d",&menu);
			
			if(menu==1)
				goto Menu1;
			if(menu==2)
				exit(0);
			}
			
		if(elegir==4)
			break;
		}
	}
		
}	
	if(opcion==3)
		exit(0);
return 0;
}
