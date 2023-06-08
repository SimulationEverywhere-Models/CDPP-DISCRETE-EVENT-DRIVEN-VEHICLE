[top]
components : movementController_a@MovementController steeringController_a@SteeringController

out : mot_torq br_int disp_info1 disp_info2 delta_angle 
in : accel decel emerg_brk act_rpm_fb turn_angle drive_straight act_ang_fb

Link : act_rpm_fb act_rpm_fb@movementController_a
Link : accel accel@movementController_a
Link : decel decel@movementController_a
Link : emerg_brk emerg_brk@movementController_a
Link : act_ang_fb act_ang_fb@steeringController_a
Link : turn_angle turn_angle@steeringController_a
Link : drive_straight drive_straight@steeringController_a
Link : br_int@movementController_a br_int
Link : mot_torq@movementController_a mot_torq
Link : disp_info1@movementController_a disp_info1
Link : disp_info2@steeringController_a disp_info2
Link : delta_angle@steeringController_a delta_angle

[movementController_a]
preparation : 00:00:05:000

[steeringController_a]
preparation : 00:00:05:000


