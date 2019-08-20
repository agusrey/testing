#include "unity.h"

/*	Módulo Driver de Consola
 * 	Este módulo correrá en una tarea que lo inicializa, luego se bloquea en un gets, y lo llama cuando recibe el string
 *
 * 1) Al inicializar, se presentará el mensaje de bienvenida
 *
 * 2) Si se recibe un comando no reconocido se presentará un mensaje de error.
 * 	  Los comandos válidos son: run, slow, stop, quit.
 *
 * 3) Al recibir un comando válido, este se cargará en la estructura status y se dará un mensaje de OK.
 *
 * 4) Se agregan comandos que especifican valores de velocidad (vmax y vmin). El valor correspondiente se recibe en un siguiente paso presentando un
 * mensaje que indica que ingrese el valor correspondiente. Dicho valor se guarda en la estructura status.
 *
 * 5) Si los valores están fuera de intervalo, se ignora el ingreso y se informa del error por consola.
 *
 * 6) Se agregan 2 nuevos comandos que especifican valores (ramp up, ramp down). El valor correspondiente se recibe en un siguiente paso presentando un
 * mensaje que indica que ingrese el valor correspondiente. Dicho valor se guarda en la estructura status.
 *
 *7) Al recibir el comando quit da un mensaje de despedida.
 *
 *8) Como respuesta a cada comando, se informará por consola el status del sistema
 *
 *9) Al inicializar, se cargará en la estructura status los valores por default y se informarán por consola
 *
 *
 */

#include "moduloConsola.h"

/*
 * TEST NUMERO 1
 */
void test_inicializacion(void) {
	char pantalla[200] = { 0 };	//simula la pantalla, recibe los bytes que se envían a consola
	consolaInit(pantalla);
	TEST_ASSERT_EQUAL_STRING("Bienvenido al Control de Motor\r\n", pantalla);
}

/*
 * TEST NUMERO 2
 */

void test_comandoValido(void) {
	char pantalla[200] = { 0 };
	char comando[] = "aaa\r\n";
	int num_comando;
	num_comando = verificarComando(comando, pantalla);
	TEST_ASSERT_EQUAL_STRING("Comando Invalido\r\n", pantalla);
	TEST_ASSERT_EQUAL(num_comando, ERROR);
}
