[top]
components : steeringSensor_a@SteeringSensor steerMechType_a@SteerMechType 

out : wheel_turn act_ang_fb 
in : delta_angle act_wheel_angle 

Link : delta_angle delta_angle@steerMechType_a
Link : wheel_turn@steerMechType_a wheel_turn
Link : act_wheel_angle act_wheel_angle@steeringSensor_a
Link : act_ang_fb@steeringSensor_a act_ang_fb

[steeringSensor_a]
preparation : 00:00:05:000

[steerMechType_a]
preparation : 00:00:15:000


