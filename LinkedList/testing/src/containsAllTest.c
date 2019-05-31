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


void containsAllTestSetup(void)
{
	utest_print("Setup...\r\n");
}


void containsAllTestCase01(void)
{
    int r;
    LinkedList* list;

    list = ll_newLinkedList();
    r = ll_containsAll(list,list);
    utest_assertNotEqualsIntMsg(r,-1,"\nError en el valor de retorno de <containsAll> si los parametros son correctos\n debe retornar 0 o 1\n");
}


void containsAllTestCase02(void)
{
    int i,r;
    LinkedList* list;
    LinkedList* pOtherList;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    pOtherList = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
        ll_add(pOtherList,pAux[i]);
    }

    ll_remove(list,0);

    r = ll_containsAll(list,pOtherList);
    utest_assertEqualsIntMsg(r, 0 ,"Error en el valor de retorno <containsAll> si la lista2 no esta contenida se debe retornar 0");


}

void containsAllTestCase03(void)
{
    int i,r;
    LinkedList* list;
    LinkedList* pOtherList;
    Employee* pAux[LENGTH];

    list = ll_newLinkedList();
    pOtherList = ll_newLinkedList();

    for(i=0; i < LENGTH; i++)
    {
        pAux[i] = newEmployee(id[i],unsortedList[i],unsortedList[i],salary[i],sector[i]);
        ll_add(list,pAux[i]);
        ll_add(pOtherList,pAux[i]);
    }

    r = ll_containsAll(list,pOtherList);
    utest_assertEqualsIntMsg(r, 1 ,"Error en el valor de retorno <containsAll> si la lista2 no esta contenida se debe retornar 0");


}

void containsAllTestCase04(void)
{
    LinkedList* list;
    list = ll_newLinkedList();
    utest_assertEqualsIntMsg(ll_containsAll(list,NULL),-1,"\nError en el valor de retorno de <containsAll> si la lista (this) pasada es NULL\n el valor a retornar es -1\n");
    utest_assertEqualsIntMsg(ll_containsAll(NULL,list),-1,"\nError en el valor de retorno de <containsAll> si la lista (this2) pasada es NULL\n el valor a retornar es -1\n");
}

