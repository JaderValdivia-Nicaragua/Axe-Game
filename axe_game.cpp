#include "raylib.h"

int main() {

    // Window Dimensions
    int windows_width = 800;
    int windows_height = 450;
    InitWindow(windows_width, windows_height, "Axe Game");

    // Circle coordinates
    int circle_x = 200;
    int circle_y = 200;
    int circle_radius = 25;

    // circle edges
    int l_circle_x = circle_x - circle_radius;
    int r_circle_x = circle_x + circle_radius;
    int u_circle_y = circle_y - circle_radius;
    int b_circle_y = circle_y + circle_radius;

    // axe cordinates
    int axe_x = 400;
    int axe_y = 0;
    int axe_length = 50;

    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_length;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_length;

    // Square direction by pixel
    int direction = 10;

    // Collision variable
    int collision_with_axe = false;

    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        // Update the background frame
        BeginDrawing();
        ClearBackground(WHITE);

        // GAME OVER if there is a collision
        if (collision_with_axe) {
            DrawText("GAME OVER!", 350, 200, 20, RED);
        }
        else {
            // Game Logic begins
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);
            
            if (IsKeyDown(KEY_D) && r_circle_x < windows_width) {
                circle_x += 10;
            }
            else if (IsKeyDown(KEY_A) && l_circle_x > 0) {
                circle_x -= 10;
            }
            
            else if (IsKeyDown(KEY_S) && b_circle_y < windows_height) {
                circle_y += 10;
            }
            else if (IsKeyDown(KEY_W) && u_circle_y > 0) {
                circle_y -= 10;
            }
            
            // Move the axe
            axe_y += direction;
            
            // Update coordinates
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_length;

            // Evalue axe direction
            if (b_axe_y > windows_height || u_axe_y < 0) {
                direction *= -1; 
            }

            // Detect a collision beetwen axe and circle
            collision_with_axe =
                                l_circle_x <= r_axe_x &&
                                u_circle_y <= b_axe_y &&
                                b_circle_y >= u_axe_y &&
                                r_circle_x >= l_axe_x;

            // Drawing the axe
            DrawRectangle(axe_x, axe_y, axe_length, axe_length, RED);
        }
        // Game logic ends
        EndDrawing();
    }
    return 0;
}