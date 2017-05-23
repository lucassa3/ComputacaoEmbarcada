/************************************************************************
* Rafael Corsi   - Insper
* rafael.corsi@insper.edu.br
*
* Computação Embarcada
*
* 09-PIO-DRIVER
************************************************************************/


#include "asf.h"
#include "conf_clock.h"

#include "driver/pmc_insper.h"
#include "driver/pio_insper.h"

/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/**
 * LEDs
 */
#define LED_PIO_ID		ID_PIOC
#define LED_PIO         PIOC
#define LED_PIN		    8
#define LED_PIN_MASK    (1<<LED_PIN)

/**
 * Botão
 */
#define BUT_PIO_ID      ID_PIOA
#define BUT_PIO         PIOA
#define BUT_PIN		    11
#define BUT_PIN_MASK    (1 << BUT_PIN)
#define BUT_DEBOUNCING_VALUE  79

/************************************************************************/
/* prototype                                                             */
/************************************************************************/
void led_init(int estado);
void but_init(void);

/************************************************************************/
/* Funções	                                                            */
/************************************************************************/

/**
 * @Brief Inicializa o pino do LED
 */
void led_init(int estado){
	
		_pmc_enable_periph_clock(LED_PIO_ID);
		_pio_set_output(LED_PIO,LED_PIN_MASK,1,1);
		
};

/**
 * @Brief Inicializa o pino do BUT
 */
void but_init(void){
	//desativa saída
	_pio_clear(BUT_PIO, BUT_PIN_MASK); //func do pio_insper.c
	//ativa controle do pino no PIO
	_pio_set_output(BUT_PIN_MASK,BUT_PIN_MASK,1,1); //func do pio_insper.c
	//ativa o pull-up
	_pio_pull_up(BUT_PIO, BUT_PIN_MASK, 1); //func do pio_insper.c
	//ativa debouncing
	_pio_set_input(BUT_PIO,BUT_PIN_MASK,PIO_PULLUP | PIO_DEBOUNCE); //func do pio_insper.c

};



/************************************************************************/
/* Main                                                                 */
/************************************************************************/
int main(void)
{
	_pmc_enable_periph_clock(ID_PIOA);
	_pmc_enable_periph_clock(ID_PIOC);
	/************************************************************************/
	/* Inicialização básica do uC                                           */
	/************************************************************************/

	sysclk_init();
	WDT->WDT_MR = WDT_MR_WDDIS;

	/************************************************************************/
	/* Inicializao I/OS                                                     */
	/************************************************************************/

	led_init(1);
    but_init();

	/************************************************************************/
	/* Super loop                                                           */
	/************************************************************************/

	while(1){
		/**
		* @Brief Verifica constantemente o status do botão
		* 1 : não apertado
		* 0 : apertado
		*/
	    if(BUT_PIO->PIO_PDSR & (BUT_PIN_MASK)){
			LED_PIO->PIO_CODR = LED_PIN_MASK;
        }
		else{
			LED_PIO->PIO_SODR = LED_PIN_MASK;
        }
	};
}


