#include <raylib.h>
#include <stdio.h>
#include <array>
#include <cmath>
#include <cstdlib>
#include <vector>

int playerPos[2] = {1280/2,720/2};
int playerHealth=100;
int speed=5;
int enemySpeed=7;

int randminmax(int min, int max) {
  return std::rand()%(max-min+1)+min;
}

class Enemy {
  public:
    int health;
    int color[3];

    Enemy(int health) {
      this->health=health;
    }



  private:
    std::array<float, 2> directionToPoint(int enemyX, int enemyY, int playerX, int playerY) {
        float dx = playerX - enemyX;
        float dy = playerY - enemyY;
        float distance = std::sqrt(dx * dx + dy * dy);
    
        // Normalize the direction vector
        if (distance != 0) {
            dx /= distance;
            dy /= distance;
        }
        return {dx, dy};  // Return the normalized direction vector
    }
};

int frames=0;

int enemyPos[2]={0,240};

std::vector<Enemy> enemies;

int main() {
    InitWindow(1280,720, "Ludum Dare 56");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Movement + math to stop player from going off screen
        if (IsKeyDown(KEY_A) && playerPos[0]>0) playerPos[0]-=speed;  
        if (IsKeyDown(KEY_D) && playerPos[0]+20<1280) playerPos[0]+=speed;
        if (IsKeyDown(KEY_W) && playerPos[1]>0) playerPos[1]-=speed;
        if (IsKeyDown(KEY_S) && playerPos[1]+20<720) playerPos[1]+=speed;

        DrawRectangle(playerPos[0],playerPos[1],20,20,BLACK);
        DrawRectangle(enemyPos[0],enemyPos[1],10,10,RED);

        DrawText(TextFormat("\n\nFPS: %d\nFT: %f",GetFPS(),GetFrameTime()),0,0,18,LIGHTGRAY);
        DrawText(TextFormat("HEALTH: %d%",playerHealth),0,0,18,DARKGRAY);
        EndDrawing();
        if (frames<60) {frames++;}
        else {frames=0;}
    }

    CloseWindow();

    return 0;
}
