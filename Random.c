#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int valor;
	int ocupado;	
} BN;

/*A ideia inicial eh fazer dinamicamente uma matriz do tipo BN.
A struct BN tem os parametros valor - que diz qual o tipo de embarcaçao
que determinado elemento da matriz possui -, e ocupado - que diz respeito
se tal elemento da matriz estah ou nao ocupado por algum pedaço de embar-
caçao. Isso facilitaria o retorno de informaçoes - para verificar se o tiro
dado acertou, e no que acertou.*/

void GeraMatriz(BN* p, int* m, int* n){
	int i, j;

	printf("Informe o numero de linhas da sua matriz: \n");
	scanf("%d", m);
	printf("Informe o numero de colunas da sua matriz: \n");
	scanf("%d", n);

	p = (BN **)malloc ((*m)*sizeof(BN*));
	for (i = 0; i < *m; ++i){
		p[i] = (BN*)malloc((*n)*sizeof(BN));
		for (j = 0; j < *n; ++j){
			p[i][j].valor = 0;
			p[i][j].ocupado = 0;
			/*No inicio, eh feita uma matriz nula - 0 indicaria agua.
			Portanto, o 'valor' dos elementos do tipo BN da matriz sao
			setados para 0. Alem disso, como no inicio todos os elementos
			da matriz estao vazios, isto eh, somente com agua, o parametro
			ocupado tambem eh setado com 0.*/
		}
	}
	printf("Sua matriz eh:\n");
	for (i = 0; i < *m; ++i){
		for (j = 0; j < *n; ++j){
			printf("%d\t", p[i][j].valor);
		}
		printf("\n");
	}

}

void Randomizar(BN* p, int * m, int * n){
	
	int sementei, sementej, barco, direcao;

	srand(time(NULL));
	sementei = rand() % (*m + 1);
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

	sementej = rand() % (*n + 1);
	/*Vale lembrar que, no caso de cada coordenada, os limites dos
	valores sorteados sao dados pelas dimensoes da matriz gerada.*/

	barco = rand() % 5;
	/*0 - agua, 1 - portal, ponteiro que joga o tiro dado no adversario
	no proprio tabuleiro de quam atirou, 2 - sub, 3 - encouraçado,
	4 - porta-avioes.*/

	direcao = rand() % 4;
	/*0 - esquerda, 1 - direita, 2 - acima, 3 - abaixo.*/

	printf("%d\n", direcao);
	printf("%d\n", sementei);
	printf("%d\n", sementej);
	printf("%d\n", barco);










}

int main(){
	BN** p;
	int* m;
	int* n;
	int i;

	GeraMatriz(&p, m, n);
	Randomizar(&p, m, n); 

	for (i = 0; i < *m; ++i){
		free(p[i]);
	}
	free(p);
	
	return 0;
}