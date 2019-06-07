#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);

static int addNode(LinkedList* this, int nodeIndex, void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinámica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void){

    LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL){
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this){

    int returnAux = -1;

    if(this != NULL){
        returnAux = this->size;
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex){

    Node* pNode = NULL;

    int len = ll_len(this);

    if(this != NULL && nodeIndex > -1 && nodeIndex < len){

        pNode = this->pFirstNode;

        int i = 0;

        while(i < len && pNode != NULL && i != nodeIndex){
            pNode = pNode->pNextNode;
            i++;
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex){

    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement){

    int returnAux = -1;

    if(this != NULL && nodeIndex > -1 && nodeIndex <= ll_len(this)){

        Node* pNew = (Node*)malloc(sizeof(Node));

        if(pNew != NULL){
            pNew->pElement = pElement;

            if(nodeIndex == 0){

                pNew->pNextNode = this->pFirstNode;
                this->pFirstNode = pNew;
                this->size++;
                returnAux = 0;
            }
            else{

                Node* pAux = test_getNode(this, nodeIndex-1);

                if(pAux != NULL){
                    pNew->pNextNode = pAux->pNextNode;
                    pAux->pNextNode = pNew;
                    this->size++;
                    returnAux = 0;
                }

            }
        }

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement){

    return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement){

    int returnAux = -1;

    if(this != NULL){
        returnAux = addNode(this, ll_len(this), pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index){

    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < ll_len(this)){
        returnAux = getNode(this, index)->pElement;
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement){

    int returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this)){

        Node* node = getNode(this, index);

        if(node != NULL){
            node->pElement = pElement;
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index){

    int returnAux = -1;

    if(this != NULL && index > -1 && index < ll_len(this)){

        Node* toBeDeleted = getNode(this, index);

        if(toBeDeleted != NULL){

            if(index == 0){
                this->pFirstNode = toBeDeleted->pNextNode;
                free(toBeDeleted);
                this->size--;
                returnAux = 0;
            }
            else{
                Node* previous = getNode(this, index-1);
                previous->pNextNode = toBeDeleted->pNextNode;
                free(toBeDeleted);
                this->size--;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this){

    int returnAux = -1;

    if(this != NULL){

        for(int i = 0; i < ll_len(this); i++){
            ll_remove(this, i);
        }

        this->pFirstNode = NULL;

        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this){

    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0){
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement){

    int returnAux = -1;

    if(this != NULL){

        for(int i = 0; i < ll_len(this); i++){
            Node* pAux = getNode(this, i);

            if(pAux != NULL && pAux->pElement == pElement){
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this){

    int returnAux = -1;

    if(this != NULL){

        if(ll_len(this) > 0)
            returnAux = 0;
        else
            returnAux = 1;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement){

    int returnAux = -1;

    if(this != NULL && index > -1 && index <= ll_len(this)){
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this, int index){

    void* returnAux = NULL;

    if(this != NULL && index > -1 && index < ll_len(this)){
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }

    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){

    int returnAux = -1;

    if(this != NULL){

        if(ll_indexOf(this, pElement) != -1)
            returnAux = 1;
        else
            returnAux = 0;
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2){

    int returnAux = -1;

    if(this != NULL && this2 != NULL){

        int len = ll_len(this);
        int cont = 0;

        for(int i = 0; i < len; i++){
            void* pElement = ll_get(this2, i);

            if(ll_contains(this, pElement))
                cont++;
        }

        if(cont == len)
            returnAux = 1;
        else
            returnAux = 0;
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to){

    LinkedList* cloneArray = NULL;

    int len = ll_len(this);

    if(this != NULL && from > -1 && from < len && to > from && to <= len){

        cloneArray = ll_newLinkedList();

        for(int i = from; i < to; i++){

            void* pElement = ll_get(this, i);

            if(pElement != NULL)
                ll_add(cloneArray, pElement);
        }

    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){

    LinkedList* cloneArray = NULL;

    if(this != NULL)
        cloneArray = ll_subList(this, 0, ll_len(this));

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                (0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){

    int returnAux =-1;

    if(this != NULL && pFunc != NULL && (order == 0 ||  order == 1)){

        int flag;

        do{

            flag = 0;

            for(int i = 0; i < ll_len(this)-1; i++){

                void* pElement = ll_get(this, i);
                void* pElementNext = ll_get(this, i+1);

                if((order == 1 && pFunc(pElement, pElementNext) > 0) || (order == 0 && pFunc(pElement, pElementNext) < 0)){

                    void* pAux = pElement;
                    ll_set(this, i, pElementNext);
                    ll_set(this, i+1, pAux);
                    returnAux = 0;
                    flag = 1;
                }
            }

        }while(flag);

    }

    return returnAux;
}

void* ll_filter(LinkedList* this, int (*pFunc)(void*)){

    LinkedList* newLinkedList = NULL;

    if(this != NULL && pFunc != NULL){

        newLinkedList = ll_newLinkedList();

        Node* pNode = ll_startIterator(this);

        if(newLinkedList != NULL){

            while(pNode != NULL){

                if(pFunc(pNode->pElement))
                    ll_add(newLinkedList, pNode->pElement);

                pNode = ll_getNextIterator(this);
            }
        }

    }

    return newLinkedList;
}

Node* ll_startIterator(LinkedList* this){

    this->nodeIterator = NULL;

    if(this != NULL){
        this->nodeIterator = this->pFirstNode;
    }

    return this->nodeIterator;
}

Node* ll_getNextIterator(LinkedList* this){

    if(this != NULL && this->nodeIterator != NULL){
        this->nodeIterator = (this->nodeIterator)->pNextNode;
    }

    return this->nodeIterator;
}

void ll_map(LinkedList* this, void (*pFunc)(void*)){

    if(this != NULL && pFunc != NULL){

        Node* pNode = ll_startIterator(this);

        while(pNode != NULL){
            pFunc(pNode->pElement);
            pNode = ll_getNextIterator(this);
        }
    }
}
