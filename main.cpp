#include <iostream> // Include all needed libraries here
#include <wiringPi.h>

using namespace std; // No need to keep using “std”

int main() {
    wiringPiSetup();    // Setup the library
    pinMode(0, OUTPUT); // Configure GPIO0 as an output
    pinMode(1, INPUT);  // Configure GPIO1 as an input
    digitalWrite(0, 0);
    // Main program loop
    while (1)
    {
        // Button is pressed if digitalRead returns 0
            // Toggle the LED
            digitalWrite(0, !digitalRead(0));
            uint state = digitalRead(0);
            string onOff;
            if(state == 0) onOff = " off ";
            else onOff = " on ";
            cout << "LED is in an" + onOff + "state" << '\n';
            delay(200); // Delay 500ms
    }
    return 0;
}