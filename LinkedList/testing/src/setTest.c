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

void setTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void setTestCase01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_set(list,0,NULL);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <set> si los parametros son correctos es 0\n");
}


void setTestCase02(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);
    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_set(list,0,pElement2);
    pElement = ll_get(list,0);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <get> al solicitar el primer elemento steado con <set>\n");

}

void setTestCase03(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_set(list,-1,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <set> al intentar setear un elemento fuera de indice (< 0),\n se deberia retornar -1\n");
    r = ll_set(list,1,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <set> al intentar setear un elemento fuera de indice (>= ll_len),\n se deberia retornar -1\n");
}

void setTestCase04(void)
{
    int r;
    r = ll_set(NULL,0,NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <set> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
