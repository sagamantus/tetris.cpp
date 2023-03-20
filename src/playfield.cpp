#include <iostream>
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include "../lib/constants.h"
#include "../lib/playfield.h"
#include "../lib/tetromino.h"

// Default constructor
Playfield::Playfield()
{
    // Initialize the score, rows, columns and game grid vector
    this->score = 0;
    this->rows = WINDOW_HEIGHT;
    this->columns = WINDOW_WIDTH;
    this->game_grid.resize(this->rows + 2);
    this->game_grid[0].resize(this->columns + 2, "x");
    for (int row = 1; row <= this->rows; ++row)
    {
        this->game_grid[row].resize(this->columns + 2, " ");
    }
    this->game_grid[rows + 1].resize(this->columns + 2, "x");
}

// Constructor with rows and columns specified
Playfield::Playfield(int rows, int columns)
{
    // Initialize the score, rows, columns and game grid vector
    this->score = 0;
    this->rows = rows;
    this->columns = columns;
    this->game_grid.resize(this->rows + 2);
    this->game_grid[0].resize(this->columns + 2, "x");
    for (int row = 1; row <= this->rows; ++row)
    {
        this->game_grid[row].resize(this->columns + 2, " ");
    }
    this->game_grid[rows + 1].resize(this->columns + 2, "x");
}

// Check if a row is completely filled
bool Playfield::row_full(int row)
{
    bool is_full = true;
    for (std::string cell : this->game_grid[row])
    {
        if (cell == " ")
        {
            is_full = false;
            break;
        }
    }
    return is_full;
}

// Clear a row by removing it and inserting a new empty row at the top of the grid
void Playfield::clear_row(int row)
{
    this->game_grid.erase(this->game_grid.begin() + row);
    std::vector<std::string> new_row(this->columns + 2, " ");
    new_row[0] = "x";
    new_row[columns + 1] = "x";
    this->game_grid.insert(this->game_grid.begin(), new_row);
}

// Clear all completely filled rows by calling clear_row for each filled row
void Playfield::clear_filled()
{
    int cleared = 0;
    for (int row = 0; row < this->rows; ++row)
    {
        if (this->row_full(row))
        {
            this->clear_row(row);
            cleared++;
        }
    }
    if (cleared == 4)
    {
        this->score += 80;
    }
    else if (cleared == 3)
    {
        this->score += 50;
    }
    else if (cleared == 2)
    {
        this->score += 30;
    }
    else
    {
        this->score += 10;
    }
}

Tetromino Playfield::generate_tetromino()
{
    srand(time(NULL));
    Tetromino tetrominos[] = {ITetromino(), JTetromino(), LTetromino(), OTetromino(), STetromino(), TTetromino(), ZTetromino()};
    Tetromino selected = tetrominos[rand() % 7];
    for (int i = 0; i < rand() % 4; ++i)
    {
        selected.rotate(*this);
    }
    return selected;
}
