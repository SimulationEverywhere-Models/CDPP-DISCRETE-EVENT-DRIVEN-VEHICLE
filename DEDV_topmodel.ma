[top]
components : display_a@Display controlUnit_c movementModel_c steeringModel_c

out : mot_rpm wheel_turn
in : accel decel emerg_brk turn_angle drive_straight act_wheel_angle act_rpm

Link : accel accel@controlUnit_c
Link : decel decel@controlUnit_c
Link : emerg_brk emerg_brk@controlUnit_c
Link : turn_angle turn_angle@controlUnit_c
Link : drive_straight drive_straight@controlUnit_c
Link : act_wheel_angle act_wheel_angle@steeringModel_c
Link : act_rpm act_rpm@movementModel_c

Link : mot_rpm@movementModel_c mot_rpm
Link : wheel_turn@steeringModel_c wheel_turn
   

[controlUnit_c]
components : movementController_a@MovementController steeringController_a@SteeringController

out : mot_torq br_int delta_angle
in : accel decel emerg_brk turn_angle drive_straight act_rpm_fb act_ang_fb

Link : accel accel@movementController_a
Link : decel decel@movementController_a
Link : emerg_brk emerg_brk@movementController_a
Link : act_rpm_fb act_rpm_fb@movementController_a
Link : turn_angle turn_angle@steeringController_a
Link : drive_straight drive_straight@steeringController_a
Link : act_ang_fb act_ang_fb@steeringController_a


Link : delta_angle@steeringController_a delta_angle
Link : mot_torq@movementController_a mot_torq
Link : br_int@movementController_a br_int


[movementModel_c]
components : motor_a@Motor brakes_a@Brakes velocitySensor_a@VelocitySensor

out : mot_rpm act_rpm_fb
in : act_rpm mot_torq br_int

Link : mot_torq mot_torq@motor_a
Link : br_int br_int@brakes_a
Link : act_rpm act_rpm@velocitySensor_a

Link : mot_rpm@motor_a mot_rpm
Link : act_rpm_fb@velocitySensor_a act_rpm_fb


[steeringModel_c]
components : steerMechType_a@SteerMechType steeringSensor_a@SteeringSensor

out : act_ang_fb wheel_turn
in : delta_angle act_wheel_angle

Link : delta_angle delta_angle@steerMechType_a
Link : act_wheel_angle act_wheel_angle@steeringSensor_a

Link : act_ang_fb@steeringSensor_a act_ang_fb
Link : wheel_turn@steerMechType_a wheel_turn


[display_a]
preparation : 00:00:05:00

[movementController_a]
preparation : 00:00:05:00

[steeringController_a]
preparation : 00:00:05:00

[motor_a]
preparation : 00:00:15:00

[brakes_a]
preparation : 00:00:15:00

[velocitySensor_a]
preparation : 00:00:05:00

[steerMechType_a]
preparation : 00:00:15:00

[steeringSensor_a]
preparation : 00:00:05:00


