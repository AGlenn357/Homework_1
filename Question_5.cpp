/*
Andrew Glenn
Homework 1
Question 5: finding the Sigmoid and Sigmoid gradient
*/

#include <iostream> //include input ourput library
#include <iomanip> //include input output manipulation library
#include <math.h> //including math library

using namespace std; //using stadard library

double sigmoid(double z) { //function for Sigmoid
    double result = 1/(1+exp(-z)); //finding Sigmoid
    return result; //returning Sigmoid value
}

double gradient_sigmoid(double sig) { //function to calculate Sigmoid gradient
    double result = sig*(1-sig); //finding Sigmoid gradient
    return result; //returning Sigmoid gradient value
}

int main() {
    double z = 0.0176836; //given z value
    double sigmoid_val = sigmoid(z); //calling Sigmoid function of z
    double sigmoid_grad_val = gradient_sigmoid(sigmoid_val); //calling gradient Sigmoid value
    cout << "The Sigmoid is " << fixed << setprecision(6) << sigmoid_val << endl << "The Sigmoid gradient is " << sigmoid_grad_val << endl; //outputting Sigmoid value and Sigmoid gradient value
}

