# Traffic Light Control System with Time Display

This project uses FreeRTOS to control traffic lights and display the remaining time for each light phase on two 7-segment displays using multiplexing.

## Features
- **Traffic Light Control**: Manages red, yellow, and green lights with set times for each phase.
- **Time Display**: Shows remaining time for each phase on two multiplexed 7-segment displays.
- **Task Management**: FreeRTOS schedules tasks for light control, countdown, and time display.

## Task Overview
1. **SSD Display Task**: Shows the countdown on two 7-segment displays.
2. **Traffic Light Control Task**: Switches between red, yellow, and green lights with corresponding times.
3. **Countdown Task**: Decreases the remaining time every second.

## How It Works
- The system starts with the red light for 10 seconds, then yellow for 5 seconds, and green for 10 seconds, displaying the countdown for each phase on the 7-segment displays. The cycle repeats.
  
## Demo

![Traffic Light Control System Demo](Demo.gif)

This GIF demonstrates the traffic light control system, showing the light transitions and the countdown timer on the 7-segment displays.
