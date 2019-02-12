#include <REGX52.H>
unsigned int k=0;
unsigned int Port2 = 0x1;
unsigned int a=1;
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
			
			if (P1_0 == 0 && P1_1 == 1 && P1_2 == 1){
				a=50;
			}
			
			if (P1_0 == 1 && P1_1 == 0 && P1_2 == 1){
				a=5;
			}
			
			if (P1_0 == 1 && P1_1 == 1 && P1_2 == 0){
				a=1;
			}
			
		}
	
	}
	
	void it_timer0(void) interrupt 1{
		
		k++;
			TL0=0xC0;
		TH0=0x63;
		TF0=0;
		if(k>a){
		k=0;
		}
		
	  if(k==a){
			Port2=Port2<<1;
			P2=~Port2;
			
			if(Port2==0x100){
				
				while(Port2!=0x01){
						
					Port2=Port2>>1;
					P2=~Port2;
				}
			
		
		}
			
			k=0;
}
		}