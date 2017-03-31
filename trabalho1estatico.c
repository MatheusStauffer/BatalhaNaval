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
	int blocupados;
	int sementei, sementej, barco, direcao;

	srand(time(NULL));
	sementei = rand() % 11;
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

	sementej = rand() % (11);
	/*Vale lembrar que, no caso de cada coordenada, os limites dos
	valores sorteados sao dados pelas dimensoes da matriz gerada.*/

	barco = rand() % 5;
	/*0 - agua, 1 - portal, ponteiro que joga o tiro dado no adversario
	no proprio tabuleiro de quam atirou, 2 - sub, 3 - encouraçado,
	4 - porta-avioes.*/

	direcao = rand() % 4;
	/*0 - esquerda, 1 - direita, 2 - acima, 3 - abaixo.*/

	blocupados = 0;

	do{
		if (barco == 1){
			if(mat[sementei][sementej].ocupado == 1){
				sementei = rand() % 11;
				sementej = rand() % 11;
			}
			else{
				mat[sementei][sementej].valor = 1;
				mat[sementei][sementej].ocupado = 1;
				blocupados++;
			}
			/*Esse teste serah recorrente no codigo. A ideia eh verificar
			a condiçao da coordenada sorteada: se estiver ocupada, sorteia-se
			outra. Em caso contrario, atribui-se o valor do barco correspondente
			e modifica-se o parametro 'ocupado' da struct. Para cada direçao
			diferente, a condiçao do teste 'if' serah adaptada.*/
		}
		else{
			if(barco == 2){
				if(mat[sementei][sementej].ocupado == 1){
					sementei = rand() % 11;
					sementej = rand() % 11;
				}
				else{
				mat[sementei][sementej].valor = 2;
				mat[sementei][sementej].ocupado = 1;
				blocupados++;
				}
				/*fim sub setado coord. de referencia*/
				if(direcao == 0){
					if(sementej-1 < 0){
						direcao = rand() % 4;
					}
					else{
						if(mat[sementei - 1][sementej].ocupado == 1){
						sementei = rand() % 11;
						sementej = rand() % 11;
						}
						else{
							mat[sementei - 1][sementej].valor = 2;
							mat[sementei - 1][sementej].ocupado = 1;
							blocupados++;
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
								sementei = rand() % 11;
								sementej = rand() % 11;
							}
							else{
								mat[sementei][sementej+1].valor = 2;
								mat[sementei][sementej+1].ocupado = 1;
								blocupados++;
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
									sementei = rand() % 11;
									sementej = rand() % 11;
								}
								else{
									mat[sementei-1][sementej].valor = 2;
									mat[sementei-1][sementej].ocupado = 1;
									blocupados++;
								}
							}
						}/*fim setado direçao acima*/
						else{
							if(sementei + 1 > 10){
								direcao = rand() % 4;
							}
							else{
								if(mat[sementei+1][sementej].ocupado == 1){
									sementei = rand() % 11;
									sementej = rand() % 11;
								}
								else{
									mat[sementei+1][sementej].valor = 2;
									mat[sementei+1][sementej].ocupado = 1;
									blocupados++;
								}
							}
						}/*fim sub setado direçao abaixo*/
					}
				}

			}/*fim condiçoes sub*/
			else{
				if(barco == 3){
					if(mat[sementei][sementej].ocupado == 1){
						sementei = rand() % 11;
						sementej = rand() % 11;
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
										blocupados = blocupados + 3;
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
										blocupados = blocupados + 3;
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
										blocupados = blocupados + 3;
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
										blocupados = blocupados + 3;
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
				else{
					if(mat[sementei][sementej].ocupado == 1){
						sementei = rand() % 11;
						sementej = rand() % 11;
					}
					else{
						switch(direcao){
							case 0:
								if(sementej - 3 < 0){
									break;
								}
								else{
									if(mat[sementei][sementej-1].ocupado == 1 || mat[sementei][sementej-2].ocupado == 1 || mat[sementei][sementej-3].ocupado ==1){
										sementei = rand() % 11;
										sementej = rand() % 11;
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
										blocupados = blocupados + 4;
										break;
									}
								}/*fim porta-avioes setado esquerda*/
							case 1:
								if(sementej + 3 > 10){
									break;
								}
								else{
									if(mat[sementei][sementej+1].ocupado == 1 || mat[sementei][sementej+2].ocupado == 1 || mat[sementei][sementej+3].ocupado == 1){
										sementei = rand() % 11;
										sementej = rand() % 11;
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
										blocupados = blocupados + 4;
										break;
									}
								}/*fim porta-avioes setado direita*/
							case 2:
								if(sementei - 3 < 0){
									break;
								}
								else{
									if(mat[sementei-1][sementej].ocupado == 1 || mat[sementei-2][sementej].ocupado == 1 || mat[sementei-3][sementej].ocupado == 1){
										sementei = rand() % 11;
										sementej = rand() % 11;
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
										blocupados = blocupados + 4;
										break;
									}
								}/* fim porta-avioes setado acima*/
							case 3:
								if(sementei + 3 > 10){
									break;
								}
								else{
									if(mat[sementei+1][sementej].ocupado == 1 || mat[sementei+2][sementej].ocupado == 1 || mat[sementei+3][sementej].ocupado == 1){
										sementei = rand() % 11;
										sementej = rand() % 11;
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
										blocupados = blocupados + 4;
										break;
									}
								}/*fim porta-avioes setado abaixo*/
						}
					}
				}/*fim condiçoes porta-avioes*/
			}
		}
	}while(blocupados<=45);
	
	
}

int main(){
	int i, j;
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
	return 0;
}