#define OK 0
#define ERROR -1

typedef enum {
	RUN = 0, SLOW, STOP, QUIT, VMAX, VMIN, ERR
} comando_t;

#define NUM_COMANDOS ERR

typedef struct{
	comando_t comando;		//comando
	unsigned int vmax;		//consigna de velocidad máxima en Hz
	unsigned int vmin;		//consigna de velocidad mínima en Hz
	unsigned int ramp_up;	//consigna rampa aceleracion en centesimas de segundo
	unsigned int ramp_down; //consigna rampa desaceleración en centésima de segundo
}status_t;


void consolaInit(char *pantalla);
comando_t verificarComando(char *comando, char *pantalla);
comando_t procesarComando(char *comando, char *pantalla);
int procesarValoresComando(comando_t comando, char *str);
int controlarValor(comando_t comando, int valor);
