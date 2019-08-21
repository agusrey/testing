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
#include <stdlib.h>

#include "moduloConsola.h"

/*mensajes*/
char mens_bienvenida[] = "Bienvenido al Control de Motor\r\n";
char mens_comando_invalido[] = "Comando Invalido\r\n";
char mens_ok[] = "OK\r\n";
char mens_vmax[] = "Ingrese Vmax =";
char mens_vmin[] = "Ingrese Vmin =";
char mens_ramp_up[] = "Ingrese Ramp Up =";
char mens_ramp_down[] = "Ingrese Ramp Down =";

/*Strings con los Comandos Válidos*/

char comando_run[] = "run\r";
char comando_slow[] = "slow\r";
char comando_stop[] = "stop\r";
char comando_quit[] = "quit\r";
char comando_vmax[] = "vmax\r";
char comando_vmin[] = "vmin\r";
char comando_ramp_up[] = "ramp up\r";
char comando_ramp_down[] = "ramp down\r";

char *comandos[NUM_COMANDOS] = { comando_run, comando_slow, comando_stop,
		comando_quit, comando_vmax, comando_vmin, comando_ramp_up,
		comando_ramp_down };

/*
 * Las siguientes estructuras contienen los valores máximos y mínimos que pueden tomar
 */
const status_t status_max = { ERR, 50, 50, 1000, 1000 };
const status_t status_min = { RUN, 1, 1, 50, 50 };

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
comando_t verificarComando(char *comando, char *pantalla) {
	comando_t ret = ERR;
	int i;
	for (i = 0; i < NUM_COMANDOS; i++) {
		if (strcmp(comando, comandos[i]) == 0) {
			return ((comando_t) i);
		}
	}
	sprintf(pantalla, "%s", mens_comando_invalido);
	return (ERROR);
}

/*
 * Funcion de procesamiento de comando, actualiza variable comando e informa resultado por consola
 */

comando_t procesarComando(char*comando, char*pantalla) {
	comando_t Comando;
	if ((Comando = verificarComando(comando, pantalla)) != ERROR) {
		switch (Comando) {
		case VMAX:
			sprintf(pantalla, "%s", mens_vmax);
			break;
		case VMIN:
			sprintf(pantalla, "%s", mens_vmin);
			break;
		case RAMP_UP:
			sprintf(pantalla, "%s", mens_ramp_up);
			break;
		case RAMP_DOWN:
			sprintf(pantalla, "%s", mens_ramp_down);
			break;
		default:
			status.comando = Comando;
			sprintf(pantalla, "%s", mens_ok);
			break;
		}
	}
	return (Comando);
}

/*
 * Recibe el comando y el string con el valor representado en ascii
 * Lo convierte a entero y lo carga en la variable status en el campo correspondiente
 */

int procesarValoresComando(comando_t comando, char *str) {
	int length;
	int valor;
	int ret = ERROR;

	length = strlen(str);
	str[length - 1] = '\0';

	if ((valor = atoi(str)) != 0) {
		switch (comando) {
		case VMAX:
			if (controlarValor(VMAX, valor) == OK) {
				status.vmax = valor;
				ret = OK;
			}
			break;

		case VMIN:
			if (controlarValor(VMIN, valor) == OK) {
				status.vmin = valor;
				ret = OK;
			}
			break;
		case RAMP_UP:
			if (controlarValor(RAMP_UP, valor) == OK) {
				status.vmax = valor;
				ret = OK;
			}
			break;

		case RAMP_DOWN:
			if (controlarValor(RAMP_DOWN, valor) == OK) {
				status.vmin = valor;
				ret = OK;
			}
			break;

		default:
			ret = ERROR;
			break;
		}
	} else {
		ret = ERROR;
	}
	return (ret);
}

/*
 * Función auxiliar que controla si el valor está dentro de los límites
 * retorna error si está fuera de límite o si al ese comando no le corresponde un valor a controlar
 */
int controlarValor(comando_t comando, int valor) {
	int ret = ERROR;

	switch (comando) {
	case VMAX:
		if (valor <= status_max.vmax && valor >= status_min.vmax)
			ret = OK;
		break;
	case VMIN:
		if (valor <= status_max.vmin && valor >= status_min.vmin)
			ret = OK;
		break;
	case RAMP_UP:
		if (valor <= status_max.ramp_up && valor >= status_min.ramp_up)
			ret = OK;
		break;
	case RAMP_DOWN:
		if (valor <= status_max.ramp_down && valor >= status_min.ramp_down)
			ret = OK;
		break;

	default:
		break;
	}

	return (ret);
}

