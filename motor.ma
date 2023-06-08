[top]
components : motor_a@Motor

out : mot_rpm 
in : mot_torq

Link : mot_torq mot_torq@motor_a
Link : mot_rpm@motor_a mot_rpm

[motor_a]
preparation : 00:00:15:00


