/*
 * Módulo Consola
 *
 * Autor: Agustín Rey agustinrey61@gmail.comn
 *
 * Este módulo recibe comandos por consola y los procesa, retornando mensajes de OK o de Error
 *
 */

#include <stdio.h>
#include <string.h>

#include "moduloConsola.h"

/*mensajes*/
char mens_bienvenida[] = "Bienvenido al Control de Motor\r\n";
char mens_comando_invalido[] = "Comando Invalido\r\n";
char mens_ok[] = "OK\r\n";

/*Strings con los Comandos Válidos*/
#define NUM_COMANDOS 4
char comando_run[] = "run\r\n";
char comando_slow[] = "slow\r\n";
char comando_stop[] = "stop\r\n";
char comando_quit[] = "quit\r\n";

char *comandos[NUM_COMANDOS] = { comando_run, comando_slow, comando_stop,
		comando_quit };

status_t status;

/*
 * Función de Inicialización (bienvenida)
 */

void consolaInit(char *pantalla) {
	sprintf(pantalla, "%s", mens_bienvenida);
}

/*
 * Funcion de verificación de comando válido
 * retorna el número de comando
 */
int verificarComando(char *comando, char *pantalla) {
	int i;
	for (i = 0; i < NUM_COMANDOS; i++) {
		if (strcmp(comando, comandos[i]) == 0) {
			return (i);
		}
	}
	sprintf(pantalla, "%s", mens_comando_invalido);
	return (ERROR);
}

/*
 * Funcion de procesamiento de comando, actualiza variable comando e informa resultado por consola
 */


void procesarComando(char*comando, char*pantalla) {
	comando_t Comando;
	if ((Comando = verificarComando(comando, pantalla)) != ERROR) {
		status.comando = Comando;
		sprintf(pantalla, "%s", mens_ok);
	}
}

