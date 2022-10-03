# pi_cpp_template
C++ template for raspberry pi 4B with cmake file

Required Libraries

- cmake
- git
- wiringPi
- g++ compiler


wiringPi installation
- git clone https://github.com/WiringPi/WiringPi.git
- ./build

cmake installation
- sudo apt update
- sudo apt upgrade-full
- sudo apt install cmake

git
- sudo apt install git

g++ compiler
- comes with the raspbian OS

After you have all the required packages installed, you'll need to cd into the build directory and run "cmake .." and "make".
This will create an executable file with no file extension on it. Just type in the name of the file to run the program. You'll
need to wire an LED from GPIO 0 to ground in order to see the blink, but you'll see the log output without this.