#include <stdio.h>

#include "moduloConsola.h"

char mens_bienvenida[]="Bienvenido al Control de Motor\r\n";


void consolaInit(char *pantalla){
	sprintf(pantalla,"%s",mens_bienvenida);

}
