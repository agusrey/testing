#include "build/temp/_test_modulo.c"
#include "moduloConsola.h"
#include "unity.h"


void test_inicializacion(void) {

 char pantalla[200]={0};

 consolaInit(pantalla);

 UnityAssertEqualString((const char*)(("Bienvenido al Control de Motor\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(35));

}



void test_comandoValido(void){

 char pantalla[200]={0};

 char comando[]="aaa\r\n";

 int num_comando;

 num_comando=verificarComando(comando, pantalla);

 UnityAssertEqualString((const char*)(("Comando Invalido\r\n")), (const char*)((pantalla)), (

((void *)0)

), (UNITY_UINT)(43));

 UnityAssertEqualNumber((UNITY_INT)((num_comando)), (UNITY_INT)((-1)), (

((void *)0)

), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

}
