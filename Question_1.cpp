/*
Andrew Glenn
AERSP 424
Homework 1
Question 1: Determining the roll rate of an aircraft
*/

#include <iostream> //include input output library
#include <string> //include string library
#include <iomanip> //include input output manipulator library

using namespace std; //using standard library

int main() {
    float Lp = 0.33; //Lp value of plane
    float Ldelta = -0.75; //Ldelta value of plane
    double P = 1; //roll rate (initial value 1)
    int delta; //elevator deflection value
    double P0 = 1; //initial rolling rate
    double P_dot; //time derivative of roll rate
    double time; //time variable
    
    
    for (int i = 1; i <= 500; i++) { //loop from t = 0 to t = 5
        if (i <= 200) {
            delta = 1; //ailerion delfection value when t <= 2 s
        }
        else {
            delta = 0; //ailerion delfection value when t > 2 s
        }
        P_dot = Lp*P+Ldelta*delta; //finding roll rate derivative value
        P = P0+P_dot*0.01; //new roll value at time t+1
        P0 = P; //setting initial roll rate to current roll rate (for next iteration)
        time = i*0.01; //time of specific iteration
        cout << "Time: " << fixed << setprecision(2) << time << " s Roll Rate: " << P << endl; //outputting time and roll rate
    }
    return 0;
}

