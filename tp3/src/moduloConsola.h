#define OK 0
#define ERROR -1

typedef enum {
	RUN = 0, SLOW, STOP, QUIT
} comandos_t;

void consolaInit(char *pantalla);
int verificarComando(char *comando, char *pantalla);
