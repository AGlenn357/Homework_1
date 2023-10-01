/*
Andrew Glenn
Homework 1
Question 4: dot product function
*/

#include <vector> //include vector library
#include <iostream> //include input ourput library
#include <iomanip> //include input output manipulation library

using namespace std;

double dot_product(vector<double> a,vector<double> b) { //dot product function for two vectors
    double result = 0; //result is the answer of the dot product
    if (a.size() == b.size()) { //if the vectors are the same size
        for (int i = 0; i < a.size(); i++) { //over the length of the vectors
            result = result + a[i]*b[i]; //adding multiplication of corresponding elements together
        }
        return result; //return dot product value
    }
    else { //if the vectors are not the same size dot product can't be computed
        cout << "Error: the vectors must be the same size" << endl; //stating that dot product can't be computed
        return 0; //returning zero
    }
}

int main(){
    vector<double> w{0.0001, 0.0001, 0.0001}; //initializing w vector
    vector<double> x{124, 31.89, 20.945}; //initializing v vector
    double answer = dot_product(w,x); //calling dot product function
    cout << "The dot product is " << fixed << setprecision(7) << answer << endl; //outputting dot product
}

