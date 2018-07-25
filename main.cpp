#include <iostream>
#include "matrix.h"

int main() {
	
	matrix matrix_a = matrix::from_csv("/Users/oliver/Desktop/a.csv");
	matrix matrix_b = matrix::from_csv("/Users/oliver/Desktop/b.csv");
	
	matrix result = matrix_a * matrix_b;
	
	cout << result.to_string();
	
	return 0;
}