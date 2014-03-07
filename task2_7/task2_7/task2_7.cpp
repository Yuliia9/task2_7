/**
* @file		task2_7.cpp
* @brief	Program creates database of questions with four answers and number of right answer.
			Then it gives users randomly five questions and their answers and checks users answer.
			If it is wrong, program shows right answer 
*
* Copyright 2014 by Yuliia Lyubchik
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*/

#include "stdafx.h"
#include "task2_7.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const unsigned int ATTEMPT = 5;	/*maximum number of question in test*/

const unsigned char ERROR = 0;
const unsigned char SUCCESS = 1;
const unsigned char MAIN_SUCCESS = 0;

int main( )
{
	Interface();
	unsigned int num;
	unsigned char retCode;

	do
	{
		printf("Enter integer number of questions for testing: ");
		retCode = scanf("%u", &num);
		fflush(stdin); // Flush the input buffer
	} while (Type_checking(retCode, (int)num) == ERROR);

	printf("List will consist of %u questions.\n", num);


	struct test*  tests = (test*) malloc( num * sizeof(test) );

	if (tests == NULL)
	{
		printf("Error occurs while trying to allocate memory for list of tests. \n");
		return (int)ERROR;
	}


	retCode = Input(tests, num);
	if (retCode == ERROR)
	{
		free(tests);
		return (int)ERROR;
	}

	retCode = Testing(tests, num);
	if (retCode == ERROR)
	{
		free(tests);
		return (int)ERROR;
	}

	free(tests);
	system("pause");
	return MAIN_SUCCESS;
}


void Interface()
{
	printf("------------------------------------------------------------\n");
	printf("Welcome to your personal testing trainer!. \n\n");
	printf("Enter question, 4 answer choices and number of right answer.\n");
	printf("Program will choose 5 questions to test your knowledge.\n");
	printf("Made by Yuliia Lyubchik.\n");
	printf("-------------------------------------------------------------\n\n");
}


unsigned char Type_checking(unsigned char retCode, int val)
{
	if (retCode == ERROR)
	{
		printf("Type mismatch. Please next time check if you enter integer number. \n");
		return ERROR;
	}
	if (val <= 0)
	{
		printf("The value can not be negative or zero.\n");
		return ERROR;
	}
	return SUCCESS;
}


unsigned char Input(struct test* tests, unsigned int num)
{
	if (tests == NULL)
	{
		printf("Error occurs while trying to get access to memory to input data.\n");
		return ERROR;
	}
	printf("Please enter questions, 4 answers and number of right answer. \n");

	unsigned char retCode;
	unsigned int i, j;
	for (i = 0; i < num; ++i)
	{
		do
		{
			printf("%i question:  ", i + 1);
			gets(tests[i].question);

		} while (strlen(tests[i].question) == 0);


		for (j = 0; j < ANSWERS; ++j)
		{
			do
			{
				printf("%u answer:  ", j + 1);
				gets(tests[i].answers[j]);

			} while (strlen(tests[i].answers[j]) == 0);
		}


		do
		{
			printf("number of right answer: ");
			retCode = scanf("%u", &tests[i].rigth_answer);
			tests[i].rigth_answer -= 1; /*answer's counting starts from 1*/
			if (tests[i].rigth_answer < 0 || tests[i].rigth_answer > 4)
			{
				printf("Right answer must be within number of answers. \n");
				retCode = ERROR;
			}
			fflush(stdin); // Flush the input buffer
		} while (retCode == ERROR);
		tests[i].tested = 0;
	}
	return SUCCESS;
}



unsigned char Testing(struct test* tests, unsigned int num)
{
	if (tests == NULL)
	{
		printf("Error occurs while trying to get access to data to test questions.\n");
		return ERROR;
	}

	system("cls");

	unsigned int temp;
	unsigned int correctansw = 0, i = 0, j, n;
	unsigned int quantity;
	num >= ATTEMPT ? quantity = ATTEMPT : quantity = num; 

	printf("Let's check you knowledge.\nEnter answers for following question.\n");


	while (i < quantity)
	{
		j = rand() % num;
		if (tests[j].tested == 0)
		{
			tests[j].tested = 1;
		}
		else
		{
			continue;
		}

		++i;
		printf("%s\n", tests[j].question);
		printf("answers: \n");
		for (n = 0; n < ANSWERS; ++n)
		{
			printf("%u. %s\n", n+1, tests[j].answers[n]);
		}
		printf("\n");
		
		do 
		{
			printf("your answer: ");
			scanf("%u", &temp);
		} while (temp < 0 || temp > 4);
		
		temp -= 1; /*answer's counting starts from 1*/

		if (temp == tests[j].rigth_answer )
		{
			++correctansw;
			printf("good job! correct answer;) \n");
		}
		else
		{
			printf("sorry, that's wrong answer:(\n");
			printf("correct answer: %s\n", tests[j].answers[tests[j].rigth_answer]);
		}
	}

	printf("Percentage of correct answers is %0.2f percent \n", (float)correctansw / quantity * 100);
	return SUCCESS;
}

