#include <stdio.h>

/*    Copyright (C) 2007 Corby Schmitz
* 
*    License removed for readablity
*/

float addition (float foo, float bar){
	return foo + bar;
}

float subtraction (float foo, float bar){
	return foo - bar;
}

float multiplication (float foo, float bar){
	return foo * bar;
}

float division (float foo, float bar){
	return foo / bar;
}

screenOut(float value){
	printf("%.1f\n",value);
}

headerOut(float foo, char op, float bar){
	printf("%.1f %c %.1f\n", foo, op, bar);
}

//Arithmetic operations
main(){
	float op1 = 10.5;
	float op2 = 5.7;
	float result;
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
}


