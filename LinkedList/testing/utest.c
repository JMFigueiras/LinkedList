/*
	utest : Unit test library for embedded C programs.
    Copyright (C) <2016>  <Ernesto Gigliotti>

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

#include "utest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERBOSE_TEST 0

char utest_printBuffer[256];
char utest_printErrorBuffer[409600];
int utest_flagTestError;
int utest_lineTestError;
char* utest_fileTestError;
int utest_totalTestsCounter;
int utest_okTestsCounter;
int utest_varAux;

void utest_init(void)
{
	utest_totalTestsCounter=0;
	utest_okTestsCounter=0;
}


void utest_printStartTesting(char* testName)
{
    utest_printErrorBuffer[0] = '\0';
    utest_print("\r\n\r\n********************************************************************\r\n");
	utest_print1("***********    Start Testing of: %20s   ************\r\n",testName);
    utest_print("********************************************************************\r\n");

}
void utest_printStatistics(char* testName)
{


    if(utest_totalTestsCounter!=utest_okTestsCounter || VERBOSE_TEST == 1)
    {
        printf(utest_printErrorBuffer);
    }
    utest_printErrorBuffer[0] = '\0';  // CLEAN ERROR BUFFER

    utest_print("********************************************************************\r\n");
	utest_print1("*******   Unit Tests Statistics: %20s   ************\r\n",testName);
    utest_print("********************************************************************\r\n");

	if(utest_totalTestsCounter>0)
	{
		int per = (int)(((float)utest_okTestsCounter/(float)utest_totalTestsCounter)*100.0);
        utest_print("**| Total Test  |  Succed Test  |  Failed Test  |  Effectiveness |**\r\n");
       utest_print4("**|    %3d      |      %3d      |      %3d      |     %3d perc.  |**\r\n",utest_totalTestsCounter,utest_okTestsCounter,(utest_totalTestsCounter-utest_okTestsCounter),per);
	}
	else
		utest_print("No tests executed.\r\n");

    utest_print("********************************************************************\r\n\r\n");

    printf(utest_printErrorBuffer);
    utest_printErrorBuffer[0] = '\0'; // CLEAN ERROR BUFFER
}

void utest_startTest(void(*fncTest)(void),void(*fncBefore)(void),char* testName)
{
	if(fncTest!=0)
	{
	    utest_print("--------------------------------------------------------------------\r\n");
		utest_flagTestError=0;
		utest_print1("%-40s\r\n",testName);

		if(fncBefore!=0)
			fncBefore();
		utest_totalTestsCounter++;
		fncTest();
		if(utest_flagTestError==1)
		{
			utest_print2("TEST FAILED\r\nFILE:%s LINE:%d\r\n",utest_fileTestError,utest_lineTestError);
		}
		else
		{
			utest_print("TEST OK\r\n");
			utest_okTestsCounter++;
		}


	}
}



