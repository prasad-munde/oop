#include <graphics.h>
#include <conio.h>
#include <math.h>

Void drawBall(int x, int y, int radius) {
    Setcolor(RED);
    Circle(x, y, radius);
    Floodfill(x, y, RED);
}

Int main() {
    // Initialize graphics
    Int gd = DETECT, gm;
    Initgraph(&gd, &gm, “”);

    // Ball properties
    Int radius = 20;
    Int x = 400; // Starting X position
    Float time = 0.0f;
    Float frequency = 0.1f; // Frequency of sine wave
    Float amplitude = 150.0f; // Amplitude of bounce
    Int baseHeight = 300; // Base height for the sine wave

    // Main loop
    While (!kbhit()) {
        // Clear the previous frame
        Cleardevice();

        // Calculate the y position using sine wave
        Int y = baseHeight + static_cast<int>(amplitude * sin(frequency * time));

        // Draw the ball
        drawBall(x, y, radius);

        // Update time
        Time += 0.1f;

        // Delay for a smoother animation
        Delay(20);
    }

    // Close the graphics window
    Closegraph();
    Return 0;
}
