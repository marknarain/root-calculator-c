
#include <stdio.h>
#include <string.h>
#include <malloc.h>

/*
Splits the entered number into pairs of two digits, the first element of the array shows the number of the following entries
x = 1234 --> [2, 12, 34]
x = 789  --> [2, 7, 89]
x = 7    --> [1, 7]
The lenght of the resulting array == number of integer
digits of the square root of x
*/

int* splitNumber(char* x) {

	int inputLen = (int)strlen(x);
	int arrayLen = (inputLen + 1) / 2;

	int* pR;
	//pR = (int*) malloc((arrayLen + 1) * sizeof(int));
	pR = (int*)calloc(arrayLen + 1, sizeof(int));

	if (pR == 0) {
		free(pR);
		return 0;
	}

	pR[0] = arrayLen;

	int ix;
	int ir;

	if ((inputLen % 2) == 0) {
		// len is an even number, start with first character
		ix = 0;
		ir = 1;
	}
	else {
		// len is odd (e.g. "456") so we have to take the first digit separately, and then continue with the loop to process the pairs
		ix = 1;
		ir = 2;
		char c = x[0];

		if ((c < '0') || (c > '9')) {
			free(pR);
			return 0;
		}

		pR[1] = c - '0';
	}

	while (ir < (arrayLen + 1)) {
		char c1 = x[ix];
		char c2 = x[ix + 1];

		if ((c1 < '0') || (c1 > '9') || (c2 < '0') || (c2 > '9')) {
			free(pR);
			return 0;
		}

		pR[ir] = (x[ix] - '0') * 10 + (x[ix + 1] - '0');
		ix = ix + 2;
		ir++;
	}
	
	return pR;
}

/*
Finds the root of the closest smaller square number.
x = 91    --> 9
x = 64    --> 8
x = 10    --> 3
Entered values must be < 100
*/

int rootOfFirstItem(int x) {

	int y;

	for (y = 9; x < (y * y); y--);

	return y;
}

// Subtracts the square of the first found Digit from the entered number

int firstStepSquareMinus(int x, int y) {
	
	int output = x - (y * y);

	return output;
}

/*
Uses a number x and the first found digit of the root
to calculate the next root.
*/

int rootDigitCalculator(int x, int y) {

	int a = y * 20;
	int b = x / a;
	a += b;

	while ((a * b) > x) {
		b--;
		a--;
	}

	return b;
}

/*
Calculates the root of number a and returns it as text
the parameter decimalPlaces defines how many decimal places after the comma
should be calculated.
*/

#define HDR_LEN 2

int* root(char* a, int decimalPlaces) {

	if (strlen(a) > 16) {
		return 0;
	}

	
	if ((a[0] == '-') || (decimalPlaces < 0)) {
		return 0;
	}
	
	int* pSplit = splitNumber(a);

	if (pSplit == 0) {
		return 0;
	}

	//The number of pairs gives us the digits before comma for the result
	int digitsBeforeComma = pSplit[0];  
	
	int allocAmount = decimalPlaces + digitsBeforeComma + HDR_LEN;
	int* outRoot = (int*)calloc(allocAmount, sizeof(int));
	
	if (outRoot == 0) {
		free(outRoot);
		return 0;
	}

	if (a[0] == '0') {
		outRoot[0] = 2;
		outRoot[1] = 2;
		outRoot[2] = 0;
		return outRoot;
	}

	outRoot[0] = decimalPlaces + digitsBeforeComma + HDR_LEN - 1;
	outRoot[1] = digitsBeforeComma + 1;
	
	int firstDigit = rootOfFirstItem(pSplit[1]);
	outRoot[2] = firstDigit;

	//c1 is needed everytime, when a new digit is calculated
	int c1 = firstStepSquareMinus(pSplit[1], firstDigit) * 100;

	int loopIndex = 0;

	int lenSplit = pSplit[0];
	bool firstRun = true;
	int d1 = 0;

	while (loopIndex < (allocAmount - HDR_LEN - 1)) {
		if (lenSplit > 1) {
			c1 += pSplit[loopIndex+HDR_LEN];
			lenSplit--;
		}
		if (firstRun == false) {
			firstDigit *= 10;
		}
		firstRun = false;
		
		firstDigit += d1;

		d1 = rootDigitCalculator(c1, firstDigit);
		
		if ((loopIndex + HDR_LEN + 1) > (allocAmount - HDR_LEN + 1)) {
			break;
		}

		outRoot[loopIndex+3] = d1;

		c1 = (c1 - ((20 * firstDigit + d1) * d1)) * 100;	

		if (c1 == 0) {
			outRoot[0] = digitsBeforeComma + 1;
			break;
		}

		loopIndex++;
	}

	return outRoot;
}