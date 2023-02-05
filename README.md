# Arduino-Robot-Car
This is some programming for the arudino robot car found at [this link](https://www.amazon.com/KEYESTUDIO-Bluetooth-Controller-Ultrasonic-Programming/dp/B08276N3D9/ref=asc_df_B08276N3D9?tag=bngsmtphsnus-20&linkCode=df0&hvadid=80127027724148&hvnetw=s&hvqmt=e&hvbmt=be&hvdev=c&hvlocint=&hvlocphy=&hvtargid=pla-4583726553591369&psc=1).  Although you can find code for this robot in the [manual](https://tinyurl.com/robot-car-arduino), the code in the manual has several things wrong with it that often produce an unnecessary amount of troubleshooting.  Some problems with the code in the manual include:
 - Programming Errors (eg. missing brackets or semicolons)
 - Very bad codesmanship (eg. disorganized code, missing line indentations, inconsistent spacing, misplaced spaces, and more)
 - The use of libraries that are difficult to install and not needed (eg SR04.h)
 - Overcomplication of code by lack of function usage
 - Incorrect pin numbers for components based on robot wiring instructions (eg. Middle and left blackline sensors, servo motor, right motors pwm, and more)
 - Low program quality (eg. robot moves very slow on blackline when it could move so much faster, or robot stops when it goes off the edge of blackline)

Because there are so many errors in this code, I decided to write completely different code for the robot.  You can access that code in this repository.  If you have any questions or comments, please post them in the [repository discussion](https://github.com/WesleyMcGinn/Arduino-Robot-Car/discussions/1).  I hope that you will find this code to be useful for your programming and your learning.

![Picture of Robot](https://m.media-amazon.com/images/I/71XpzsS2dbL._AC_SX466_.jpg)
