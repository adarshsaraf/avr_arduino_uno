#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

ISR(TIMER1_COMPA_vect) {
	PORTB ^= (1<<PORTB5);
}

int main(){

	//set PortB
	DDRB |= (1 << DDB5);
	
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	
	// Set compare match register for 1Hz increments
  	// Clock speed is 16 MHz, prescaler is 256
  	// Formula: (16*10^6) / (256 * 1) - 1 = 62499
  	OCR1A = 7812;
  	
  	TCCR1B |= ( 1 << WGM12);
  	
  	
  	TIMSK1 |= (1 << OCIE1A);
  	
  	TCCR1B |= (1 << CS10);
  	TCCR1B |= (1 << CS12);
  	
  	sei();
	
	while (1) {
		
	}
}
		
