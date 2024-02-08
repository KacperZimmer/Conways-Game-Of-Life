# Conway's Game of Life in C++ using Raylib Library

## Description

This program implements the classical Conway's Game of Life using the Raylib library for graphics rendering. The Game of Life is a type of cellular automaton game where cells on the board evolve according to simple rules.

## Source Code

### Code Structure

- `calculateNeighbor(const std::vector<std::vector<short>>& grid, size_t row, size_t col)`: Function to calculate the number of neighbors of a given cell.
- `renderGrid(const std::vector<std::vector<short>>& grid)`: Function to render the game grid.
- `createNewGeneration(const std::vector<std::vector<short>>& grid, const int& numOfCellsInRow, const int& numOfCellsInCol)`: Function to create a new generation of cells based on the current grid state.
- `createGrid(int screenWidth, int screenHeight)`: Function to initialize the game grid with random cell states.
- `main()`: Main function containing the game loop and window initialization.

### Dependencies

- Raylib Library: Used for graphics rendering.

## How to Use

1. Compile the program with a C++ compiler.
2. Run the compiled executable.
3. Watch the Game of Life simulation unfold in the Raylib window.

## Controls

- Close the window to exit the simulation.

## Notes

- The grid size and cell size are configurable.
- The initial state of the grid is randomly generated.
- Each generation evolves based on the rules of Conway's Game of Life.

## Example 

![Tekst zastępczy]([nazwa_pliku_obrazu.png](https://github.com/KacperZimmer/Conways-Game-Of-Life/blob/main/img/example.png)https://github.com/KacperZimmer/Conways-Game-Of-Life/blob/main/img/example.png)
