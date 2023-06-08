[top]
components : steeringSensor_a@SteeringSensor

out : act_ang_fb 
in : act_wheel_angle 

Link : act_wheel_angle act_wheel_angle@steeringSensor_a
Link : act_ang_fb@steeringSensor_a act_ang_fb

[steeringSensor_a]
preparation : 00:00:05:000


