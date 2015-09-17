void zigzag (byte *matriz, boolean acender, boolean luz){
	/*	Inicializacao das variaveis de controle */
	linha = coluna = 0;
	direcao = LOW;
	if (acender == HIGH)
		zera (matriz);
	
	/*	Varredura de toda a matriz */
	for (indice = 0; indice < pow(tamanho, 2); indice++){
		/*	Caso esteja acendendo os LEDS */
		if (acender == HIGH){
			bitSet (matriz[linha], coluna);
			envia (matriz);
			if (luz == LOW)
				bitClear (matriz[linha], coluna);

		/*	Caso contrario */		
		}else{
			bitClear (matriz[linha], coluna);
			envia (matriz);
		}

		/*	Vindo pela direita */
		if (direcao == LOW){
			if (linha == 0){  
				coluna++;
				direcao = HIGH;
			}else if (coluna == (tamanho - 1)){
				linha++;
				direcao = HIGH;
			}else{
				coluna++;
				linha--;
			}
		/*	Vindo pela esquerda */
		}else{
			if (coluna == 0){
				linha++;
				if (linha == tamanho){
			  		linha = tamanho - 1;
					coluna++;
				}
				direcao = LOW;
			}else if (linha == (tamanho - 1)){
				coluna++;
				direcao = LOW;
			}else{
				linha++;
				coluna--;
			}
		}  
	}
}
