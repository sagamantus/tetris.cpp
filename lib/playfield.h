#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include <iostream>
#include <ncurses.h>
#include <vector>

class Playfield
{
public:
    int rows;
    int columns;
    int score;               // Total score
    
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

#endif