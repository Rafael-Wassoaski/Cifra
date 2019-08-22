#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void tabela(char campo[26][26]) {

	char alfabeto [26] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' , 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}	;
int j, x, z;




	for(int i = 0; i < 26; i++, z++){
		z=i;
		for( j = 0, x=0; j < 27; j++, x++){


			if(x+z >=26){
				x=z=0;
			}
			
			campo[i][j] = alfabeto[x+z];


			

		}
		
	}



};


void codificar(char campo[26][26], char chave[100], char palavra [100]){
int linha, coluna;
for(int i =0 ; i< strlen(palavra); i++){



	for(int j = 0; j<26; j++){
		if(campo[0][j] == palavra[i]){
			coluna = j;
			break;
		}
	}

for(int x =0; x< 26; x++){
	
				if(campo[x][0] == chave[i]){
					
					linha = x;
					
					 break;
				}
			}


			printf("%c", campo[linha][coluna]);
}




}



void main(int argc, char const *argv[])
{
	char palavra[100];


	printf("Digite a palavra a ser criptografada (com até 100 caracteres): ");
	scanf("%s", palavra);

	char chave [100];
	char tabuleiro[26][26];


	while(1){
		printf("\n\nDigite a palavra a palavra chave (com o mesmo número de caracteres que a palavra anterior): ");
		scanf("%s", chave);

		if(strlen(palavra) == strlen(chave)){
			break;
		}
		printf("\n\nA chave não possui o mesmo tamanho da palavra a ser criptografada\n\n");
	}

	for(int i = 0; i < strlen(palavra); i ++){
		palavra[i] = tolower(palavra[i]);
		chave[i] = tolower(chave[i]);

	}

	printf("%ld\n", strlen(palavra));
	tabela(tabuleiro);
	codificar(tabuleiro, chave, palavra);


}