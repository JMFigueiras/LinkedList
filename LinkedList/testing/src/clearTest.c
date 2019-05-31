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

void clearTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void clearTestCase01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_clear(list);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <clear> si los parametros son correctos es 0\n");
}

void clearTestCase02(void)
{
    LinkedList* list;
    void* pElement;
    void* pElement2 = newEmployee(10,"JUAN","PEREZ",1,1);
    list = ll_newLinkedList();
    ll_add(list,NULL);
    ll_clear(list);
    ll_add(list,NULL);
    ll_add(list,pElement2);
    pElement = ll_get(list,1);
    utest_assertEqualsPointerMsg(pElement,pElement2,"\nError en el valor de retorno de <get> al solicitar \nun elemento luego de eliminar sus antecesores con <clear>\n");
}


void clearTestCase03(void)
{
    int r;
    r = ll_clear(NULL);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <clear> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
