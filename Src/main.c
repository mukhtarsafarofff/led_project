#define PERIPH_BASE (0x40000000UL)

#define AHB1PERIPH_OFFSET (0x00020000UL)

#define AHB1PERIPH_BASE  (PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOA_OFFSET (0x0000UL)

#define GPIOA_BASE (AHB1PERIPH_BASE + GPIOA_OFFSET)

#define RCC_OFFSET (0X3800UL)

#define RCC_BASE (AHB1PERIPH_BASE + RCC_OFFSET)



#define AHB1EN_R_OFFSET (0x30UL)

#define RCC_AHB1EN_R (*(volatile unsigned int*)(RCC_BASE + AHB1EN_R_OFFSET))


#define GPIOAEN     (1U<<0)       //1i burda 0ci pozisiyaya shift edirik yani 0b 0000 0000 0000 0000 0000 0000 0000 0001

#define MODE_R_OFFSET (0X00UL)  //direction-u bildiren mode registerin reference manualdaki address offset yazisinda 0x00 yazildigi uchun bunu offset kimi define eledik

#define GPIOA_MODE_R   (*(volatile unsigned int*)( GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET (0x14UL)

#define GPIOA_OD_R (*(volatile unsigned int*)(GPIOA_BASE + OD_R_OFFSET))

// (1U<<10)  // burda 10cu biti 1 edirik, shift positioning ile
// &=~(1U<<11) // burda 11ci biti 0 edirik, yene shift positioning ile, ~ inverslemeni bildirir
#define PIN5 (1U<<5)
#define LED_PIN PIN5
int main (void) {
	//1.enable clock access to GPIOA
	RCC_AHB1EN_R  |= GPIOAEN;
	GPIOA_MODE_R  |= (1U<<10); // burda 10cu biti 1 edirik, shift positioning ile
	GPIOA_MODE_R  &=~(1U<<11); // burda 11ci biti 0 edirik, yene shift positioning ile, ~ inverslemeni bildirir
	while(1){
		//GPIOA_OD_R |= LED_PIN; //data registerde LED_ppin adli pinin output kimi high veya low olmasini data ile bu registere yazdiq
		GPIOA_OD_R ^= LED_PIN;//bu toggle operatorudur
		for(int i=0;i<10000;i++){}
	}
}
