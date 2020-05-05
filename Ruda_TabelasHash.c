#include <stdio.h>
#include <stdlib.h>

typedef struct nos{

	int data;
	struct nos *prox;

} nos;

typedef struct lista{

	nos *primeiro;
	nos *ultimo;

} lista;

void hash_push(lista *, const int);
unsigned x;

void main ()
{

	unsigned n;
	nos *j;
	int y, i, tmp;

	scanf("%u", &n);

	while (n--)
	{

		scanf("%u %d", &x, &y);

		lista hash[x];
		for (i = 0; i < x; ++i)
			hash[i].primeiro = NULL, hash[i].ultimo = NULL;

		for (i = 0; i < y; ++i)
			scanf("%d", &tmp), hash_push(hash, tmp);

		for (i = 0; i < x; ++i)
		{	
			printf("%d -> ", i);
			for (j = hash[i].primeiro; j; j = j->prox)
				printf("%d -> ", j->data);

			printf("\\");
			printf("\n");

		}

		if (n)
			printf("\n");

	}

}

void hash_push(lista *__hash, const int key)
{

	nos *aux;
	aux = (nos *) malloc(sizeof(nos));

	if(!aux)
		exit(1);

	int idx = key % x;
	if (__hash[idx].primeiro)
		__hash[idx].ultimo->prox = aux;
	else
		__hash[idx].primeiro = aux;

	__hash[idx].ultimo = aux;
	aux->prox = NULL;
	aux->data = key;
	
}