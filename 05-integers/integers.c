#include <stdio.h>
#include <stdlib.h>

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

//addition subroutine
int addition (int foo, int bar){
	return foo + bar;
}

//subtraction subroutine
int subtraction (int foo, int bar){
	return foo - bar;
}

//multiplication subroutine
int multiplication (int foo, int bar){
	return foo * bar;
}

//division subroutine
int division (int foo, int bar){
	return foo / bar;
}

//mod operator subroutine
int modulo (int foo, int bar){
	return foo % bar;
}

//print out calculation values
void screenOut(int value){
	printf("%d\n",value);
}

//print out output header details on the operation to be done
void headerOut(int foo, char op, int bar){
	printf("%d %c %d\n", foo, op, bar);
}

//Arithmetic operations
void main(){
	int op1 = 10;
	int op2 = 5;
	int result;
	headerOut(op1, '+', op2);
	result = addition(op1, op2);
	screenOut(result);
	headerOut(op1, '-', op2);
	result = subtraction(op1, op2);
	screenOut(result);
	headerOut(op1, '*', op2);
	result = multiplication(op1, op2);
	screenOut(result);
	headerOut(op1, '/', op2);
	result = division(op1, op2);
	screenOut(result);
	headerOut(op1, '%', op2);
	result = modulo(op1, op2);
	screenOut(result);
}
