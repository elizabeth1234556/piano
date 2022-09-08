
#include <configuracionPines.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"

//botones
/*
#define Boton0  0x20

#define Boton1  0x2
#define Boton2  0x4
#define Boton3  0x8
#define Boton4  0x10
#define Boton5  0x20
#define Boton6  0x40
#define Boton7  0x90
*/
void Delay1ms(unsigned long msec); // Delay function
void Nota(int nota, float duracion);
//FRECUENCIAS DE NOTA
#define Do	261
#define Re  293
#define Mi  329
#define Fa  349
#define Sol  392
#define La  440
#define Si  600

//DURACION DE LA NOTA
#define negra .02
#define blanca 3

//PDIR
#define T1 0x80
#define T2 0x08
#define T3 0x10
#define T4 0x20
#define T5 0x40
#define T6 0x400
#define T7 0x800

int cucaracha[] = {
		Do, Do, Do, Fa, La // Do, Do, Do, Fa, La,Fa, Fa, Mi, Mi, Re, Re, Do,Do, Do, Do, Mi, Sol

};
int DuracionNotas[] = {
		blanca, blanca, blanca, blanca // blanca, blanca, blanca, blanca, blanca, blanca,blanca, blanca, blanca, blanca, blanca, blanca, blanca,blanca, blanca, blanca, blanca, blanca

};


//configuracion buzzer

int main(void) {
	int i=0;
/*




	pinMode('C',0, INPUT);
	*/



	pinMode('C',11, INPUT);//2048 -->0x800
	pinMode('C',10, INPUT);//1024 -->0x400
	pinMode('C',6, INPUT);// 64--> 0x40
	pinMode('C',5, INPUT);// 32--> 0x20
	pinMode('C',4, INPUT);// 16--> 0x10
	pinMode('C',3, INPUT);// 8--> 0x08
	pinMode('C',7, INPUT); //128 ---> 0X80
	pinMode('C',0, OUTPUT);//PRUEBA
	//digitalWrite('C',0,ON);

	//BUZER

	//Port Data Input Register en C
	   	int *p2DIR;
	   	p2DIR = (int *)0x400FF090;


	   	while(1){


	   		while(*p2DIR == T1){

	   			for(i=0;i<5;i++){
	   				Nota( cucaracha[i],DuracionNotas[i]);
	   				//Delay1ms(1000);
	   			}
	   	   		//Nota(Do,negra);

	   		}
	   		while(*p2DIR == T2){

	   			Nota(Re,negra);

	   	    }
	   		while(*p2DIR == T3){

	   			Nota(Mi,negra);

	   		}
	   		while(*p2DIR == T4){

	   			Nota(Fa,negra);

	   		}
	   		while(*p2DIR == T5){

	   			Nota(Sol,negra);

	   		}
	   		while(*p2DIR == T6){

	   			Nota(La,negra);

	   		}
	   		while(*p2DIR == T7){

	   			Nota(Si,negra);

	   		}
}




	   		}



//Note Definitions

void Nota(int nota, float duracion)
{
	long int i,cycles;
	float wavelength = 4;

	cycles=nota/wavelength;
	//BUZER
	pinMode('C',2, OUTPUT);

	for (i=0;i<cycles;i++)
	{
		Delay1ms(duracion);
		digitalWrite('C',2,OFF);
		Delay1ms(duracion);
		digitalWrite('C',2,ON);
	}
	return;
}


void Delay1ms(unsigned long msec){
unsigned long i;
  while(msec > 0)
		{
				i = 13333;  // this number means 1ms
				while(i > 0)
				{
					i = i - 1;
				}
				msec = msec - 1; // decrements every 1ms// write this function

		}
}

