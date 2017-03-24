#include <stdio.h>
#include <stdlib.h>

void GeraMatriz(int**p, int** q, int m, int n){
	int i, j;
	/*Tinha declarado os ponteiros dentro da funçao, mas eh melhor
	modularizar o programa, deixando assim esta funçao para apenas
	gerar as matrizes - tabuleiros.
	int p**, q**;*/

	printf("Informe o numero de linhas da matriz para o jogo: \n");
	scanf("%d", &m);
	printf("Informe o numero de colunas da matriz para o jogo: \n");
	scanf("%d", &n);

	p = (int **)malloc(m*sizeof(int *));
	for(i = 0; i < 10; i++){
		p[i] = (int *)malloc(n*sizeof(int));
		for (j = 0; j < 10; j++){
			p[i][j] = 0;
		}
	}

	q = (int **)malloc(m*sizeof(int *));
	for(i = 0; i < 10; i++){
		q[i] = (int *)malloc(n*sizeof(int));
		for (j = 0; j < 10; j++){
			q[i][j] = 0;
		}
	}
}

void Estrategia(int** p, int** q, int m, int n){
	/*A ideia eh percorrer a matriz setando 'blocos', que seriam as
	estruturas componentes dos barcos. 2 blocos em sequencia seriam
	um submarino, 6 um porta-avioes, e assim por diante. Pensei em 
	por uma estrutura com um bloco soh, que seria um 'Portal". Quando
	acertado, o 'Portal' reverteria a jogada, enviando o tiro dado,
	preservando as coordenadas, para a matriz de quem atirou.
	Cada bloco seria um '1' dentro da matriz, que vem 'de fabrica'
	nula. Para identificaçao de qual barco foi acertado, fariamos um
	loop - do-while, por exemplo - que verifica se o elemento ao lado,
	ou em cima, ou baixo, tambem eh um 'bloco'. Colocariamos um contador,
	e com isso saberiamos quantos 'blocos' formam a estrutura, e conse-
	quentemente qual o tipo de barco*/
	int i, j, barco, coordenadax, coordenaday, continua, qtd;


	printf("Montem suas estrategias!\n");
	getchar;
	qtd = 0;
	do{
		printf("De acordo com a seguinte codificaçao:\n");
		printf("Portal - 1, Submarino - 2, Porta-avioes - 3\n");
		printf("Informe qual barco deseja colocar: \n");
		scanf("%d", &barco);
		if (barco == 1){
			printf("Informe, separando por espaços, em quais coordenadas seu Portal estara': \n");
			scanf("%d%d", &coordenadax, &coordenaday);
			p[coordenadax][coordenaday] = 1;
		}
		else{
			if(barco == 2){
				printf("Informe, separando por espaços, qual a 1a coordenada em que seu Submarino estara': \n");
				/*Tambem podemos por Coordenada de referencia, ao inves de 1a coordenada.*/
				scanf("%d%d", &coordenadax, &coordenaday);
				printf("De acordo com a seguinte codificaçao:\n");
				printf("Esquerda - 1, Direita - 2, Acima - 3, Abaixo - 4\n");
				printf("Informe agora onde que seu Submarino continua: \n");
				/*Aqui podemos mudar para: Qual eh a orientaçao do seu Submarino?
				Direita, esquerda, acima, abaixo*/
				scanf("%d", &continua);
				if (continua == 1){
					if (coordenadax == 0){
						printf("Nao existem mais posiçoes `a esquerda!\n");
						printf("Informe outra orientaçao: \n");
						scanf("%d", &continua);
					}else{
					p[coordenadax][coordenaday] = 1;
					p[coordenadax - 1][coordenaday] = 1;
					}
				}
				else{
					if (continua == 2){
						p[coordenadax][coordenaday] = 1;
						p[coordenadax + 1][coordenaday] = 1;
					}
					else{
						if (continua == 3){
							p[coordenadax][coordenaday] = 1;
							p[coordenadax][coordenaday + 1] = 1;
						}
						else{
							p[coordenadax][coordenaday] = 1;
							p[coordenadax][coordenaday - 1] = 1;
						}
					}
				}
			}//fim if Submarino
			else{
				printf("Informe, separando por espaços, qual a 1a coordenada em que seu Porta-avioes estara': \n");
				scanf("%d%d", &coordenadax, &coordenaday);
				printf("De acordo com a seguinte codificaçao:\n");
				printf("Esquerda - 1, Direita - 2, Acima - 3, Abaixo - 4\n");
				printf("Informe agora onde que seu Porta-avioes continua: \n");
				scanf("%d", &continua);
				if (continua == 1){
					p[coordenadax][coordenaday] = 1;
					p[coordenadax - 1][coordenaday] = 1;
					p[coordenadax - 2][coordenaday] = 1;
				}
				else{
					if (continua == 2){
						p[coordenadax][coordenaday] = 1;
						p[coordenadax + 1][coordenaday] = 1;
						p[coordenadax + 2][coordenaday] = 1;
					}
					else{
						if (continua == 3){
							p[coordenadax][coordenaday] = 1;
							p[coordenadax][coordenaday + 1] = 1;
							p[coordenadax][coordenaday + 2] = 1;
						}
						else{
							p[coordenadax][coordenaday] = 1;
							p[coordenadax][coordenaday - 1] = 1;
							p[coordenadax][coordenaday - 2] = 1;
						}
					}
				}
			}//fim else Porta-avioes	
		}//fim else Submarino
	}while(qtd != 6)
	/*Falta definir se as dimensoes das matrizes serao fixas - acho melhor -
	e verificar os potenciais erros no posicionamento dos barcos. Por exemplo,
	se a coordenada de referencia esta na ponta direita da matriz, e o usuario pede
	para que a orientaçao do barco seja para direita, deve-se exibir uma
	mensagem de erro, pois, nao existem mais posiçoes `a direita para 
	serem utilizadas. Tambem eh importante observar a possibilidade de choque
	entre barcos informados - se uma posiçao foi informada, nao pode mais ser
	usada. Rascunho na linha 71. Alem disso, eh preciso definir
	qual a quantidade de barcos que pode ser usada - que por sua vez depende
	novamente das dimensoes da matriz. Se estas forem `a escolha do usuario,
	poderiamos setar modos de jogo: rapido - matrizes 3x3 ou 4x4 -, medio -
	matrizes 6x6 ou 7x7, ou normal - matrizes 10x10 e 12x12. Nos modos rapido
	e medio nao caberiam barcos grandes, somente submarinos e portais, entao
	colocariamos uma condiçao para tanto.*/
}






