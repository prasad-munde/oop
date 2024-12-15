#include <graphics.h>
#include <conio.h>
#include <math.h>

void drawBall(int x, int y, int radius) {
    setcolor(RED);
    circle(x, y, radius);
    floodfill(x, y, RED);
}

int main() {
    // Initialize graphics
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Ball properties
    int radius = 20;
    int x = 400; // Starting X position
    float time = 0.0f;
    float frequency = 0.1f; // Frequency of sine wave
    float amplitude = 150.0f; // Amplitude of bounce
    int baseHeight = 300; // Base height for the sine wave

    // Main loop
    while (!kbhit()) {
        // Clear the previous frame
        cleardevice();

        // Calculate the y position using sine wave
        int y = baseHeight + static_cast<int>(amplitude * sin(frequency * time));

        // Draw the ball
        drawBall(x, y, radius);

        // Update time
        time += 0.1f;

        // Delay for a smoother animation
        delay(20);
    }

    // Close the graphics window
    closegraph();
    return 0;
}
