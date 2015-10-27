/* 
* Título: Medida do nível de iluminação utilizando o sensor LDR
* Autor: Charles Cardoso de Oliveira
* Descrição: A medida que o nível de iluminação aumenta, diminui o valor lido na entrada analógica A0.
* Os valores lidos são mostrados no monitor via interface serial e devem ser utilizados para calibrar os valores LIMIARX de acordo com o local.
* A quantidade de led's ligados é controlada pelos condicionais.
*/

#define LIMIAR1 1020
#define LIMIAR2 1010
#define LIMIAR3 1000

#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5

int valorAnalogico;

void setup(){
    Serial.begin(9600); /* Inicia o modo serial para debug */
	
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
}

void loop(){
	valorAnalogico = analogRead(A0);
	Serial.println(valorAnalogico); /* Imprime no monitor o valor lido em A0 (deve ser utilizado para calibrar os valores LIMIAR) */
	
	if(valorAnalogico > LIMIAR1){
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, LOW);
		digitalWrite(LED3, LOW);
		digitalWrite(LED4, LOW);
	}
  
	if(valorAnalogico > LIMIAR2 && valorAnalogico <= LIMIAR1){
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, LOW);
		digitalWrite(LED4, LOW);
	}
  
	if(valorAnalogico > LIMIAR3 && valorAnalogico <= LIMIAR2){
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
		digitalWrite(LED4, LOW);
	}
  
	if(valorAnalogico <= LIMIAR3){
		digitalWrite(LED1, HIGH);
		digitalWrite(LED2, HIGH);
		digitalWrite(LED3, HIGH);
		digitalWrite(LED4, HIGH);
	}
}
