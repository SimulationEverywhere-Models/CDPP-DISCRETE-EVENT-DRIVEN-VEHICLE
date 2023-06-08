[top]
components : motor_a@Motor brakes_a@Brakes velocitySensor_a@VelocitySensor

out : mot_rpm act_rpm_fb
in : mot_torq br_int act_rpm

Link : mot_torq mot_torq@motor_a
Link : br_int br_int@brakes_a
Link : act_rpm act_rpm@velocitySensor_a
Link : mot_rpm@motor_a mot_rpm
Link : act_rpm_fb@velocitySensor_a act_rpm_fb

[motor_a]
preparation : 00:00:15:000

[brakes_a]
preparation : 00:00:15:000

[velocitySensor_a]
preparation : 00:00:05:000


