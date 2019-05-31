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

void indexOfTestSetup(void)
{
	utest_print("Setup...\r\n");
}

void indexOfTestCase01(void)
{
    LinkedList* list;
    int r;
    list = ll_newLinkedList();
    ll_add(list,NULL);
    r = ll_indexOf(list,NULL);
    utest_assertEqualsIntMsg(r,0,"\nError en el valor de retorno de <indexOf> si los parametros son correctos y \nel elemento esta contenido se debe retornar la posicion del elemento\n");
    r = ll_indexOf(list,(void*)1);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <indexOf> si los parametros son correctos y \nel elemento NO esta contenido se debe retornar -1\n");
}

void indexOfTestCase02(void)
{
    int r;
    r = ll_indexOf(NULL,0);
    utest_assertEqualsIntMsg(r,-1,"\nError en el valor de retorno de <indexOf> si la lista pasada es NULL\n el valor a retornar es (-1)\n");
}
