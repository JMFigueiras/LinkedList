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
#define LENGTH 6


static char* unsortedList[] = {"Za","Zb","Xd","Xb","Ya","Yc"};
static int sector[] = {1,1,2,3,4,6};
static float salary[] = {1001,2000,1002,3000,4000,8000};
static float salarySortedUp[] = {8000,4000,3000,2000,1002,1001};
static int id[] = {11,20,3,4,9,99};


void sortTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void sortTestCase01(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, compareEmployee,1);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <sort> si los parametros son correctos\n la funcion retorna 0\n");

}


void sortTestCase02(void)
{
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];
    Employee* pAuxGet[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    ll_sort(list, compareEmployee,0);

    for(i=0; i < LENGTH; i++)
    {
        pAuxGet[i] = ll_get(list,i);
        utest_assertNotNullMsg(pAuxGet[i],"Error al intentar obtener un elemento luego de ordenar");
        utest_assertEqualsFloatMsg(((Employee*)pAuxGet[i])->salary,salarySortedUp[i],"El orden de la lista es incorrecto");
    }

}
void sortTestCase03(void)
{
    int r;
    r = ll_sort(NULL, compareEmployee,1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el puntero a la lista es NULL\n la funcion retorna -1\n");

}


void sortTestCase04(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, NULL,1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el puntero a la funcion criterio es NULL\n la funcion sort retorna -1\n");

}

void sortTestCase05(void)
{
    int r;
    int i;
    LinkedList* list;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }
    r = ll_sort(list, compareEmployee,-1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <sort> si el orden es distinto de 1 o 0\n la funcion sort retorna -1\n");

}
