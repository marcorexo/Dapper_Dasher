#include "raylib.h"

int main() {
    const int windowWidth{512};
    const int windowHeight{380};

    int velocity{0};
    // pixels / second
    int jumpVelocity{-600};
    bool isInAir{false};
    //accelerqation due to gravity px/s/s
    const int gravity{1'000};

    //sprite animation rate
    const float updateTime{1.0/12.0};
    float runningTime{};

    InitWindow(windowWidth, windowHeight, "Dapper Dasher!");

    //compound data type
    Texture2D scarfy = LoadTexture("textures/scarfy.png");

    //rectangle used for the sprite animation
    Rectangle scarfyRect;
    scarfyRect.width = scarfy.width/6;
    scarfyRect.height = scarfy.height;
    scarfyRect.x = 0;
    scarfyRect.y = 0;

    Vector2 scarfyPosition;
    scarfyPosition.x = windowWidth/2 - scarfyRect.width/2;
    scarfyPosition.y = windowHeight/2 - scarfyRect.height;

    int frame{};
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        //delta time (time between current and last frame)
        const float dT{GetFrameTime()};

        if(scarfyPosition.y >= (windowHeight - scarfyRect.width)){
            velocity = 0;
            isInAir = false;
        }
        else{
            //apply gravity
            velocity += gravity * dT;
        }
        
        //game logic begins
        if(IsKeyPressed(KEY_SPACE) && !isInAir){
            velocity += jumpVelocity;
            isInAir = true;
        }
        
        //update position
        scarfyPosition.y += velocity * dT;

        //update the animaiton running time
        runningTime += dT;
        if(runningTime >= updateTime){
            runningTime = 0.0;
            scarfyRect.x = frame * scarfyRect.width;
            frame++;
            if(frame > 5) frame = 0;
        }

        DrawTextureRec(scarfy, scarfyRect, scarfyPosition, WHITE);

        EndDrawing();
    }

    UnloadTexture(scarfy);
    CloseWindow();

    return 0;
}