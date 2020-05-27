#include <stdlib.h>
#include <stdio.h>
#include "files.h"

#include <raylib.h>

void histore(int *puntaje){
	//const char *p = (char*)puntaje;
	comprobar();
    FILE *archivo;
    //char c = (char) puntaje;
	char caracter[100];
    archivo = fopen("histore.txt", "r");
	fgets(caracter, 100, archivo);   
	fclose(archivo);
	int cadena = atoi(caracter);
	if(*puntaje>cadena){
		FILE *archi;
		archi = fopen("histore.txt", "w");
		char cadena[100];
		sprintf(cadena, "%d", *puntaje);
		fputs(cadena, archi);
		fclose(archi);		
	}
}

void comprobar(){
	FILE *archivo;
	archivo = fopen("histore.txt", "a");
	fclose(archivo);
}