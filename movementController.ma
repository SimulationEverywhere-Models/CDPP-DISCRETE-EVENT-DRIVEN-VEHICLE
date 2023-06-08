[top]
components : movementController_a@MovementController 

out : br_int mot_torq disp_info1 
in : act_rpm_fb accel decel emerg_brk

Link : act_rpm_fb act_rpm_fb@movementController_a
Link : accel accel@movementController_a
Link : decel decel@movementController_a
Link : emerg_brk emerg_brk@movementController_a
Link : br_int@movementController_a br_int
Link : mot_torq@movementController_a mot_torq
Link : disp_info1@movementController_a disp_info1

[movementController_a]
preparation : 00:00:05:000


