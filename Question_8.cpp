/*
Andrew Glenn
Homework 1
Question 8: training the artificial neural network to classify airplanes
*/

#include <iostream> //include input ourput library
#include <math.h> //include math library
#include <vector> //include vector library
#include <string> //inlcude string library

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

vector<double> gradient_weights(vector<double> w, vector<double> x, double y) { //function for gradient weights (from question 7)
    vector<double> dwi;
    double wx_dot = dot_product(w,x); //finding dot product of w and x
    for (int i = 0; i < w.size(); i++) { //for each value in weights
        dwi.push_back(2*(sigmoid(wx_dot)-y)*(sigmoid(wx_dot)*(1-sigmoid(wx_dot)))*x[i]); //adding dwi value to vector
    }
    return dwi; //returning gradient weight vector
}
    
vector<double> update_weights(vector<double> w, vector<double> dw, double alpha) { //function to update weights (from question 7)
    for (int i = 0; i < w.size(); i++) { //for each value in weights
        w[i] = w[i] - alpha*dw[i]; //new weight value
    }
    return w; //returning new weights
}

int main() {
    string model[8] = {"M-346 Master", "AT-402B", "MB-236", "AT-502B", "MB-339", "AT-602", "Aero L-159 Alca", "AT-504"}; //models of aircraft
    double approach_speed[8] = {124, 74, 103, 77, 104, 92, 130, 73}; //approach speeds of aircraft
    double wingspan[8] = {31.89, 51.08, 34.67, 52.00, 35.63, 56.00, 31.29, 52.00}; //wingspan of aircraft
    double MTOW[8] = {20.945, 9.170, 8.300, 9.400, 13.000, 12.500, 17.637, 9.600}; //maximum takewoff weight of aircraft
    double engine_type[8] = {1, 0, 1, 0, 1, 0, 1, 0}; //engine type (turboprop: 0, jet: 1)
    vector<double> w{0.0001, 0.0001, 0.0001}; //initializing weights
    double alpha = 0.001; //initializing alpha (learning rate)
    vector<double> x{0, 0, 0}; //initializing x (with dummy values)
    double y;
    vector<double> dw; //initializing dw
    
    for (int i = 0; i < 1000; i++) { //loop with a 1000 iterations
        for (int n = 0; n < 8; n++) { //loop for each aircraft model
            x[0] = approach_speed[n]; //adding approach speed to x
            x[1] = wingspan[n]; //adding wignspan to x
            x[2] = MTOW[n]; //adding MTOW to x
            y = engine_type[n]; //setting y to engine type
            dw = gradient_weights(w, x, y); //finding dw
            w = update_weights(w, dw, alpha); //updating weights
        }
    }
    cout << "w = ["; //outputting start of w
    for (int i = 0; i < w.size(); i++) { //for each elemnt w
        cout << w[i]; //output element value
        if (i != dw.size() -1) { //if not the last element
            cout << ", "; //add comma and space
        }
    }
    cout << "]" << endl; //moving to new line
}

