#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this -> Kp = Kp;
    this -> Ki = Ki;
    this -> Kd = Kd;
}

void PID::UpdateError(double cte) {
//TODO: double check this
    d_error = cte - p_error;
    i_error += cte;
    p_error = cte;
}

double PID::TotalError() {
//returns steering angle becuase we have all the info here

    return -Kp * p_error - Kd * d_error - Ki * i_error;


}

/*
def run(robot, tau_p, tau_d, tau_i, n=100, speed=1.0):
  x_trajectory = []
  y_trajectory = []
  prev_cte = robot.y
  for i in range(n):
      cte = robot.y
      cte_d = cte - prev_cte
      prev_cte = cte
      sum_cte = sum(y_trajectory) + cte
      steer = -tau_p * cte - tau_d * cte_d - tau_i * sum_cte
//                  robot.move(steer, speed)
//                  x_trajectory.append(robot.x)
//                  y_trajectory.append(robot.y)
//              return x_trajectory, y_trajectory
*/