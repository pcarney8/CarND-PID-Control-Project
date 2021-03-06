#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
    Kp = _Kp;
    Ki = _Ki;
    Kd = _Kd;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    i_error += cte;
    p_error = cte;
}

double PID::TotalError() {
    //returns steering angle becuase we have all the info here
    double steer_value = -Kp * p_error - Kd * d_error - Ki * i_error;
    steer_value = steer_value < -1 ? -1 : steer_value;
    steer_value = steer_value > 1 ? 1 : steer_value;

    return steer_value;
}
