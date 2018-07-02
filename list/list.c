#include <stdio.h>

typedef struct {
	int data;
	node next;
}node;

typedef struct{
    node *head;
    int size = 0;
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
	int i;
	node *aux;
	aux = l->head;
	
	for(i = 0; i < l->size; i++)
		aux = aux->next;

	return aux->data;
}

int list_pop_front(list* l)
{
	node *aux;
	aux = l->head;
	
	if(l->size >1)
		l->head = l->head->next;
	else if(l->size == 1)
		l->head = NULL;
	else
		return -666;

	(l->size)--;
	return aux->data;
}

int list_pop_back(list* l)
{
	int i;
	node *aux, *aux2;
	aux = l->head;

	if(l->size > 1)
	{
		for (i = 0; i < l->size-1; i++)
			aux2 = aux2->next;
		aux = aux2->next;
		aux2->next = NULL;
	}else if (l->size == 1)
	{
		l->head = NULL;
	}else
		return -666;

	(l->size)--;
	return aux->data;
}

void list_add_front(list* l, int data)
{
	node *new;
	new->data = data;
	if(l->size > 0)
		new->next = l->head;
	else
		new->next = NULL;
	l->head = new;
	(l->size)++;
}

void list_add_back(list* l, int data)
{
	node *new;
	new->data = data;
	new->next = l->head;
	l->head = new;
}

void list_clear(list* l)
{

}