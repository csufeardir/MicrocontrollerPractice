#include <REGX52.H>

void wait(void){
	unsigned int i;
	for (i=0;i<10000;i++);
}

void main(void)
	{
		unsigned int k;
		P3_7 = 0; // ON
		P3_6 = 0; // OFF
		P1_4 = 0; // OFF
		P1_3 = 0; // OFF
		while(1)
			{
				P2 = ~P2;

for (k=0; k<40; k++){
	wait();
	
}	
			
				
			}
		
}

