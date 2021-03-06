#include <stdlib.h>
#include "miLista.h"

//Inserta un elemento con valor del objeto ingresado como parámetro, después del elemento ingresado como parámetro
extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento)
{
	if ((lista != NULL) && (elemento != NULL) && (Lista_Vacia(lista) == 0)) 
	{
		//Puntero temporal ElementoLista para verificar si el elemento ingresado como parámetro existe		
		ElementoLista *temp = Lista_Buscar(lista, elemento->objeto);
		
		//Si el elemento ingresado como parámetro es el último, se usa la función Lista_InsertaFin	
		if (elemento == Lista_Ultimo(lista))
		{
			Lista_InsertarFin(lista, objeto);
		}
		else if (temp != NULL)
		{
			//Se crea un puntero ElementoLista donde se guardará el objeto ingresado como parámetro y se reserva el espacio de memoria			
			ElementoLista *nuevo = (ElementoLista *)malloc(sizeof(ElementoLista));

			//Se le asigna al nuevo elemento el objeto ingresado como parámetro
			nuevo->objeto = objeto;

			//Se mueven  los punteros
			nuevo->anterior = elemento;
			nuevo->siguiente = elemento->siguiente;
			elemento->siguiente->anterior = nuevo;
			elemento->siguiente = nuevo;

			//Incrementa el valor de número de elementos de la lista
			lista->numeroElementos++;
			return 1;
		}
	}
	return -1;
}
