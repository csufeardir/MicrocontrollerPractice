#include <REGX52.H>
unsigned int PortDisplay=0xE1;
unsigned int PortDisplay2=0xD2;
unsigned int PortDisplay3=0xB3;
unsigned int PortDisplay4=0x74;

char a = 4;
char b = 3;
char c = 2;
char d = 1;
char pos = 0;

unsigned int k=0;
unsigned int Display = 0x1;
void main(void)
	{
		
		
		P3_7 = 1; // OFF
		P3_6 = 1; // ON
		P1_4 = 0; // OFF
		P1_3 = 0; // OFF
		
		
		TMOD=0x01;
		EA=1;
		ET0=1;
		TL0=0x78;
		TH0=0xEC;
		TR0=1;
		
		while(1){
			
			
		}
	
	}
	
	void it_timer0(void) interrupt 1{
		
		k++;
			TL0=0x78;
		TH0=0xEC;
		TF0=0;
		P2=~P2;
		
		switch(pos){
			case 0:
				P2=P0/1000;
				pos=1;
			  break;
			
			case 1:
				P2=P0/100;
			  pos=2;
			  break;
			
			case 2:
				P2=P0/10;
			  pos=3;
			  break;
			  
			case 3:
				P2=P0;
				pos=0;
			  break;
		}
		
		

	}
	