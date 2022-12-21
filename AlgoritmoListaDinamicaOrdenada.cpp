#include <stdio.h>
#include <stdlib.h>

struct tipolista{
	int codigo;
	struct tipolista *prox;
};

struct tipolista *primeiro = NULL;

void insere(int x){
	if (primeiro==NULL){
		struct tipolista *no;
		no = (struct tipolista*)malloc(sizeof(struct tipolista));
		primeiro = no;
		no->codigo = x;
		no->prox = NULL;
	}else{
		struct tipolista *varajuda;
		varajuda = primeiro;
		while(varajuda->prox !=NULL){
			varajuda = varajuda->prox;
		}
		varajuda->prox = (struct tipolista*)malloc(sizeof(struct tipolista));
		varajuda = varajuda->prox;
		varajuda->codigo = x;
		varajuda->prox = NULL;
		return;
	}
	
}

void inseremeio(){
	int x;
	if(primeiro==NULL){
		printf("FILA VAZIA, INSERINDO ELEMENTO NO INICIO.\n\n");
		printf("Digite o numero que voce quer inserir: ");
		scanf("%d",&x);
		struct tipolista *no;
		no = (struct tipolista*)malloc(sizeof(struct tipolista));
		primeiro = no;
		no->codigo = x;
		no->prox = NULL;
	}else{
		printf("Apos qual numero você quer inserir este elemento? ");
		scanf("%d",&x);
		struct tipolista *assist;
		assist = primeiro;
		while(assist->codigo != x && assist->prox!=NULL){
			assist = assist->prox;	
		}
		if(assist->codigo != x){
			printf("VALOR NÃO ENCONTRADO, VOLTANDO AO MENU.\n\n");
			system("pause");
			system("cls");
			return;
		}
		int y;
		struct tipolista *no;
		no = (struct tipolista*)malloc(sizeof(struct tipolista));
		printf("Digite o valor que você quer inserir: ");
		scanf("%d",&y);
		no->codigo=y;
		no->prox = assist->prox;
		assist->prox = no;	
	}
}

void ordenalista(){
	struct tipolista *assist;
	struct tipolista *assist2;
	int menorvalor;
	assist = primeiro;
	assist2 = primeiro;
	menorvalor = assist->codigo;
	while(assist->prox!=NULL){
		while(assist->prox!=NULL){
			if(menorvalor > assist->prox->codigo){
				menorvalor = assist->prox->codigo;
				assist->prox->codigo = assist2->codigo;
				assist2->codigo = menorvalor;
			}
			assist = assist->prox;
		}
		assist = assist2->prox;
		assist2 = assist2->prox;
		menorvalor = assist2->codigo;
	}
	return;
}


void imprimelista(){
	struct tipolista *varajuda;
	if(primeiro == NULL){
		return;
	}else{
		varajuda = primeiro;
		while(varajuda!=NULL){
			printf("%d ",varajuda->codigo);
			varajuda = varajuda->prox;
		}
		return;
	}
}

int main(){
	int x,e =-1;
	while(x!=0){
		printf("\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		printf("                MENU\n\n");
		printf("1 - Inserir um elemento apos algum elemento.                  LISTA\n");
		printf("2 - Inserir um elemento automaticamente a Lista.               | ");
		imprimelista();
		printf("|\n");
		printf("3 - Ordenar Lista\n0 - Sair.\n\n");
		printf("-=-=-=-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
		printf("Digite o numero da opcao -> ");
		scanf("%d",&x);
		switch (x)
		{	
   			case 1:
   				system("cls");
   				inseremeio();
   			break;
   				
   			case 2:
   				system("cls");
     			printf("Digite o valor do elemento que voce quer inserir: ");
     			int e;
     			scanf("%d",&e);
     			insere(e);
   			break;
			
			case 3:
				system("cls");
				ordenalista();
			break;
			
   			case 0:
   				system("cls");
   				printf("Finalizando o sistema...");
     		break;
     		
     		default:
     			system("cls");
     			printf("Voce digitou uma opcao que nao existe seu viadinho... Voltando ao menu.\n\n");
     			system("pause");
     			system("cls");
     		break;
	
		}
	}
}
