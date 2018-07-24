//
// Created by Oliver Hines on 22/07/2018.
//

#ifndef MATRICES_MATRIX_H
#define MATRICES_MATRIX_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "row.h"

using namespace std;

class matrix {
	
	private:
	
	// MARK: Variables
	vector<row> rows;
	long num_columns;
	
	// MARK: Methods
	// Method to find the highest number of digits of element in matrix
	// so that when displaying the matrix, enough space is allocated
	long get_digit_num () {
		
		long highestNumber = 0;
		
		for (row row1: rows) {
			
			for (double element: row1.get_elements()) {
			
				string numberString = std::to_string(element);
				
				if (numberString.length() > highestNumber) {
					highestNumber = numberString.length();
				}
			}
		}
		
		return highestNumber;
	}
	
	string center_element (double element, long digits) {
		
		string elementString = std::to_string(element);
		if (elementString.length() < digits) {
			
			long charsToAdd = digits - elementString.length();
			for (int i = 0; i <= charsToAdd; i++) {
				
				if (i % 2 == 0) {
					
					elementString.insert(0, " ");
				} else {
					elementString += " ";
				}
				
			}
		}
		
		return elementString;
	}
	
	public:
	
	// MARK: Constructors
	explicit matrix(vector<row> rows) {
		
		this->rows = rows;
	}
	
	// Method to create blank matrix of certain dimensions
	static matrix create_blank (long numRows, long numColumns) {
		
		vector<row> rows;
		
		for (int i = 0; i < numRows; i++) {
			
			vector<double> elements;
			
			for (int j = 0; j < numColumns; j++) {
				
				elements.push_back(0);
			}
			
			row newRow = row(elements);
			rows.push_back(newRow);
		}
		
		return matrix(rows);
	}
	
	// Method to create a new matrix from the data in a csv file
	static matrix from_csv (const string &filePath) {
		
		// Array to hold the rows as they are read in
		vector<row> rows;
		
		ifstream file (filePath);
		string line;
		
		// To store the number of columns in each read in row
		long numColumns = -1;
		
		// Loop through every line in the file
		while (std::getline(file, line)) {
		
			vector<double> elements;
			
			stringstream stream(line);
			double element;
			
			// Loop through every character in line
			while (stream >> element) {
				// Put the element in the vector of elements
				elements.push_back(element);
				// If the next character is not one of the elements, then discard it
				if (stream.peek() == ',' || stream.peek() == ' ')
					stream.ignore();
			}
			// Check that each row has the same number of elements as last
			if (numColumns == -1) {
				numColumns = elements.size();
			} else {
				if (elements.size() != numColumns) throw invalid_argument("Error: Number of columns must be the same in each row");
			}
			
			// Create the new row from the read in elements
			row newRow = row(elements);
			// Add to vector of rows
			rows.push_back(newRow);
		}
		
		// Create actual matrix from rows
		matrix newMatrix = matrix(rows);
		// Set the number of columns in the new matrix
		newMatrix.num_columns = numColumns;
		
		return newMatrix;
	}
	
	// MARK: Methods
	
	long row_count () const {
		
		return rows.size();
	}
	
	long column_count () const {
		
		return num_columns;
	}
	
	// Method to format the contents of the matrix into a printable string
	string get_output () {
		
		string output;
		
		// Find the highest number of digits in elements to allocate space
		long highest = get_digit_num() + 1;
		
		for (row currentRow: rows) {
			output += "| ";
			
			for (double element: currentRow.get_elements()) {
				
				output += center_element(element, highest);
				output += " ";
			}
			output.erase(output.length() - 1);
			output.pop_back();
			output += " |";
			output += "\n";
		}
		
		return output;
	}
	
	// MARK: Operators
	
	// Addition
	matrix operator + (matrix& b) {
		
		matrix result = create_blank(this->row_count(), this->column_count());
	
		// Check that the matrices are conformable for addition
		if (this->column_count() == b.column_count() & this->row_count() == b.row_count()) {
			// They are conformable, perform addition
			
			// Loop through each row then element
			for (long i = 0; i < this->row_count(); i++) {
				
				for (long j = 0; j < this->column_count(); j++) {
					
					// Create and set new value for element
					double newValue = this->rows.at(i).get_element(j) + b.rows.at(i).get_element(j);
					result.rows.at(i).set_element(j, newValue);
				}
			}
			
		} else {
			// They are not conformable, throw error
			throw invalid_argument("Error: Matrix is not conformable for addition");
		}
		
		return result;
	}
	
	// Subtraction
	matrix operator - (matrix& b) {
		
		matrix result = create_blank(this->row_count(), this->column_count());
		
		// Check that the matrices are conformable for addition
		if (this->column_count() == b.column_count() & this->row_count() == b.row_count()) {
			// They are conformable, perform addition
			
			// Loop through each row then element
			for (long i = 0; i < this->row_count(); i++) {
				
				for (long j = 0; j < this->column_count(); j++) {
					
					// Create and set new value for element
					double newValue = this->rows.at(i).get_element(j) - b.rows.at(i).get_element(j);
					result.rows.at(i).set_element(j, newValue);
				}
			}
			
		} else {
			// They are not conformable, throw error
			throw invalid_argument("Error: Matrix is not conformable for subtraction");
		}
		
		return result;
	}
	
	
};

#endif //MATRICES_MATRIX_H
