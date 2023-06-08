[top]
components : velocitySensor_a@VelocitySensor

out : act_rpm_fb 
in : act_rpm

Link : act_rpm act_rpm@velocitySensor_a
Link : act_rpm_fb@velocitySensor_a act_rpm_fb

[velocitySensor_a]
preparation : 00:00:05:000


