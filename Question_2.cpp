/*
Andrew Glenn
AERSP 424
Homework 1
Question 2: Determining the roll rate of an aircraft with gain controller
*/

#include <iostream> //include input output library
#include <string> //include string library
#include <iomanip> //include input output manipulator library

using namespace std; //using standard library

int main() {
    float Lp = 0.33; //Lp value of plane
    float Ldelta = -0.75; //Ldelta value of plane
    double Pt1; //roll rate at time t+1
    double delta; //aileron deflection value
    double Pt = 1; //roll rate at time t
    double P_dot; //time derivative of roll rate
    double time; //time variable
    double K = -1.27; //gain value in controller
    
    
    for (int i = 1; i <= 500; i++) { //loop from t = 0 to t = 5
        delta = -K*Pt; //aileron deflection angle
        P_dot = Lp*Pt+Ldelta*delta; //finding roll rate derivative value
        Pt1 = Pt+P_dot*0.01; //new roll rate value at time t+1
        Pt = Pt1; //setting initial roll rate to current roll rate (for next iteration)
        time = i*0.01; //time of specific iteration
        cout << "Time: " << fixed << setprecision(2) << time << " s Roll Rate: " << Pt1 << endl; //outputting time and roll rate
    }
    return 0;
}

