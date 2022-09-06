// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot {

  WPI_VictorSPX leftMaster {1};
  WPI_VictorSPX leftSlave {3};

  WPI_VictorSPX rightMaster {2};
  WPI_VictorSPX rightSlave {4};

  frc::DifferentialDrive m_robotDrive{leftMaster, rightMaster};
  frc::Joystick m_Joystick{0};

 public:
  void RobotInit() override {
    rightMaster.SetInverted(true);
    rightSlave.SetInverted(true);

    rightSlave.Follow(rightMaster);
    leftSlave.Follow(leftMaster);
  }

  void TeleopPeriodic() override {
    m_robotDrive.ArcadeDrive(-m_Joystick.GetY(), m_Joystick.GetX());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
