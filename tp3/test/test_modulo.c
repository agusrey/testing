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
extern status_t status;
char pantalla[200] = { 0 };	//simula la pantalla, recibe los bytes que se envían a consola

void SetUp(void) {
	status.comando = ERR;
	sprintf(&pantalla[0], " ");
}

/*
 * TEST NUMERO 1 - mensaje de bienvenida
 */
void test_inicializacion(void) {
	consolaInit(pantalla);
	TEST_ASSERT_EQUAL_STRING("Bienvenido al Control de Motor\r\n", pantalla);
}

/*
 * TEST NUMERO 2- Puse dos Pruebas, por comando válido e  inválido
 */

void test_comandoInValido(void) {

	char comando[] = "Run\r";
	int num_comando;
	num_comando = verificarComando(comando, pantalla);
	TEST_ASSERT_EQUAL_STRING("Comando Invalido\r\n", pantalla);
	TEST_ASSERT_EQUAL(num_comando, ERROR);

}

void test_comandoValido(void) {

	char comando[] = "run\r";
	int num_comando;
	sprintf(&pantalla[0], " ");
	num_comando = verificarComando(comando, pantalla);
	TEST_ASSERT_EQUAL_STRING(" ", pantalla);//verifica que no se escribió nada en pantalla
	TEST_ASSERT_EQUAL(num_comando, 0);
}

/*
 * TEST NUMERO 3 - Cargar estructura e informar OK
 */

void test_procesarComandoValido(void) {

	char comando[] = "run\r";
	int num_comando;
	procesarComando(comando, pantalla);
	TEST_ASSERT_EQUAL_STRING("OK\r\n", pantalla);
	TEST_ASSERT_EQUAL(status.comando, RUN);
}

/*
 * TEST NUMERO 4 - Toma valores para comandos nuevos
 */

void test_procesarValores(void) {

	char comando[] = "vmin\r";
	char valor[] = "44\r";
	int retorno;
	comando_t num_comando;
	num_comando = procesarComando(comando, pantalla);
	retorno = procesarValoresComando(num_comando, valor);
	TEST_ASSERT_EQUAL_STRING("Ingrese Vmin =", pantalla);
	TEST_ASSERT_NOT_EQUAL(retorno, ERROR);
	TEST_ASSERT_EQUAL(status.vmin, 44);

}

/*
 * TEST NUMERO 5 - Verificar que los valores están en rango antes de cargarlos
 */

void test_verificarValores(void) {

	char comando[] = "vmax\r";
	char valor[] = "55\r";
	int retorno;
	comando_t num_comando;
	num_comando = procesarComando(comando, pantalla);
	retorno = procesarValoresComando(num_comando, valor);
	TEST_ASSERT_EQUAL_STRING("Ingrese Vmax =", pantalla);
	TEST_ASSERT_EQUAL(retorno, ERROR);
}

