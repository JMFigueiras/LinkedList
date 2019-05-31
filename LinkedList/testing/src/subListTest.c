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


void subListTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void subListTestCase01(void)
{
    LinkedList* list;

    list = ll_newLinkedList();
    ll_add(list,NULL);

    utest_assertNotNullMsg(ll_subList(list,0,1),"\nError en el valor de retorno de <subList> si los parametros son correctos\nno debe retornar NULL\n");

}

void subListTestCase02(void)
{
    int i;
    LinkedList* list;
    LinkedList* pSubList;
    Employee* pAux[LENGTH];
    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    pSubList = ll_subList(list,0,2);

    for(i=0; i < 2; i++)
    {
        utest_assertEqualsPointerMsg(ll_get(pSubList,i),ll_get(list,i),"Error: la sub lista no contiene los elementos solicitados");
    }
}



void subListTestCase03(void)
{
    int i;
    LinkedList* list;
    LinkedList* pSubList;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    pSubList = ll_subList(list,-1,2);
    utest_assertNullMsg(pSubList,"\nError en el valor de retorno de <subList> el from esta fuera de indice (< 0),\n se deberia retornar NULL\n");

    pSubList = ll_subList(list,0,6);
    utest_assertNullMsg(pSubList,"\nError en el valor de retorno de <subList> el to esta fuera de indice (> len()),\n se deberia retornar NULL\n");

}

void subListTestCase04(void)
{
    int i;
    LinkedList* list;
    LinkedList* pSubList;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
    }

    pSubList = ll_subList(NULL,0,2);
    utest_assertNullMsg(pSubList,"\nError en el valor de retorno de <subList> si la lista pasada es NULL\n el valor a retornar es (NULL)\n");
}
