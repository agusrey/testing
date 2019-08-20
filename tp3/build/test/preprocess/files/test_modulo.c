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
