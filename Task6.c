#include <REGX52.H>
unsigned int PortDisplay=0xE1;
unsigned int PortDisplay2=0xD2;
unsigned int PortDisplay3=0xB3;
unsigned int PortDisplay4=0x74;
int PortDisp;
char a = 4;
char b = 3;
char c = 2;
char d = 1;
char pos = 0;
unsigned int k=0;
unsigned int Display = 0x1;
void main(void)
	{
		P3_7 = 0; 
		P3_6 = 1; 
		P1_4 = 1; 
		P1_3 = 1;
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
		PortDisp = P0;
		a=PortDisp/10;
		b=(PortDisp/10)%10;
		c=PortDisp%10;
		d=PortDisp;
		switch(pos){
			case 0:
				P2= 0x70 | (c&0x0F);
				pos=1;
			  break;
			case 1:
				P2= 0xB0 | (b&0x0F);
			  pos=2;
			  break;
			case 2:
				P2= 0xD0 | (a&0x0F);
			  pos=3;
			  break;
			case 3:
				P2= 0xE0 | (d&0x0F);
				pos=0;
			  break;
		}
	}