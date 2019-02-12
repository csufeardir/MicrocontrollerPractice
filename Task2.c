#include <REGX52.H>
unsigned int k=0;
	

void main(void)
	{
		
		
		P3_7 = 0; // ON
		P3_6 = 0; // OFF
		P1_4 = 0; // OFF
		P1_3 = 0; // OFF
		
		TMOD=0x01;
		EA=1;
		ET0=1;
		TL0=0xC0;
		TH0=0x63;
		TR0=1;
		
		while(1){
			
		}
	
	}
	
	void it_timer0(void) interrupt 1{
		
		k++;
			TL0=0xC0;
		TH0=0x63;
		TF0=0;
		
	  if(k==50){
		P2=~P2;
			k=0;
		}
		
}
	

	