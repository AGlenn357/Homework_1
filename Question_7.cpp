/*
Andrew Glenn
Homework 1
Question 7: creating gradient weights and update weights function
*/

#include <iostream> //include input ourput library
#include <iomanip> //include input output manipulation library
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

vector<double> gradient_weights(vector<double> w, vector<double> x, double y) { //function for gradient weights
    vector<double> dwi;
    double wx_dot = dot_product(w,x); //finding dot product of w and x
    for (int i = 0; i < w.size(); i++) { //for each value in weights
        dwi.push_back(2*(sigmoid(wx_dot)-y)*(sigmoid(wx_dot)*(1-sigmoid(wx_dot)))*x[i]); //adding dwi value to vector
    }
    return dwi; //returning gradient weight vector
}
    
vector<double> update_weights(vector<double> w, vector<double> dw, double alpha) { //function to update weights
    for (int i = 0; i < w.size(); i++) { //for each value in weights
        w[i] = w[i] - alpha*dw[i]; //new weight value
    }
    return w; //returning new weights
}

int main() {
    double y = 1; //y value
    vector<double> w{0.0001, 0.0001, 0.0001}; //initializing weights
    vector<double> x{124, 31.89, 20.945}; //initializing x values
    double alpha = 0.001; //initiallzing alpha value (learning rate)
    vector<double> dw = gradient_weights(w, x, y); //calling gradient weights
    w = update_weights(w, dw, alpha); //calling update weights function
    cout << "dw = ["; //outputting start of dw
    for (int i = 0; i < dw.size(); i++) { //for each element in dw
        cout << dw[i]; //output element value
        if (i != dw.size() -1) { //if not the last element
            cout << ", "; //add comma and space
        }
    }
    cout << "]" << endl; //moving to new line
    cout << "w = ["; //outputting start of w
    for (int i = 0; i < w.size(); i++) { //for each elemnt w
        cout << w[i]; //output element value
        if (i != dw.size() -1) { //if not the last element
            cout << ", "; //add comma and space
        }
    }
    cout << "]" << endl; //moving to new line
}

