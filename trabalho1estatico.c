#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int valor;
	int ocupado;	
}BN;

void GeraMatriz(BN mat[][10]){
	int i, j;

	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			mat[i][j].valor = 0;
			mat[i][j].ocupado = 0;
		}
	}
}

void Randomizar(BN mat[][10]){
	int i;
	int sementei, sementej, direcao;

	srand(time(NULL));
	sementei = rand() % 10;
	/*Semente seria um valor aleatorio para uma coordenada x, que
	posteriormente serah preenchido por uma embarcaçao que tambem
	serah sorteada, com a variavel barco. Gerando uma coordenada
	aleatoria, a variavel direçao, tambem gerada aleatoriamente, 
	seria o parametro usado para dizer onde estah o resto da embar-
	caçao. EXEMPLO: semente i sorteia 9, semente j sorteia 5. O 
	ponto (9, 5) foi selecionado como referencia. barco sorteia 2,
	que significa submarino - 1 portal, 2 sub, 3 encouraçado e 
	4 porta-avioes. direcao sorteia 2, que significa que a outra parte
	do barco, no caso um sub, ficaria `a direita da coordenada
	de referencia, ou seja, ficaria no ponto (10, 5). Colocar testes
	para nao estourar a matriz - posicionar algo que nao caiba em
	determinado ponto da matriz com determinada direçao - alem de verificar
	se tal ponto jah estah ocupado, fazendo uso do parametro da
	struct.*/

	sementej = rand() % (10);
	/*Vale lembrar que, no caso de cada coordenada, os limites dos
	valores sorteados sao dados pelas dimensoes da matriz gerada.*/

	direcao = rand() % 4;
	/*0 - esquerda, 1 - direita, 2 - acima, 3 - abaixo.*/

	for(i=0;i<4;i++){
		if(mat[sementei][sementej].ocupado == 1){
			sementei = rand() % 10;
			sementej = rand() % 10;
		}
		else{
			mat[sementei][sementej].valor = 1;
			mat[sementei][sementej].ocupado = 1;
		}
	}
	/*Esse teste serah recorrente no codigo. A ideia eh verificar
	a condiçao da coordenada sorteada: se estiver ocupada, sorteia-se
	outra. Em caso contrario, atribui-se o valor do barco correspondente
	e modifica-se o parametro 'ocupado' da struct. Para cada direçao
	diferente, a condiçao do teste 'if' serah adaptada.*/

	for(i=0;i<3;i++){
		if(mat[sementei][sementej].ocupado == 1){
			sementei = rand() % 10;
			sementej = rand() % 10;
		}
		else{
			mat[sementei][sementej].valor = 2;
			mat[sementei][sementej].ocupado = 1;
		}
		/*fim sub setado coord. de referencia*/
		if(direcao == 0){
			if(sementej-1 < 0){
				direcao = rand() % 4;
			}
			else{
				if(mat[sementei - 1][sementej].ocupado == 1){
					sementei = rand() % 10;
					sementej = rand() % 10;
				}
				else{
					mat[sementei - 1][sementej].valor = 2;
					mat[sementei - 1][sementej].ocupado = 1;
				}
			}
		}/*fim sub setado direçao esquerda*/
		else{
			if(direcao == 1){
				if(sementej + 1 > 10){
					direcao = rand() % 4;
				}
				else{
					if(mat[sementei][sementej+1].ocupado == 1){
						sementei = rand() % 10;
						sementej = rand() % 10;
					}
					else{
						mat[sementei][sementej+1].valor = 2;
						mat[sementei][sementej+1].ocupado = 1;
					}
				}
			}/*fim sub setado direçao direita*/
			else{
				if(direcao == 2){
					if(sementei - 1 < 0){
						direcao = rand() % 4;
					}
					else{
						if(mat[sementei-1][sementej].ocupado == 1){
							sementei = rand() % 10;
							sementej = rand() % 10;
						}
						else{
							mat[sementei-1][sementej].valor = 2;
							mat[sementei-1][sementej].ocupado = 1;
						}
					}
				}/*fim setado direçao acima*/
				else{
					if(sementei + 1 > 10){
						direcao = rand() % 4;
					}
					else{
						if(mat[sementei+1][sementej].ocupado == 1){
							sementei = rand() % 10;
							sementej = rand() % 10;
						}
						else{
							mat[sementei+1][sementej].valor = 2;
							mat[sementei+1][sementej].ocupado = 1;
						}
					}
				}/*fim sub setado direçao abaixo*/
			}
		}
	}/*fim condiçoes sub*/
	for(i=0;i<3;i++){
		if(mat[sementei][sementej].ocupado == 1){
			sementei = rand() % 10;
			sementej = rand() % 10;
		}
		else{
			switch(direcao){
				case 0:
					if(sementej - 2 < 0){
						break;
					}
					else{
						if(mat[sementei][sementej-1].ocupado == 1 || mat[sementei][sementej-2].ocupado == 1){
							/*No teste acima, se todas as coordenadas adjacentes necessarias
							para o posicionamento do barco estiverem ocupadas, sorteia-se uma
							nova coordenada de referencia.*/	
							sementei = rand() % 4;
							sementej = rand() % 4;
							break;
						}
						else{
							mat[sementei][sementej].valor = 3;
							mat[sementei][sementej-1].valor = 3;
							mat[sementei][sementej-2].valor = 3;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei][sementej-1].ocupado = 1;
							mat[sementei][sementej-2].ocupado = 1;
							break;
						}
					}/*fim encouraçado setado esquerda*/
				case 1:
					if(sementej + 2 > 10){
						break;
					}
					else{
						if(mat[sementei][sementej+1].ocupado == 1 || mat[sementei][sementej+2].ocupado == 1){
							sementei = rand() % 4;
							sementej = rand() % 4;
							break;
						}
						else{
							mat[sementei][sementej].valor = 3;
							mat[sementei][sementej+1].valor = 3;
							mat[sementei][sementej+2].valor = 3;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei][sementej+1].ocupado = 1;
							mat[sementei][sementej+2].ocupado = 1;
							break;
						}
					}/*fim encouraçado setado direita*/
				case 2:
					if(sementei - 2 < 0){
						break;
					}
					else{
						if(mat[sementei-1][sementej].ocupado == 1 || mat[sementei-2][sementej].ocupado == 1){
							sementei = rand() % 4;
							sementej = rand() % 4;
							break;
						}
						else{
							mat[sementei][sementej].valor = 3;
							mat[sementei-1][sementej].valor = 3;
							mat[sementei-2][sementej].valor = 3;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei-1][sementej].ocupado = 1;
							mat[sementei-2][sementej].ocupado = 1;
							break;
						}
					}/* fim encouraçado setado acima*/
				case 3:
					if(sementei + 2 > 10){
						break;
					}
					else{
						if(mat[sementei+1][sementej].ocupado == 1 || mat[sementei+2][sementej].ocupado == 1){
							sementei = rand() % 4;
							sementej = rand() % 4;
							break;
						}
						else{
							mat[sementei][sementej].valor = 3;
							mat[sementei+1][sementej].valor = 3;
							mat[sementei+2][sementej].valor = 3;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei+1][sementej].ocupado = 1;
							mat[sementei+2][sementej].ocupado = 1;
							break;
						}
					}/*fim encouraçado setado abaixo*/
			} /*Aqui estah estabelecida a condiçao para o nao estouro das
				dimensoes da matriz, bem como a disponibilidade - ocupado ou
				nao - de cada elemento da matriz. Foi feito um switch, que 
				economiza espaço e eh mais legivel do que uma cadeia de if's
				e else's. Primeiro testa-se a coord. de referencia. Se estiver
				ocupada, sorteia-se uma nova. Caso contrario, em pelo menos uma
				das direçoes validas, as coordenadas adjacentes devem estar
				vazias para o que barco possa ser posicionado.*/

		}
	}/*fim condiçoes encouraçado.*/
	for(i=0;i<2;i++){
		if(mat[sementei][sementej].ocupado == 1){
			sementei = rand() % 10;
			sementej = rand() % 10;
		}
		else{
			switch(direcao){
				case 0:
					if(sementej - 3 < 0){
						break;
					}
					else{
						if(mat[sementei][sementej-1].ocupado == 1 || mat[sementei][sementej-2].ocupado == 1 || mat[sementei][sementej-3].ocupado ==1){
							sementei = rand() % 10;
							sementej = rand() % 10;
							break;
						}
						else{
							mat[sementei][sementej].valor = 4;
							mat[sementei][sementej-1].valor = 4;
							mat[sementei][sementej-2].valor = 4;
							mat[sementei][sementej-3].valor = 4;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei][sementej-1].ocupado = 1;
							mat[sementei][sementej-2].ocupado = 1;
							mat[sementei][sementej-3].ocupado = 1;
							break;
						}
					}/*fim porta-avioes setado esquerda*/
				case 1:
					if(sementej + 3 > 10){
						break;
					}
					else{
						if(mat[sementei][sementej+1].ocupado == 1 || mat[sementei][sementej+2].ocupado == 1 || mat[sementei][sementej+3].ocupado == 1){
							sementei = rand() % 10;
							sementej = rand() % 10;
							break;
						}
						else{
							mat[sementei][sementej].valor = 4;
							mat[sementei][sementej+1].valor = 4;
							mat[sementei][sementej+2].valor = 4;
							mat[sementei][sementej+3].valor = 4;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei][sementej+1].ocupado = 1;
							mat[sementei][sementej+2].ocupado = 1;
							mat[sementei][sementej+3].ocupado = 1;
							break;
						}
					}/*fim porta-avioes setado direita*/
				case 2:
					if(sementei - 3 < 0){
						break;
					}
					else{
						if(mat[sementei-1][sementej].ocupado == 1 || mat[sementei-2][sementej].ocupado == 1 || mat[sementei-3][sementej].ocupado == 1){
							sementei = rand() % 10;
							sementej = rand() % 10;
							break;
						}
						else{
							mat[sementei][sementej].valor = 4;
							mat[sementei-1][sementej].valor = 4;
							mat[sementei-2][sementej].valor = 4;
							mat[sementei-3][sementej].valor = 4;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei-1][sementej].ocupado = 1;
							mat[sementei-2][sementej].ocupado = 1;
							mat[sementei-3][sementej].ocupado = 1;
							break;
						}
					}/* fim porta-avioes setado acima*/
				case 3:
					if(sementei + 3 > 10){
						break;
					}
					else{
						if(mat[sementei+1][sementej].ocupado == 1 || mat[sementei+2][sementej].ocupado == 1 || mat[sementei+3][sementej].ocupado == 1){
							sementei = rand() % 10;
							sementej = rand() % 10;
							break;
						}
						else{
							mat[sementei][sementej].valor = 4;
							mat[sementei+1][sementej].valor = 4;
							mat[sementei+2][sementej].valor = 4;
							mat[sementei+3][sementej].valor = 4;
							mat[sementei][sementej].ocupado = 1;
							mat[sementei+1][sementej].ocupado = 1;
							mat[sementei+2][sementej].ocupado = 1;
							mat[sementei+3][sementej].ocupado = 1;
							break;
						}
					}/*fim porta-avioes setado abaixo*/
			}
		}
	}/*fim condiçoes porta-avioes*/	
			
}

