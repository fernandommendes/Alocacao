#include <stdio.h>
#include <stdlib.h>

void preencherVetor();
int main(void) {
	setbuf(stdout, NULL);
	preencherVetor();

	return 0;
}

void preencherVetor(){

	double *valorMercadoria,
		   *percDesconto,
		   *valorFinal,
		   somaValor = 0;
	int cont,
		cont50 = 0;
	char resp;

	valorMercadoria = (double *) malloc (sizeof(double));
	percDesconto = (double *) malloc (sizeof(double));

	for(cont = 0;  ; cont++){
		do{
			printf("\nDigite o valor da mercadoria: R$\n");
			fflush(stdin);
			scanf("%lf", &valorMercadoria[cont]);

			if (valorMercadoria[cont] <= 0 ){
				printf("\nValor inválido. Digite novamente.\n");
			}

		}while(valorMercadoria[cont] <= 0);

		do{
			printf("\nDigite o percentual de desconto (De 0 até 100%): ");
			fflush(stdin);
			scanf("%lf", &percDesconto[cont]);

			if(percDesconto[cont] < 0 || percDesconto[cont] > 100){
				printf("\nValor inválido. Digite novamente. \n");
			}
		}while(percDesconto[cont] < 0 || percDesconto[cont] > 100);

		valorFinal[cont] = valorMercadoria[cont] - valorMercadoria[cont]*percDesconto/100;
		printf("\nValor final a pagar R$%.2lf", valorFinal[cont]);

		somaValor += valorFinal[cont];

		if(percDesconto[cont] > 50){
			cont50++;
		}

		do{
			printf("\nDeseja finalizar (S-Sim/N-Não): \n");
			fflush(stdin);
			scanf("%c", &resp);
		}while(resp != 'S' && resp != 'N');

		if (resp == 'S'){
			break;
		}else{
			valorMercadoria = (double *) realloc (valorMercadoria, (cont + 2) * sizeof(double));
			valorFinal = (double *) realloc (valorFinal, (cont + 2) * sizeof(double));
			valorMercadoria = (double *) realloc (valorMercadoria, (cont + 2) * sizeof(double));
		}
	}

}
