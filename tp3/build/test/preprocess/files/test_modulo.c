#include "build/temp/_test_modulo.c"
#include "moduloConsola.h"
#include "unity.h"
extern status_t status;

char pantalla[200] = { 0 };



void SetUp(void) {

 status.comando = ULTIMO;

 sprintf(&pantalla[0],"");

}









void test_inicializacion(void) {

 consolaInit(pantalla);

 UnityAssertEqualString((const char*)(("Bienvenido al Control de Motor\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(44));

}











void test_comandoInValido(void) {



 char comando[] = "Run\r\n";

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



 char comando[] = "run\r\n";

 int num_comando;

 sprintf(&pantalla[0],"");

 num_comando = verificarComando(comando, pantalla);

 UnityAssertEqualString((const char*)(("")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(67));

 UnityAssertEqualNumber((UNITY_INT)((num_comando)), (UNITY_INT)((0)), (

((void *)0)

), (UNITY_UINT)(68), UNITY_DISPLAY_STYLE_INT);

}











void test_procesarComandoValido(void) {



 char comando[] = "run\r\n";

 int num_comando;

 procesarComando(comando, pantalla);

 UnityAssertEqualString((const char*)(("OK\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(80));

 UnityAssertEqualNumber((UNITY_INT)((status.comando)), (UNITY_INT)((RUN)), (

((void *)0)

), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);

}
