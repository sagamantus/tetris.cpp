#include <iostream>
#include <ncurses.h>
#include <vector>
#include "../lib/constants.h"
#include "../lib/playfield.h"

// Default constructor
Playfield::Playfield()
{
    // Initialize the rows, columns and game grid vector
    this->rows = WINDOW_HEIGHT;
    this->columns = WINDOW_WIDTH;
    this->game_grid.resize(this->rows);
    for (int row = 0; row < this->rows; ++row)
        this->game_grid[row].resize(this->columns, "");
}

// Constructor with rows and columns specified
Playfield::Playfield(int rows, int columns)
{
    // Initialize the rows, columns and game grid vector
    this->rows = rows;
    this->columns = columns;
    this->game_grid.resize(this->rows);
    for (int row = 0; row < this->rows; ++row)
        this->game_grid[row].resize(this->columns, "");
}

// Check if a row is completely filled
bool Playfield::row_full(int row)
{
    bool is_full = true;
    for (std::string cell : this->game_grid[row])
    {
        if (cell.empty())
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
    this->game_grid.insert(this->game_grid.begin(), std::vector<std::string>(this->columns, ""));
}

// Clear all completely filled rows by calling clear_row for each filled row
void Playfield::clear_filled()
{
    for (int row = 0; row < this->rows; ++row)
    {
        if (this->row_full(row))
        {
            this->clear_row(row);
        }
    }
}
