#include<REGX52.H>
int i;
int x;
char a=4;
char b=3;
char c=2;
char d=0;
int value;
char position=0;
int count=0;


void main (void){


P3_6=1;
P3_7=0;
P1_3=0;
P1_4=1;

x=0x01;
TMOD=0x01;
EA=1;
ET0= 1;
TL0= 0x78;  //highest value - 5000=EC78
TH0=0xEC ;
TR0=1;


while(1) {
 

}
}


void it_timer0 (void) interrupt 1 {


        TL0= 0x78;
    TH0=0xEC;
        TF0=0;
i++; 
        P2 = ~P2;

if(i==40) {
count++;
value=count;
d=(value/1000);
c= (value/100)%10;
  
  b=(value/10)%10;
  a=value%10;
i=0;
if(count==10000){
i=0;
}


}
switch(position){
        case 0: 
P2=0x70 | (a & 0x0F); // ONES
          position=1;
break;

        case 1:
                P2=0xB0 | (b & 0x0F); // TENS
          position=2;
                break;

        case 2:
                P2=0xD0 | (c & 0x0F); // Hundreds
          position=3;
                break;

        case 3:
                P2=0xE0 | (d & 0x0F); // Thouands
          position=0;
                break;

}
}