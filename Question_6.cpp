/*
Andrew Glenn
Homework 1
Question 6: creating a gradient cost function
*/

#include <iostream> //include input ourput library
#include <iomanip> //include input output manipulation library
#include <math.h> //including math library

using namespace std; //using standard library

double gradient_cost(double y_predict, double y ) { //gradient cost function
    double result = 2*(y_predict - y); //finding gradient cost function
    return result; //returning result
}

int main() {
    double y_predict = 0.504421; //y prediction value
    double y = 1; //y value
    double answer = gradient_cost(y_predict, y); //calling gradient cost function
    cout << "The gradient cost is " << answer << endl; //outputting the gradient cost
}

