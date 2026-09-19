#include <webots/Robot.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Motor.hpp>
#include <iostream>

using namespace std;
using namespace webots;

int main(int argc, char **argv) {

  Robot *robot = new Robot();

  int timeStep = (int)robot->getBasicTimeStep();

  Motor *motor = robot->getMotor("motor");
  PositionSensor *ps = robot->getPositionSensor("encoder");

  ps->enable(timeStep);

  // Dejar el motor completamente libre
  motor->setTorque(0.0);

  while (robot->step(timeStep) != -1) {

    double val = ps->getValue();
    cout << "Posicion actual: " << val << endl;
  }

  delete robot;
  return 0;
}
