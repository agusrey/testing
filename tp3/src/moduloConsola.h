#define OK 0
#define ERROR -1

typedef enum {
	RUN = 0, SLOW, STOP, QUIT, ULTIMO
} comando_t;

typedef struct{
	comando_t comando;		//comando
	unsigned int vmax;		//consigna de velocidad máxima en Hz
	unsigned int vmin;		//consigna de velocidad mínima en Hz
	unsigned int ramp_up;	//consigna rampa aceleracion en centesimas de segundo
	unsigned int ramp_down; //consigna rampa desaceleración en centésima de segundo
}status_t;


void consolaInit(char *pantalla);
int verificarComando(char *comando, char *pantalla);
void procesarComando(char*comando, char*pantalla);
