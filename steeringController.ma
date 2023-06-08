[top]
components : steeringController_a@SteeringController

out : delta_angle disp_info2 
in : turn_angle drive_straight act_ang_fb

Link : delta_angle@steeringController_a delta_angle
Link : act_ang_fb act_ang_fb@steeringController_a
Link : turn_angle turn_angle@steeringController_a
Link : drive_straight drive_straight@steeringController_a
Link : disp_info2@steeringController_a disp_info2

[steeringController_a]
preparation : 00:00:05:000


