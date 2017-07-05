
#include <wiringPi.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>
#include <python2.7/Python.h>

#define MAXTIMINGS	85
#define DHT_PIN		7
int dht11_dat[5] = { 0, 0, 0, 0, 0 };

//copilar gcc codigo_pi_principal.c -o codigo_pi_principal -g -Wall -lpython2.7.9 -lm -L/usr/lib/python2.7.9/config
//./codigo_main_principal

void sensor_dht11_dat();

//fUNçãO PARA REALIZAR A LEITURA DA PORTA do sensor de presença PIR
void sensor_PIR(void)
{
//	pinMode(0,INPUT);
//	int i=0;
	
	//Leitura do pino  17, segundo o mapa de pinos da biblioteca wiringpi
//	i=digitalRead (0); //porta 17 do RASPEBERRY PI
		
//	if (i == 1)
//	{
		//Sensor com movimento
		printf("Presença de Movimento detectado\n");
		
		//Acionar a camera;		
		
    		FILE *python;
    
    		Py_Initialize();
    
    		python = fopen("codigo_camera.py", "r");
    		PyRun_SimpleFile(python, "codigo_camera.py");

    		Py_Finalize();


		//Leitura do sensor de temperatura e umidade
		printf( "Dados do local\n" );
		sensor_dht11_dat();
		delay( 1000 ); /* Aguardo 1 segundo */
		

		//Enviar e-mail
		FILE *python;
    
    		Py_Initialize();
    
    		python = fopen("email_principal.py", "r");
    		PyRun_SimpleFile(python, "email_principal.py");

    		Py_Finalize();
		
		
//	}
}

void sensor_dht11_dat()
{
	uint8_t ultimo_estado	= HIGH;
	uint8_t contador		= 0;
	uint8_t j		= 0, i;
	float	f; /* fahrenheit */
 
	dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;
 
	/* Pino de saida depois esperar 18 milliseconds */
	pinMode( DHT_PIN, OUTPUT );
	digitalWrite( DHT_PIN, LOW );
	delay( 18 );
	/* pino alto depois espera 40 microseconds */
	digitalWrite( DHT_PIN, HIGH );
	delayMicroseconds( 40 );
	/* Prepara o pino para entrada */
	 pinMode( DHT_PIN, INPUT );
 
	/* Realizar a leitura */
	for ( i = 0; i < MAXTIMINGS; i++ )
	{
		contador = 0;
		while ( digitalRead( DHT_PIN ) == ultimo_estado )
		{
			contador++;
			delayMicroseconds( 1 );
			if ( contador == 255 )
			{
				break;
			}
		}
		ultimo_estado = digitalRead( DHT_PIN );
 
		if ( contador == 255 )
			break;
 

		if ( (i >= 4) && (i % 2 == 0) )
		{
			dht11_dat[j / 8] <<= 1;
			if ( contador > 16 )
				dht11_dat[j / 8] |= 1;
			j++;
		}
	}
 
	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) &&
	     (dht11_dat[4] == ( (dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF) ) )
	{
		f = dht11_dat[2] * 9. / 5. + 32;
		printf( "Umidade = %d.%d %% Temperatura = %d.%d *C (%.1f *F)\n",
			dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3], f );
	}else  {
		printf( "Sem bons dados\n" );
	}
}


int main(){
	
	printf( "Projeto de Monitoramento residencial - Projeto Embarcados 2017" );
 
	if ( wiringPiSetup() == -1 )
		exit( 1 );
 
	
//	while ( 1 )
//	  {
//		leitura do sensor PIR
//		sensor_PIR();
//		
//	    }
 
	//Realiza a leitura quando o sensor PIR É ACIONADO NA BORDA 
 	wiringPiISR(0,INT_EDGE_RISING, sensor_PIR);

 	//pthread_exit(NULL);
 	return 0;

}
