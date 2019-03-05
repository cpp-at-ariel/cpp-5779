/**
 * Implementation of factorial function.
 * Contains a subtle bug.
 */

int factorial(int number) { 
	return number <= 1 ? number : factorial(number - 1) * number; 
}
