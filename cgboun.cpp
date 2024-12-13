#include <iostream>
#include <cmath>
#include <thread>
#include <chrono>

#define PI 3.14159265

// Base class representing a general Shape
class Shape {
public:
    // Virtual function to be overridden by derived classes
    virtual void move() = 0;
};

// Derived class representing a Ball that moves in a sine wave
class Ball : public Shape {
private:
    double positionX;
    double amplitude;
    double frequency;
    double phase;
    double step;

public:
    Ball(double amp, double freq, double ph)
        : positionX(0), amplitude(amp), frequency(freq), phase(ph), step(0.1) {}

    // Overriding the move function for sine wave ball behavior
    void move() override {
        positionX += step;
    }

    void display() {
        // Calculate vertical position based on sine wave
        double positionY = amplitude * std::sin(frequency * positionX + phase);

        // Normalize the vertical position for display (map sine wave to a 20-line height display)
        int verticalPos = static_cast<int>((positionY + 1.0) * 10);

        // Display the ball's position
        for (int i = 0; i < 30; i++) {
            if (i == verticalPos) {
                std::cout << "0";  // The ball
            } else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a Ball object that moves in a sine wave
    Ball myBall(1.0, 1.0, 0);  // Amplitude = 1, Frequency = 1, Phase = 0

    // Continuously move and display the ball along the sine wave
    for (int i = 0; i < 100; i++) {
        myBall.move();
        myBall.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::cout << "\r";  // Clears the line for smooth animation
    }

    return 0;
}
