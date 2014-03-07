/**
* @file		task2_7.h
* @brief	header file for task2_7.cpp
defines data types and prototypes for functions used in task2_7.cpp
*/

#include "stdafx.h"


const  unsigned int LEN = 40;	/*maximum length of characters for questions or answers*/

const unsigned int ANSWERS = 4; /*number of answers for question*/

/*defines data type for holding question, it's answers, number of correct answer and mark that shows if question was tested*/
struct test
{
	char question[LEN];
	char answers[ANSWERS][LEN];
	unsigned int rigth_answer;
	unsigned int tested;

};


/**
* @brief				This function displays general information about program to users
* @param	void
* @return	void
*/
void Interface();



/**
* @brief						Checking if data match requirements set to that data types or functions return values

* @param	[in]				unsigned char retCode - return value of other functions for checking if functions ended properly
			[in]				int val - number for checking if it's negative or zero
* @return	unsigned char		Return ERROR if data doesn't match requirements
								Return SUCCESS if inputed data match requirements
*/
unsigned char Type_checking(unsigned char retCode, int val);



/**
* @brief					Function for input questions and their answers in database
* @param	[in/out]		struct test* tests - pointer to array of structures that holds questions and answers
			[in]			unsigned int num - the number of questions in database
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if data was inputed
*/
unsigned char Input(struct test* tests, unsigned int num);



/**
* @brief					Function shows questions and their answers,
							checks user answer and if it's wrong, shows correct answer,
							after test shows the percentage of right answers
* @param	[in]			struct test* tests - pointer to array of structures that holds questions and answers
			[in]			unsigned int num - the number of questions in database
* @return	unsigned char	Return ERROR if pointer to array of structures is NULL
							Return SUCCESS if test was conducted 
*/
unsigned char Testing(struct test* tests, unsigned int num);