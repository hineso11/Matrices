#include <iostream>
#include "matrix.h"

int main() {
	
	matrix matrix_a = matrix::from_csv("/Users/oliver/Desktop/a.csv");
	matrix matrix_b = matrix::from_csv("/Users/oliver/Desktop/b.csv");
	
	if (matrix_a == matrix_b) {
		
		cout << "Same";
	} else {
		
		cout << "Not same";
	}
	
	return 0;
}