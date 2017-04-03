/************************************************************************
* Rafael Corsi   - Insper
* rafael.corsi@insper.edu.br
*
* Computação Embarcada
*
* 10-PIO-INTERRUPCAO
*
* [ref] http://www.atmel.com/Images/Atmel-42142-SAM-AT03258-Using-Low-Power-Mode-in-SAM4E-Microcontroller_Application-Note.pdf
* [ref] https://www.eecs.umich.edu/courses/eecs373/labs/refs/M3%20Guide.pdf
************************************************************************/


#include "asf.h"
#include "conf_clock.h"



/************************************************************************/
/* Defines                                                              */
/************************************************************************/

/**
 * LEDs
 */
#define LED_1_PIO_ID		ID_PIOC
#define LED_1_PIO         PIOC
#define LED_1_PIN		    8
#define LED_1_PIN_MASK    (1 << LED_1_PIN)

#define LED_2_PIO_ID		ID_PIOC
#define LED_2_PIO         PIOC
#define LED_2_PIN		    0
#define LED_2_PIN_MASK    (1 << LED_2_PIN)

#define LED_3_PIO_ID		ID_PIOC
#define LED_3_PIO         PIOC
#define LED_3_PIN		    30
#define LED_3_PIN_MASK    (1 << LED_3_PIN)

#define LED_4_PIO_ID		ID_PIOC
#define LED_4_PIO         PIOC
#define LED_4_PIN		    2
#define LED_4_PIN_MASK    (1 << LED_4_PIN)

/**
 * Botão
 */


#define BUT_1_PIO_ID   ID_PIOD
#define BUT_1_PIO      PIOD
#define BUT_1_PIN      11
#define BUT_1_PIN_MASK (1 << BUT_1_PIN)
#define BUT_1_DEBOUNCING_VALUE  79

#define BUT_2_PIO_ID   ID_PIOD
#define BUT_2_PIO      PIOD
#define BUT_2_PIN      28
#define BUT_2_PIN_MASK (1 << BUT_2_PIN)

#define BUT_3_PIO_ID   ID_PIOC
#define BUT_3_PIO      PIOC
#define BUT_3_PIN      31
#define BUT_3_PIN_MASK (1 << BUT_3_PIN)

#define BUT_4_PIO_ID   ID_PIOA
#define BUT_4_PIO      PIOA
#define BUT_4_PIN      19
#define BUT_4_PIN_MASK (1 << BUT_4_PIN)

/************************************************************************/
/* prototype                                                             */
/************************************************************************/
void led_init(int estado);
void but_init(void);
void but_Handler();

/************************************************************************/
/* Interrupçcões                                                        */
/************************************************************************/

void but_1_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_1_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_PIO, LED_PIN_MASK))
    pio_clear(LED_PIO, LED_PIN_MASK);
   else
    pio_set(LED_PIO,LED_PIN_MASK);
    
}

void but_1_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_1_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_1_PIO, LED_1_PIN_MASK))
    pio_clear(LED_1_PIO, LED_1_PIN_MASK);
   else
    pio_set(LED_1_PIO, LED_1_PIN_MASK);
    
}

void but_1_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_1_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_1_PIO, LED_1_PIN_MASK))
    pio_clear(LED_1_PIO, LED_1_PIN_MASK);
   else
    pio_set(LED_1_PIO, LED_1_PIN_MASK);
    
}

void but_1_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_1_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_1_PIO, LED_1_PIN_MASK))
    pio_clear(LED_1_PIO, LED_1_PIN_MASK);
   else
    pio_set(LED_1_PIO, LED_1_PIN_MASK);
    
}
void butOLED2_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_PIO, LED_PIN_MASK))
    pio_clear(LED_PIO, LED_PIN_MASK);
   else
    pio_set(LED_PIO,LED_PIN_MASK);
    
}

void butOLED3_Handler(){
    /*
     *  limpa interrupcao do PIO
     */
    uint32_t pioIntStatus;
    pioIntStatus =  pio_get_interrupt_status(BUT_PIO);
    
   /**
    *  Toggle status led
    */
   if(pio_get_output_data_status(LED_PIO, LED_PIN_MASK))
    pio_clear(LED_PIO, LED_PIN_MASK);
   else
    pio_set(LED_PIO,LED_PIN_MASK);
    
}

/************************************************************************/
/* Funções	                                                            */
/************************************************************************/

/**
 * @Brief Inicializa o pino do LED
 */
void led_init(int estado){
    pmc_enable_periph_clk(LED_PIO_ID);
    pio_set_output(LED_PIO, LED_PIN_MASK, 1, 0, 0 );
};

/**
 * @Brief Inicializa o pino do BUT
 *  config. botao em modo entrada enquanto 
 *  ativa e configura sua interrupcao.
 */
void but_init(void){
    /* config. pino botao em modo de entrada */
    pmc_enable_periph_clk(BUT_PIO_ID);
    pio_set_input(BUT_PIO, BUT_PIN_MASK, PIO_PULLUP | PIO_DEBOUNCE);
    
    /* config. interrupcao em borda de descida no botao do kit */
    /* indica funcao (but_Handler) a ser chamada quando houver uma interrupção */
    pio_enable_interrupt(BUT_PIO, BUT_PIN_MASK);
    pio_handler_set(BUT_PIO, BUT_PIO_ID, BUT_PIN_MASK, PIO_IT_FALL_EDGE, but_Handler);
    
    /* habilita interrupçcão do PIO que controla o botao */
    /* e configura sua prioridade                        */
    NVIC_EnableIRQ(BUT_PIO_ID);
    NVIC_SetPriority(BUT_PIO_ID, 1);
};



/************************************************************************/
/* Main                                                                 */
/************************************************************************/
int main(void)
{
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
       /* entra em modo sleep */
       //pmc_sleep(SLEEPMGR_SLEEP_WFI);
	};
}


