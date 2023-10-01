/*
Andrew Glenn
Homework 1
Question 9: implementing the neural network
*/

#include <iostream> //include input ourput library
#include <math.h> //include math library
#include <vector> //include vector library

using namespace std; //using standard library

double dot_product(vector<double> a,vector<double> b) { //dot product function for two vectors (from question 4)
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

double sigmoid(double z) { //function for Sigmoid (from question 5)
    double result = 1/(1+exp(-z)); //finding Sigmoid
    return result; //returning Sigmoid value
}

int main() {
    string model[4] = {"SF50 Vision", "208 Caravan", "Aero L-29 Delfin", "AT-802U"}; //airplane model names
    double approach_speed[4] = {87, 79, 92, 91}; //approach speeds
    double wingspan[4] = {38.67, 52.08, 33.75, 59.25}; //wingspans
    double MTOW[4] = {6, 8, 7.804, 16}; //maximum takeoff weights
    int engine_type[4]; //engine type results
    string string_engine_type[4];
    vector<double> w{0.135603, -0.287251, -0.00492586}; //weights from question 8
    vector<double> x{0, 0, 0}; //initializing x (with dummy values)
    double y_predict; //y prediction value
    
    for (int i = 0; i < 4; i++) { //loop for each aircraft model
        x[0] = approach_speed[i]; //adding approach speed to x
        x[1] = wingspan[i]; //adding wignspan to x
        x[2] = MTOW[i]; //adding MTOW to x
        y_predict = sigmoid(dot_product(w, x)); //finding y prediction
        if (y_predict > 0.5) {
            engine_type[i] = 1; //setting engine type to jet
            string_engine_type[i] = "jet"; //string engine type to jet
            cout << model[i] << ": " << string_engine_type[i] << endl; //outputting engine type
        }
        else {
            engine_type[i] = 0; //setting engine type to turboprop
            string_engine_type[i] = "turboprop"; //string engine type to turboprop
            cout << model[i] << ": " << string_engine_type[i] << endl; //outputting engine type
        }
    }
}

