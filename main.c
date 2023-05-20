// Introduction to TM4C123 Tiva C Series LaunchPad
// https://microcontrollerslab.com/introduction-tiva-tm4c123g-launchpad/

// How to download and install Keil uVision for ARM and 8051
// https://microcontrollerslab.com/download-install-keil-uvision/

// Getting started with Keil uVision: Write your first Program for Tiva LaunchPad
// https://microcontrollerslab.com/keil-uvision-first-program/

// How to use GPIO pins of TM4C123G Tiva launchPad
// https://microcontrollerslab.com/use-gpio-pins-tm4c123g-tiva-launchpad/

#define SYSCTL_RCGCGPIO_R (*(( volatile unsigned long *)0x400FE608 ) )
#define GPIO_PORTF_DATA_R (*(( volatile unsigned long *)0x40025038 ) ) 
#define GPIO_PORTF_DIR_R  (*(( volatile unsigned long *)0x40025400 ) ) 
#define GPIO_PORTF_DEN_R  (*(( volatile unsigned long *)0x4002551C ) )

#define GPIO_PORTF_CLK_EN  0x20
#define GPIO_PORTF_PIN1_EN 0x02
#define LED_ON1 	   0x02
#define GPIO_PORTF_PIN2_EN 0x04
#define LED_ON2		   0x04
#define GPIO_PORTF_PIN3_EN 0x08
#define LED_ON3 	   0x08

#define DELAY_VALUE							1000000

static void Delay(void){
	for (unsigned long j=0; j<DELAY_VALUE ; j++);
}

int main ( void )
{
SYSCTL_RCGCGPIO_R |= GPIO_PORTF_CLK_EN ;
GPIO_PORTF_DIR_R |= GPIO_PORTF_PIN1_EN ;
GPIO_PORTF_DEN_R |= GPIO_PORTF_PIN1_EN ;	
GPIO_PORTF_DIR_R |= GPIO_PORTF_PIN2_EN ;
GPIO_PORTF_DEN_R |= GPIO_PORTF_PIN2_EN ;
GPIO_PORTF_DIR_R |= GPIO_PORTF_PIN3_EN ;
GPIO_PORTF_DEN_R |= GPIO_PORTF_PIN3_EN ;
		
// Loop forever . 
		while (1) 
		{  
			GPIO_PORTF_DATA_R &= LED_ON3;
			GPIO_PORTF_DATA_R &= LED_ON2;
			GPIO_PORTF_DATA_R |= LED_ON1;
			Delay();
			GPIO_PORTF_DATA_R &= LED_ON1;
			GPIO_PORTF_DATA_R &= LED_ON2;
			GPIO_PORTF_DATA_R |= LED_ON3;	
			Delay();
			GPIO_PORTF_DATA_R &= LED_ON3;
			GPIO_PORTF_DATA_R &= LED_ON1;
			GPIO_PORTF_DATA_R |= LED_ON2;
			Delay();
				
		}
}
