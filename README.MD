**Mechanical Brake Add on for Ardurover**

My ardurover was lacking a brake. The ESC that I was using did not support reverse throttle nor braking due that it was for an electric monster truck. If you reverse while going on high speeds with a high power motor there is a good chance that you'll destroy the gearbox... Therefore it lacks reverse.   

This code monitors the throttle signal coming from APM 2.8 and checks for negative throttle (which indicates brake request). When a negative throttle is detected the arduino triggers the brake with the servo.   


This code will also include snipplets for some lights and sensors in near future...   
