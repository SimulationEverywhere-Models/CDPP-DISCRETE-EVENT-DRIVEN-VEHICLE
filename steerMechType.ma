[top]
components : steerMechType_a@SteerMechType

out : wheel_turn 
in : delta_angle

Link : delta_angle delta_angle@steerMechType_a
Link : wheel_turn@steerMechType_a wheel_turn

[steerMechType_a]
preparation : 00:00:15:000


