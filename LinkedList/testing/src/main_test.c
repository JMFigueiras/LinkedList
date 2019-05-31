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
//**********LISTAS***********
#include "../inc/newTest.h"
#include "../inc/addTest.h"
#include "../inc/getNodeTest.h"
#include "../inc/addNodeTest.h"
//**********LISTAS***********


#include "../inc/deleteLinkedListTest.h"
#include "../inc/lenTest.h"
#include "../inc/getTest.h"
#include "../inc/containsTest.h"
#include "../inc/setTest.h"
#include "../inc/removeTest.h"
#include "../inc/clearTest.h"
#include "../inc/cloneTest.h"
#include "../inc/pushTest.h"
#include "../inc/indexOfTest.h"
#include "../inc/isEmptyTest.h"
#include "../inc/popTest.h"
#include "../inc/subListTest.h"
#include "../inc/containsAllTest.h"
#include "../inc/sortTest.h"


void startTesting(int testGroup)
{


    switch(testGroup)
    {
        case 1:
            utest_printStartTesting("ll_newLinkedList()");
            utest_init();
            utest_startTest(newTestCase01,newTestSetup,">Caso [Crear un nuevo LinkedList]");
            utest_printStatistics("ll_newLinkedList()");
            break;

        case 2:
            utest_printStartTesting("ll_len()");
            utest_init();
            utest_startTest(lenTestCase01,lenTestSetup,">Caso [Cantidad de elementos de una lista con elementos]");
            utest_startTest(lenTestCase02,lenTestSetup,">Caso [Cantidad de elementos de una lista vacia]");
            utest_startTest(lenTestCase03,lenTestSetup,">Caso [Cantidad de elementos de una lista que apunta a NULL]]");
            utest_printStatistics("ll_len()");
            break;
        case 3:
            utest_printStartTesting("ll_getNode()");
            utest_init();
            utest_startTest(getNodeTestCase01,getNodeTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(getNodeTestCase02,getNodeTestSetup,">Caso [Solicitar el primer nodo]");
            utest_startTest(getNodeTestCase03,getNodeTestSetup,">Caso [Solicitar el ultimo nodo]");
            utest_startTest(getNodeTestCase04,getNodeTestSetup,">Caso [Solicita nodo fuera de indice]");
            utest_startTest(getNodeTestCase05,getNodeTestSetup,">Caso [Solicita nodo pasando una lista NULL]");
            utest_printStatistics("ll_getNode()");
            break;
        case 4:
            utest_printStartTesting("ll_addNode()");
            utest_init();
            utest_startTest(addNodeTestCase01,addNodeTestSetup,">Caso [Verifica si se incrementa el size de la lista al agregar nodos]");
            utest_startTest(addNodeTestCase02,addNodeTestSetup,">Caso [Agregar un nuevo nodo a la lista]");
            utest_startTest(addNodeTestCase03,addNodeTestSetup,">Caso [Verificar el nodo agregado]");
            utest_startTest(addNodeTestCase04,addNodeTestSetup,">Caso [Intentar agregar nodos pasando una lista NULL]");
            utest_startTest(addNodeTestCase05,addNodeTestSetup,">Caso [Intenta agregar un nodo el la posicion cero de una lista con elementos cargados]");
            utest_printStatistics("ll_addNode()");
            break;

        case 5:
            utest_printStartTesting("ll_add()");
            utest_init();
            utest_startTest(addTestCase01,addTestSetup,">Caso [Verifica si se incrementa el size de la lista al agregar elementos]");
            utest_startTest(addTestCase02,addTestSetup,">Caso [Agregar un nuevo elemento a la lista]");
            utest_startTest(addTestCase03,addTestSetup,">Caso [Verificar el elemento agregado]");
            utest_startTest(addTestCase04,addTestSetup,">Caso [Intentar agregar elementos pasando una lista NULL]");
            utest_printStatistics("ll_add()");
            break;

        case 6:
            utest_printStartTesting("ll_get()");
            utest_init();
            utest_startTest(getTestCase01,getTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(getTestCase02,getTestSetup,">Caso [Solicitar el primer elemento]");
            utest_startTest(getTestCase03,getTestSetup,">Caso [Solicitar el ultimo elemento]");
            utest_startTest(getTestCase04,getTestSetup,">Caso [Solicita elementos fuera de indice]");
            utest_startTest(getTestCase05,getTestSetup,">Caso [Solicitar elementos pasando una lista NULL]");
            utest_printStatistics("ll_get()");
            break;

        case 7:
            utest_printStartTesting("ll_set()");
            utest_init();
            utest_startTest(setTestCase01,setTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(setTestCase02,setTestSetup,">Caso [Verifica un elemento seteado]");
            utest_startTest(setTestCase03,setTestSetup,">Caso [Intenta setear un elemento fuera de indice]");
            utest_startTest(setTestCase04,setTestSetup,">Caso [Intenta setear un elemento pasando una lista NULL]]");
            utest_printStatistics("ll_set()");
            break;

        case 8:
            utest_printStartTesting("ll_remove()");
            utest_init();
            utest_startTest(removeTestCase01,removeTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(removeTestCase02,removeTestSetup,">Caso [Verifica si un elemento fue correctamente removido]");
            utest_startTest(removeTestCase03,removeTestSetup,">Caso [Intenta remover un elemento fuera de indice]");
            utest_startTest(removeTestCase04,removeTestSetup,">Caso [Intenta remover un elemento pasando una lista NULL]]");
            utest_printStatistics("ll_remove()");
            break;

        case 9:
            utest_printStartTesting("ll_clear()");
            utest_init();
            utest_startTest(clearTestCase01,clearTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(clearTestCase02,clearTestSetup,">Caso [Verifica si todos los elemento fueron correctamente removidos]");
            utest_startTest(clearTestCase03,clearTestSetup,">Caso [Intenta realizar un clear pasando una lista NULL]");
            utest_printStatistics("ll_clear()");
            break;

        case 10:
            utest_printStartTesting("ll_deleteLinkedList()");
            utest_init();
            utest_startTest(deleteLinkedListTestCase01,deleteLinkedListTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(deleteLinkedListTestCase02,deleteLinkedListTestSetup,">Caso [Intenta realizar un deleteLinkedList pasando una lista NULL]]");
            utest_printStatistics("ll_deleteLinkedList()");
            break;

        case 11:
            utest_printStartTesting("ll_indexOf()");
            utest_init();
            utest_startTest(indexOfTestCase01,indexOfTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(indexOfTestCase02,indexOfTestSetup,">Caso [Intenta realizar un indexOf pasando una lista NULL]");
            utest_printStatistics("ll_indexOf()");
            break;

        case 12:
            utest_printStartTesting("ll_isEmpty()");
            utest_init();
            utest_startTest(isEmptyTestCase01,isEmptyTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(isEmptyTestCase02,isEmptyTestSetup,">Caso [Intenta realizar un isEmpty pasando una lista NULL]");
            utest_printStatistics("ll_isEmpty()");
            break;

        case 13:
            utest_printStartTesting("ll_push()");
            utest_init();
            utest_startTest(pushTestCase01,pushTestSetup,">Caso [Verifica si se incrementa el size de la lista al agregar elementos]");
            utest_startTest(pushTestCase02,pushTestSetup,">Caso [Agregar un nuevo elemento a la lista]");
            utest_startTest(pushTestCase03,pushTestSetup,">Caso [Verificar el elemento agregado]");
            utest_startTest(pushTestCase04,pushTestSetup,">Caso [Intenta insertar un elemento fuera del indice]");
            utest_startTest(pushTestCase05,pushTestSetup,">Caso [Intentar insertar elementos pasando una lista NULL]");
            utest_printStatistics("ll_push()");
            break;

        case 14:
            utest_printStartTesting("ll_pop()");
            utest_init();
            utest_startTest(popTestCase01,popTestSetup,">Caso [Verifica si se decrementa el size de la lista al quitar elementos]");
            utest_startTest(popTestCase02,popTestSetup,">Caso [Agregar un nuevo elemento a la lista]");
            utest_startTest(popTestCase03,popTestSetup,">Caso [Verificar el elemento quitado]");
            utest_startTest(popTestCase04,popTestSetup,">Caso [Intenta eliminar un elemento fuera del indice]");
            utest_startTest(popTestCase05,popTestSetup,">Caso [Intentar insertar elementos pasando una lista NULL]");
            utest_printStatistics("ll_pop()");
            break;

        case 15:
            utest_printStartTesting("ll_contains()");
            utest_init();
            utest_startTest(containsTestCase01,containsTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(containsTestCase02,containsTestSetup,">Caso [Verifica si encuentra elementos contenidos]");
            utest_startTest(containsTestCase03,containsTestSetup,">Caso [Intentar verificar si un elemento esta contenido pasando una lista NULL]");
            utest_printStatistics("ll_contains()");
            break;

        case 16:
            utest_printStartTesting("ll_containsAll()");
            utest_init();
            utest_startTest(containsAllTestCase01,containsAllTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(containsAllTestCase02,containsAllTestSetup,">Caso [Verifica el valor de retorno cuando la lista2 NO esta contenida en la lista1]");
            utest_startTest(containsAllTestCase03,containsAllTestSetup,">Caso [Verifica el valor de retorno cuando la lista2 SI esta contenida en la lista1]");
            utest_startTest(containsAllTestCase04,containsAllTestSetup,">Caso [Intentar verificar si un elemento esta contenido pasando una lista NULL]");
            utest_printStatistics("ll_containsAll()");
            break;

        case 17:
            utest_printStartTesting("ll_subList()");
            utest_init();
            utest_startTest(subListTestCase01,subListTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(subListTestCase02,subListTestSetup,">Caso [Verifica si los elementos de la sub lista son correctos]");
            utest_startTest(subListTestCase03,subListTestSetup,">Caso [Intenta generar sublistas con parametros fuera del indice]");
            utest_startTest(subListTestCase04,subListTestSetup,">Caso [Intenta crear una sublista pasando una lista NULL]");
            utest_printStatistics("ll_subList()");
            break;

        case 18:
            utest_printStartTesting("ll_clone()");
            utest_init();
            utest_startTest(cloneTestCase01,cloneTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(cloneTestCase02,cloneTestSetup,">Caso [Verifica si los elementos de la lista clonada son correctos]");
            utest_startTest(cloneTestCase03,cloneTestSetup,">Caso [Intenta crear una lista clonada pasando una lista NULL]");
            utest_printStatistics("ll_clone()");
            break;

        case 19:
            utest_printStartTesting("ll_sort()");
            utest_init();
            utest_startTest(sortTestCase01,sortTestSetup,">Caso [Verifica retorno con parametros correctos]");
            utest_startTest(sortTestCase02,sortTestSetup,">Caso [Verifica si la lista se encuentra correctamente ordenada]");
            utest_startTest(sortTestCase03,sortTestSetup,">Caso [Intenta ordenar una lista NULL]");
            utest_startTest(sortTestCase04,sortTestSetup,">Caso [Intenta ordenar pasando un puntero a la funcion criterio NULL]");
            utest_startTest(sortTestCase05,sortTestSetup,">Caso [Intenta ordenar pasando el orden fuera de valor]");
            utest_printStatistics("ll_sort()");
            break;
    }


}
