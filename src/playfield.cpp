#include <iostream>
#include <ncurses.h>
#include <vector>
#include "../lib/constants.h"

class Playfield
{
public:
    int rows;
    int columns;
    // 2D vector representing the cells on the playfield
    std::vector<std::vector<std::string>> game_grid;

    // Constructors
    Playfield();                      // Default
    Playfield(int rows, int columns); // With rows and columns

    // Methods
    bool row_full(int row);  // Check if a row is completely filled
    void clear_row(int row); // Clear the row
    void clear_filled();     // Clear all completely filled rows
};

// Default constructor
Playfield::Playfield()
{
    // Initialize the rows, columns and game grid vector
    this->rows = DEF_ROW;
    this->columns = DEF_COL;
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
