/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 75
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char palavra[]="SENHASECRETA";

char subtraima(char c0, char b){
	char a, a0, d, b0;
	if(c0>='A' && c0<='Z'){
		b0= b-'A';
		d=c0-'A';
		if(b0>=d){
			for(a0=0; a0<=25; a0++){
				if(d==(a0+b0)%('Z'-'A'+1)){
					break;
				}
			}
		}
		else{
			a0=d-b0;
		}
		
		a=a0+'A';
		return a;		
	}
	else{
		return c0;
	}
}
int main() {
	int i=0, j=0; 
/* Leitura da entrada */
	fgets(buffer_entrada, TAM_BUFFER, stdin);

//revertendo a cifra
	for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {

		buffer_saida[i] = subtraima(buffer_entrada[i], palavra[j]);
 		j++;
		if (palavra[j]=='\0'){ 
			j=0;
		}
  	}
	
	buffer_saida[i]='\0';
	

/* Escrever saida na tela */
	printf("%s\n", buffer_saida);
	
	return 0;
}
