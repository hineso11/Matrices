//
// Created by Oliver Hines on 22/07/2018.
//

#ifndef MATRICES_ROW_H
#define MATRICES_ROW_H

#include <iostream>
#include <vector>

using namespace std;

class row {
	
	private:
	vector<double> elements;
	
	public:
	
	explicit row(vector<double > elements) {
		
		this->elements = elements;
	};
	
	vector<double> get_elements () {
		
		return elements;
	}
	
	void set_element (long position, double value) {
		
		elements.at(position) = value;
	}
	
	double get_element (long position) {
		
		return elements.at(position);
	}

};

#endif //MATRICES_ROW_H
