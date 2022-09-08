
#include <configuracionPines.h>
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"


void Delay1ms(unsigned long msec);
void Nota(float nota);
void cucaracha();
void cumple();

//FRECUENCIAS DE NOTA


#define Re2  293
#define Do2  329
#define Sol2  369


#define Si  349
#define La  392
#define Sol  440

#define Fa  600
#define Mi  650
#define Re  750
#define Do  1043

/*/DURACION DE LA NOTA
#define negra .5
#define blanca .5
*/

//PDIR
// Musica
#define T1c 0x80
#define T2c 0x100
// teclas
#define T1 0x08
#define T2 0x200
#define T3 0x10
#define T4 0x20
#define T5 0x40
#define T6 0x400
#define T7 0x800
#define T8 0x1000
#define T9 0x2000



int main(void) {


	pinMode('C',13, INPUT);//8192 -->0x2000
	pinMode('C',12, INPUT);//4096 -->0x1000
	pinMode('C',11, INPUT);//2048 -->0x800
	pinMode('C',10, INPUT);//1024 -->0x400
	pinMode('C',9, INPUT);//512 -->0x200
	pinMode('C',8, INPUT);//256 -->0x100

	pinMode('C',6, INPUT);// 64--> 0x40
	pinMode('C',5, INPUT);// 32--> 0x20
	pinMode('C',4, INPUT);// 16--> 0x10
	pinMode('C',3, INPUT);// 8--> 0x08
	pinMode('C',7, INPUT); //128 ---> 0X80




	//digitalWrite('C',0,ON);

	//BUZER

	//Port Data Input Register en C
	   	int *p2DIR;
	   	p2DIR = (int *)0x400FF090;


	   	while(1){
	   		////teclas Canciones
	   		while(*p2DIR == T1c){
	   			cucaracha();

	   		}
	   		while(*p2DIR == T2c){

	   			 cumple();
	   	    }


	   		////teclas Notas
	   		while(*p2DIR == T1){

	   		Nota(Re2);

	   		}
	   		while(*p2DIR == T2){

	   		    Nota(Do2);

	   	    }
	   		while(*p2DIR == T3){

	   			Nota(Si);

	   		}
	   		while(*p2DIR == T4){

	   			Nota(La);

	   		}
	   		while(*p2DIR == T5){

	   			Nota(Sol);

	   		}
	   		while(*p2DIR == T6){

	   			Nota(Fa);

	   		}
	   		while(*p2DIR == T7){

	   			Nota(Mi);

	   		}
	   		while(*p2DIR == T8){

	   		Nota(Re);

	   		}
	   		while(*p2DIR == T9){

	   		Nota(Do);

	   		}
	   	}
}



//Note Definitions

//nota=frecuencia
void Nota(float nota)
{

	long int i,cycles;
	float wavelength = 4;

	cycles=nota/wavelength;

	//BUZER
	pinMode('C',2, OUTPUT);

	for (i=0;i<cycles;i++)
	{

		digitalWrite('C',2,OFF);
		Delay1ms(.5);
		digitalWrite('C',2,ON);
		Delay1ms(.5);
	}


	return;
}

void Delay1ms(unsigned long msec){
unsigned long i;
  while(msec > 0)
		{
				i = 13333;   //1ms
				while(i > 0)
				{
					i = i - 1;
				}
				msec = msec - 1;

		}
}


void cumple(){
	//SOL     SOL   LA   SOL  DO↑ SI
	int i;
	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(La);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Do2);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Si);
	Delay1ms(3);

	//SOL     SOL   LA   SOL  RE↑ DO↑

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(La);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Re2);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Do2);
	Delay1ms(3);

	//SOL  SOL  SOL↑  MI↑  DO↑    SI   LA

	for(i=0;i<200;i++)
	Nota(Re);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Re);
	Delay1ms(1);

	for(i=0;i<300;i++)
	Nota(Re2);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Si);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Fa);
	Delay1ms(1);

	for(i=0;i<400;i++)
	Nota(Mi);
	Delay1ms(3);

		//SOL     SOL   LA   SOL  DO↑ SI

	for(i=0;i<200;i++)
	Nota(Do2);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Do2);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Si);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(La);
	Delay1ms(1);

	for(i=0;i<200;i++)
	Nota(Sol);
	Delay1ms(1);

}

void cucaracha(){
	int i;

					for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<300;i++)
		   			Nota(Fa);
		   			Delay1ms(1);

		   			for(i=0;i<300;i++)
		   			Nota(La);
		   			Delay1ms(1);
		   			//la cucaracha
		   			for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<80;i++)
		   			Nota(Do);
		   			Delay1ms(1);

		   			for(i=0;i<300;i++)
		   			Nota(Fa);
		   			Delay1ms(1);

		   			for(i=0;i<300;i++)
		   			Nota(La);
		   			Delay1ms(1);

		   			//la cucaracha
		   			//FA FA MI MI RE RE DO

		   			for(i=0;i<300;i++)
		   			Nota(Fa);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Fa);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Mi);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Mi);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Re);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Re);
		   			Delay1ms(1);

		   			for(i=0;i<100;i++)
		   			Nota(Do);
		   			Delay1ms(3);
	////
		   							for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<300;i++)
		   				   			Nota(Mi);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<300;i++)
		   				   			Nota(Sol);
		   				   			Delay1ms(1);
		   				   			//la cucaracha
		   				   			for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<80;i++)
		   				   			Nota(Do);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<300;i++)
		   				   			Nota(Mi);
		   				   			Delay1ms(1);

		   				   			for(i=0;i<300;i++)
		   				   			Nota(Sol);
		   				   			Delay1ms(3);
	//
		   				   						for(i=0;i<300;i++)
		   				   			   			Nota(Do2);


		   				   			   			for(i=0;i<200;i++)
		   				   			   			Nota(Re2);

		   				   			   			for(i=0;i<200;i++)
		   				   			   			 Nota(Re2);

		   				   			   			Delay1ms(1);

		   				   			   			for(i=0;i<200;i++)
		   				   			   			Nota(Do2);



		   				   			   			for(i=0;i<200;i++)
		   				   			   			Nota(Si);

		   				   			   			Delay1ms(1);

		   				   			   			for(i=0;i<200;i++)
		   				   			   			Nota(La);


		   				   			   			for(i=0;i<200;i++)
		   				   			   			Nota(Sol);
		   				   			   			Delay1ms(1);

		   				   			   			for(i=0;i<600;i++)
		   				   			   			Nota(Fa);
}

