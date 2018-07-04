#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int data;
	struct node *next;
}node;

typedef struct{
    node *head;
    node *end;
    int size;
}list;

int list_size(list* l);
int list_front(list* l); // devuelve primer elemento de la lista
int list_back(list* l); // devuelve último elemento de la lista
int list_pop_front(list* l); // quita el primer elemento (y regresa su valor)
int list_pop_back(list* l); // quita el último elemento (y regresa su valor)
void list_add_front(list* l, int data); // agrega al inicio
void list_add_back(list* l, int data); // agrega al final
void list_clear(list* l); // limpia la lista

int main()
{
	list *lista;
	lista = malloc(sizeof(lista));
	printf("lista size: %d\n",lista->size);

	return 0;
}

int list_size(list *l)
{
	return l->size;
}

int list_front(list* l)
{
	return l->head->data;
}

int list_back(list* l)
{
	return l->end->data;
}

int list_pop_front(list* l)
{
	node *aux;
	aux = l->head;
	
	if(l->size >1)
		l->head = l->head->next;
	else if(l->size == 1)
		l->head = NULL, l->end = NULL;
	else
		return -666;

	(l->size)--;
	//free(aux);
	return aux->data;
}

int list_pop_back(list* l)
{
	int i;
	node *aux, *aux2;
	aux = l->head;
	aux2 = l->end;

	if(l->size > 1)
	{
		for (i = 0; i < l->size-1; i++)
			aux = aux->next;
		l->end = aux;
		aux->next = NULL;
	}else if (l->size == 1)
	{
		l->head = NULL;
		l->end = NULL;
	}else
		return -666;

	(l->size)--;
	return aux2->data;
}

void list_add_front(list* l, int data)
{
	node *new;
	if((new = malloc(sizeof(node))) == NULL)
		printf("error malloc\n");
	else
	{
		new->data = data;

		if(l->size > 0)
			new->next = l->head;
		else
		{
			l->end = new;
			new->next = NULL;
		}

		l->head = new;
		(l->size)++;
	}
}

void list_add_back(list* l, int data)
{
	node *new;
	if((new = malloc(sizeof(node))) == NULL)
		printf("error malloc\n");
	else
	{
		new->data = data;
		
		if(l->size > 0)
			l->end->next = new;
		else
			l->head = new;

		new->next=NULL;
		l->end = new;
		(l->size)++;
	}
}

void list_clear(list* l)
{
	int i;
	node *aux;
	if (l->size > 0)
	{
		for(i = 0; i< l->size; i++)
		{
			aux = l->head;
			l->head = l->head->next;
			free(aux);
		}	
	}
	l->size = 0;
}