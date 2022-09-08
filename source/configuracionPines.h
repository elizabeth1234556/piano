/*
 * configuracion.h
 *
 *  Created on: 10 ago. 2021
 *      Author: user
 */

#ifndef CONFIGURACIONPINES_H_
#define CONFIGURACIONPINES_H_

#define OUTPUT 1
#define INPUT 0
#define ON 1
#define OFF 0

	void pinMode(unsigned char puerto, int bit, unsigned char mode);
	void digitalWrite(unsigned char puerto, int bit, unsigned char data);

#endif /* CONFIGURACIONPINES_H_ */
