#include "raylib.h"
#include <array>
#include <random>
#include <thread>
#include <iostream>


short calculateNeighbor(const std::vector<std::vector<short>>& grid, size_t row, size_t col){
     short neighborCounter{};

     for(int i = -1; i < 2; ++i) {
         for (int j = -1; j < 2; ++j) {
             if(j == 0 && i == 0){
                 continue;
             }
             if (grid[row + i][col + j] == 1) ++neighborCounter;
         }
     }
     return neighborCounter;
}



void renderGrid(const std::vector<std::vector<short>>& grid){
    int currentXPos{};
    int currentYPos{};

    for(const auto& row : grid){
        for(const auto& col : row){
            if(col == 1) {
                DrawRectangle(currentXPos, currentYPos, 5, 5, WHITE);
            }
            currentXPos += 5;
        }
        currentYPos += 5;
        currentXPos = 0;
    }
}
std::vector<std::vector<short>> createNewGeneration(const std::vector<std::vector<short>>& grid, const int& numOfCellsInRow, const int& numOfCellsInCol){

    std::vector<std::vector<short>> newGenerationGrid(numOfCellsInRow, std::vector<short>(numOfCellsInCol, 0));

    short numOfNeighbor{};
    bool currentState{};

    for(size_t row = 0; row < grid.size(); ++row){
        for(size_t cols = 0; cols < grid[0].size(); ++cols){
            currentState = grid[row][cols];

            if(row == 0 || row == (grid.size() -1) || cols == 0 || cols == (grid[0].size() - 1)){
                continue;
            }
            numOfNeighbor = calculateNeighbor(grid, row, cols);

            if(currentState == 0 && numOfNeighbor == 3){
                newGenerationGrid[row][cols] = 1;
            }else if(currentState == 1 && (numOfNeighbor > 3 || numOfNeighbor < 2) ){
                newGenerationGrid[row][cols] = 0;
            }else{
                newGenerationGrid[row][cols] = currentState;
            }
        }
    }


    return newGenerationGrid;

}

std::vector<std::vector<short>> createGrid(int screenWidth, int screenHeight){
    int numOfCellsInRow = screenHeight / 5; // 10 -> size of each cell
    int numOfCellsInCol = screenWidth / 5;
    int randomNum{};

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> distrib(0, 1);


    std::vector<std::vector<short>> grid(numOfCellsInRow, std::vector<short>(numOfCellsInCol, 0));

    for(auto & row : grid){
        for(short & col : row){
            randomNum = distrib(gen);

            col = (randomNum == 1) ? 1 : 0;
        }
    }

    return grid;

}

int main() {

    const int screenWidth = 1000;
    const int screenHeight = 1000;
    InitWindow(screenWidth, screenHeight, "Game Of Life");

    int numOfCellsInRow = screenHeight / 5;
    int numOfCellsInCol = screenWidth / 5;

    std::vector<std::vector<short>> grid = createGrid(screenWidth, screenHeight);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);


        renderGrid(grid);

        grid = createNewGeneration(grid, numOfCellsInRow, numOfCellsInCol);
        std::this_thread::sleep_for(std::chrono::milliseconds(25));

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