void Pipoco(int* x, int* y){
	
	printf("Informe a coordenada x na qual deseja atirar: \n");
	scanf("%d", x);
	printf("Informe a coordenada y na qual deseja atirar: \n");
	scanf("%d", y);
}

void PearlHarbor(BN mat[][10], int x, int y){
	int contportal, contsub, contenc, contpv, contagua;

	contportal = 0;
	contsub = 0;
	contenc = 0;
	contpv = 0;
	contagua = 0;

	printf("Shhhhhhhhhhhhhhiiiiiuuu...\n");
	getchar();
	if(mat[x][y].valor == 0){
		printf("Flop. Voce acertou! Em um peixe.\n");
		contagua++;
	}
	else{
		if(mat[x][y].valor == 1){
			printf("Voce acertou em algo...\n");
			getchar();
			printf("Mas.. como?! O que aconteceu!\n");
			printf("Me parece ser um.. Portal!\n");
			printf("E pra onde foi o tiro?\n");
			contportal++;
			/*Aqui endereçariamos as coordenadas para a outra matriz,
			e contariamos o acerto no proprio taabuleiro de quem
			efetuou o disparo*/
		}
		else{
			if(mat[x][y].valor == 2){
				printf("O tiro entrou na agua!\n");
				getchar();
				printf("Espere, ouvi uma explosao!\n");
				printf("Voce acertou um submarino!\n");
				contsub++;
			}
			else{
				if(mat[x][y].valor == 3){
					printf("CABUM! Voce acertou em um encouraçado!\n");
					contenc++;
				}
				else{
					printf("POW! Voce acertou em um aviao!\n");
					getchar();
					printf("Quer dizer, em um porta-avioes!\n");
					contpv++;
				}
			}
		}
	}
} 

int main(){
	int i, j, x, y;
	BN mat[10][10];

	GeraMatriz(mat);
	Randomizar(mat);

	printf("Sua matriz eh:\n");
	for (i = 0; i < 10; ++i){
		for (j = 0; j < 10; ++j){
			printf("%d\t", mat[i][j].valor);
		}
		printf("\n");
	}

	Pipoco(&x, &y);
	PearlHarbor(mat, (x-1), (y-1));
	\*As variáveis x e y recebem as coordenadas do tiro. As pessoas, em
	geral, informam numeros de 1 a 10, enquanto a matriz é indexada de 0 a 9.
	Por isso, x-1 e y-1*\

	return 0;
}
