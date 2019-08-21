#include "build/temp/_test_modulo.c"
#include "moduloConsola.h"
#include "unity.h"
extern status_t status;

char pantalla[200] = { 0 };



void SetUp(void) {

 status.comando = ERR;

 sprintf(&pantalla[0], " ");

}









void test_inicializacion(void) {

 consolaInit(pantalla);

 UnityAssertEqualString((const char*)(("Bienvenido al Control de Motor\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(44));

}











void test_comandoInValido(void) {



 char comando[] = "Run\r";

 int num_comando;

 num_comando = verificarComando(comando, pantalla);

 UnityAssertEqualString((const char*)(("Comando Invalido\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(56));

 UnityAssertEqualNumber((UNITY_INT)((num_comando)), (UNITY_INT)((-1)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);



}



void test_comandoValido(void) {



 char comando[] = "run\r";

 int num_comando;

 sprintf(&pantalla[0], " ");

 num_comando = verificarComando(comando, pantalla);

 UnityAssertEqualString((const char*)((" ")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(67));

 UnityAssertEqualNumber((UNITY_INT)((num_comando)), (UNITY_INT)((0)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}











void test_procesarComandoValido(void) {



 char comando[] = "run\r";

 int num_comando;

 procesarComando(comando, pantalla);

 UnityAssertEqualString((const char*)(("OK\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(80));

 UnityAssertEqualNumber((UNITY_INT)((status.comando)), (UNITY_INT)((RUN)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

}











void test_procesarValores(void) {



 char comando[] = "vmin\r";

 char valor[] = "44\r";

 int retorno;

 comando_t num_comando;

 num_comando = procesarComando(comando, pantalla);

 retorno = procesarValoresComando(num_comando, valor);

 UnityAssertEqualString((const char*)(("Ingrese Vmin =")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(96));

 if (((retorno) != (-1))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(97)));};

 UnityAssertEqualNumber((UNITY_INT)((status.vmin)), (UNITY_INT)((44)), (

((void *)0)

), (UNITY_UINT)(98), UNITY_DISPLAY_STYLE_INT);



}











void test_verificarValores(void) {



 char comando[] = "vmax\r";

 char valor[] = "55\r";

 int retorno;

 comando_t num_comando;

 num_comando = procesarComando(comando, pantalla);

 retorno = procesarValoresComando(num_comando, valor);

 UnityAssertEqualString((const char*)(("Ingrese Vmax =")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(114));

 UnityAssertEqualNumber((UNITY_INT)((retorno)), (UNITY_INT)((-1)), (

((void *)0)

), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

}











void test_procesarValores2(void) {



 char comando[] = "ramp up\r";

 char valor[] = "200\r";

 int retorno;

 comando_t num_comando;

 num_comando = procesarComando(comando, pantalla);

 retorno = procesarValoresComando(num_comando, valor);

 UnityAssertEqualString((const char*)(("Ingrese Ramp Up =")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(130));

 if (((retorno) != (-1))) {} else {UnityFail( ((" Expected Not-Equal")), (UNITY_UINT)((UNITY_UINT)(131)));};

 UnityAssertEqualNumber((UNITY_INT)((status.vmin)), (UNITY_INT)((44)), (

((void *)0)

), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);



}



void test_verificarValores2(void) {



 char comando[] = "ramp down\r";

 char valor[] = "5\r";

 int retorno;

 comando_t num_comando;

 num_comando = procesarComando(comando, pantalla);

 retorno = procesarValoresComando(num_comando, valor);

 UnityAssertEqualString((const char*)(("Ingrese Ramp Down =")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(144));

 UnityAssertEqualNumber((UNITY_INT)((retorno)), (UNITY_INT)((-1)), (

((void *)0)

), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

}
