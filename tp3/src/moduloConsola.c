#include <stdio.h>
#include <string.h>

#include "moduloConsola.h"
/*mensajes*/
char mens_bienvenida[] = "Bienvenido al Control de Motor\r\n";
char mens_comando_invalido[] = "Comando Invalido\r\n";

/*Strings con los Comandos Válidos*/
#define NUM_COMANDOS 4
char comando_run[] = "run\r\n";
char comando_slow[] = "slow\r\n";
char comando_stop[] = "stop\r\n";
char comando_quit[] = "quit\r\n";


char *comandos[NUM_COMANDOS] = { comando_run, comando_slow, comando_stop,
		comando_quit };

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
return(ERROR);
}

