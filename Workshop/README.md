
# Servos and Stepper Motor controls using Arduino
## INDEX
1. Overview
2. PART1: Servos
3. Servos: An introduction
4. Servos: Use cases
5. Servos: Coding and controls
6. Servos: Cool Experiment
8. PART2: Stepper Motors
9. Stepper Motors: An introduction
10. Stepper Motors: Use cases
11. Stepper Motors: Coding and controls
12. Stepper Motors: Cool Experiment


## Servos: An introduction

At its core, a servo motor is a type of motor that can rotate or push parts of a machine with high precision. The key characteristics that set servo motors apart from other types of motors are their control, precision, and feedback.

The unique aspect of servo motors is their use of a "closed-loop" control system. In simple terms, a closed-loop system means that the motor continually receives and responds to feedback about its position or speed, allowing it to make precise adjustments as necessary.

This feedback mechanism typically involves a potentiometer or an encoder that is connected to the motor's output shaft. This device can detect the shaft's current position or speed and send this information back to the motor's control circuit. 

The control circuit then compares the actual position or speed of the shaft with the desired position or speed (as specified by the input signal). If there's a difference, the control circuit will adjust the power to the motor to correct it.

__Factoid__:
The word "servo" comes from the Latin "servus", meaning slave. A servo motor is effectively a slave to its input signals, adjusting its speed, position, or torque based on the instructions it receives.



 Reference: https://howtomechatronics.com/how-it-works/how-servo-motors-work-how-to-control-servos-using-arduino/


### Types of Servos:
 Certainly! There are several types of servo motors, each with unique characteristics and suited to specific applications. Here are some of the most common types:

**1. Standard Servos:** These are the most common types of servo motors. They have a limited rotation angle, typically around 180 degrees. You'll find these in many hobbyist applications like model airplanes or simple robotic arms. These servos have a physical stop built into the gear mechanism to prevent turning beyond these limits.

**2. Continuous Rotation Servos:** Unlike standard servos, continuous rotation servos can rotate 360 degrees continuously in either direction. They are often used for driving wheels on robots because they can turn all the way around. Rather than controlling position, as with standard servos, a command to a continuous rotation servo is interpreted as a speed and direction.

**3. Winch Servos:** These are similar to standard servos, but they have an extended rotation range, typically around 270 degrees. These servos are often used in applications where a larger range of motion is required, such as steering a remote-controlled boat or car.

**4. Linear Servos:** Instead of a rotary actuator, these servos have a linear actuator. This means they move in a straight line rather than rotating. These types of servos are often used in applications where linear motion is required, such as moving a control surface in a straight line.

**5. Large Scale or Giant Servos:** These are high power servos designed for large scale models and other high-stress applications. They provide the same functionality as a standard servo but can deliver much higher torque.

Remember, different servo types require different control signals and power requirements, so always ensure the servo you choose is compatible with your Arduino and the rest of your hardware.



## Servos: Use cases

Servo motors controlled by Arduino find a wide range of applications in various domains due to their precision and control. Here are some key use cases:

**1. Robotics:** In the field of robotics, servos are extensively used. They can be found in robotic arms, legs, or heads to control precise movements. An Arduino can be used to control these servos, allowing you to program complex movements and actions.

**2. Drones and RC Vehicles:** Servo motors are often used in drones and remote-controlled vehicles for steering control, adjusting flight surfaces, or controlling camera gimbal systems. An Arduino can provide the necessary control signals to these servos, making it an ideal choice for hobbyists and professionals alike.

**3. Automation Systems:** In automated systems like home automation or industrial automation, servo motors can be used for a variety of tasks, such as opening or closing valves, adjusting light fixtures, or moving parts in a production line. An Arduino can control these actions based on various sensor inputs.

**4. Interactive Art Installations:** Servo motors controlled by Arduino have become popular in the world of interactive art. They can be used to create moving sculptures, interactive displays, or sound installations, where the motion of the servo motors is controlled by audience interaction.


**5. Animatronics:** In the world of film and entertainment, servos are extensively used in animatronics to create lifelike movements. Arduino can be used to control these servos, making it easier to program and synchronize complex movements.

These examples illustrate just a few of the many possibilities for servo motors controlled by Arduino. With creativity and programming, the applications are virtually endless.


## Servos: Coding and controls

###We focus on regular 180 degree servos first:

The operation of a servo motor is managed by transmitting a sequence of pulses via the signal wire. The control signal should ideally have a frequency of 50Hz, meaning a pulse should be emitted every 20 milliseconds. The angular positioning of the servo is determined by the duration of the pulse. Typically, these servos have the capacity to rotate up to 180 degrees due to their physical constraints on movement.


###Continuous rotation servos:

Continuous rotation servo motors are regulated by a sequence of pulses sent through the signal line. The frequency of the control signal should maintain at 50Hz, which equates to a pulse being produced every 20 milliseconds. Unlike standard servos, the pulse width for a continuous rotation servo does not specify a position, but instead dictates the speed and direction of rotation. These servos, contrary to standard ones, have the ability to rotate without any physical limitations, thereby achieving full 360-degree rotation in either direction.


Arduino code and connections:





