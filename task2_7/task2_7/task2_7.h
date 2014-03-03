#include "stdafx.h"

/*maximum length of characters for questions or answers*/
const  unsigned int LEN = 40;

const unsigned int ANSWERS = 4;

struct test
{
	char question[LEN];
	char answers[ANSWERS][LEN];
	unsigned int rigth_answer;
	unsigned int tested;

};

/*displays some general information about program*/
void Interface();

/*checking entered data and return 0 if type doesn't match requirements*/
unsigned char Type_checking(unsigned char retCode, int val);

/*input coordinates of space points into list of points*/
unsigned char Input(struct test* tests, unsigned int num);

/*show 5 questions from tests and check entered answers, count number of right answers*/
unsigned char Testing(test* tests, unsigned int num);