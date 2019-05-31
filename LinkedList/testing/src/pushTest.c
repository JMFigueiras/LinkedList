/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../../testing/utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//INCLUDE LIBRARY TO TEST
#include "../../inc/LinkedList.h"
#include "../../testing/inc/Employee.h"

//DEFINES OF THIS TEST
#define LENGTH 5


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1000,1000,2000,3000,4000,8000};
static int id[] = {11,20,3,4,9,99};


void pushTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void pushTestCase01(void)
{
    LinkedList* list;

    list = ll_newLinkedList();
    ll_push(list,0,NULL);
    utest_assertEqualsIntMsg(1,list->size,"\nError en el valor de size de la lista se debe incrementar al agregar un nuevo elemento\n");

}

void pushTestCase02(void)
{
    int i,r;
    LinkedList* list;
    Employee* pAux[LENGTH];
    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        r = ll_push(list,list->size,pAux[i]);
        utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <push> si se agrego un elemento correctamente\n el valor a retornar es (0)\n");
    }

}

void pushTestCase03(void)
{
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];
    void* pElement;
    char msg[256];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_push(list,list->size,pAux[i]);
    }

    for (i=0;i < LENGTH;i++)
    {
        pElement = ll_get(list,i);
        utest_assertNotNullMsg(pElement,"\nExiste un error al intentar obtener el elemento.\n El valor de retorno no puede ser NULL\n");
        sprintf(msg,"\nError en el valor de retorno de <get> al solicitar el elemento en la  posicion %i\n",i);
        utest_assertEqualsPointerMsg(pElement,pAux[i],msg);
    }

}

void pushTestCase04(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_push(list,-1,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <push> al intentar setear un elemento fuera de indice (< 0),\n se deberia retornar -1\n");
    r = ll_push(list,2,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <push> al intentar setear un elemento fuera de indice (>= ll_len),\n se deberia retornar -1\n");
}


void pushTestCase05(void)
{
    int r;
    r = ll_push(NULL,0,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <push> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
