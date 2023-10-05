#include "raylib.h"

int main() {
    const int windowWidth{512};
    const int windowHeight{380};

    int velocity{0};
    int jumpVelocity{-14};
    bool isInAir{false};
    //accelerqation due to gravity px/f/f
    const int gravity{1};

    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    //compound data type
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRect;
    scarfyRect.width = scarfy.width/6;
    scarfyRect.height = scarfy.height;
    scarfyRect.x = 0;
    scarfyRect.y = 0;
    Vector2 scarfyPosition;
    scarfyPosition.x = windowWidth/2 - scarfyRect.width/2;
    scarfyPosition.y = windowHeight/2 - scarfyRect.height;

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if(scarfyPosition.y >= (windowHeight - scarfyRect.width)){
            velocity = 0;
            isInAir = false;
        }
        else{
            //apply gravity
            velocity += gravity;
        }
        
        //game logic begins
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity += jumpVelocity;
            isInAir = true;
        }
        
        //update position
        scarfyPosition.y += velocity;

        DrawTextureRec(scarfy, scarfyRect, scarfyPosition, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();

    return 0;
}