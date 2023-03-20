#include <iostream>
#include <ncurses.h>
#include "../lib/playfield.h"
#include "../lib/tetromino.h"

void Tetromino::drop(Playfield pf)
{
    while (!this->is_overlapping(pf, {this->position.first + 1, this->position.second}))
    {
        this->position.first++;
    }
    // write into playfield grid
}

bool Tetromino::is_overlapping(Playfield pf, std::vector<std::vector<std::string>> new_orientation)
{
    bool overlapping = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (new_orientation[i][j] != " " && pf.game_grid[this->position.first + i][this->position.second + j] != " ")
            {
                overlapping = false;
                return overlapping;
            }
        }
    }
}

bool Tetromino::is_overlapping(Playfield pf, std::pair<int, int> new_position)
{
    bool overlapping = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (this->tetromino_grid[i][j] != " " && pf.game_grid[new_position.first + i][new_position.second + j] != " ")
            {
                overlapping = false;
                return overlapping;
            }
        }
    }
}

void Tetromino::move_down(Playfield pf)
{
    if (this->position == std::pair<int, int>({-1, -1}))
    {
        if (!this->is_overlapping(pf, {0, (pf.rows / 2) - 1}))
        {
            this->position = std::pair<int, int>({0, (pf.rows / 2) - 1});
        }
        else
        {
            // game over
        }
    }
    else if (!this->is_overlapping(pf, {this->position.first + 1, this->position.second}))
    {
        this->position.first++;
    }
    else
    {
        // write into playfield grid
    }
}

void Tetromino::move_left(Playfield pf)
{
    if (!this->is_overlapping(pf, {this->position.first, this->position.second - 1}))
    {
        this->position.second--;
    }
}

void Tetromino::move_right(Playfield pf)
{
    if (!this->is_overlapping(pf, {this->position.first, this->position.second + 1}))
    {
        this->position.second++;
    }
}

void Tetromino::rotate(Playfield pf)
{
    std::vector<std::vector<std::string>> matrix = pf.game_grid;
    std::vector<std::vector<std::string>> result;
    for (auto i = 0; i < 4; i++)
    {
        std::vector<std::string> row;
        for (int j = 3; j >= 0; j--)
        {
            row.push_back(matrix[j][i]);
        }
        result.push_back(row);
    }
    if (this->position == std::pair<int, int>({-1, -1}))
    {
        this->tetromino_grid = result;
    } else {
        if (!this->is_overlapping(pf, matrix))
        {
            this->tetromino_grid = result;
        }
    }
}

ITetromino::ITetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", "0", " ", " "},
        {" ", "0", " ", " "},
        {" ", "0", " ", " "},
        {" ", "0", " ", " "},
    };
}
TTetromino::TTetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", " ", "0", " "},
        {" ", "0", "0", " "},
        {" ", " ", "0", " "},
        {" ", " ", " ", " "},
    };
}
ZTetromino::ZTetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", " ", "0", " "},
        {" ", "0", "0", " "},
        {" ", "0", " ", " "},
        {" ", " ", " ", " "},
    };
}
STetromino::STetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", "0", " ", " "},
        {" ", "0", "0", " "},
        {" ", " ", "0", " "},
        {" ", " ", " ", " "},
    };
}
OTetromino::OTetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", "0", "0", " "},
        {" ", "0", "0", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
    };
}
JTetromino::JTetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", " ", "0", " "},
        {" ", " ", "0", " "},
        {" ", "0", "0", " "},
        {" ", " ", " ", " "},
    };
}
LTetromino::LTetromino()
{
    this->position = {-1, -1};
    this->tetromino_grid = {
        {" ", "0", " ", " "},
        {" ", "0", " ", " "},
        {" ", "0", "0", " "},
        {" ", " ", " ", " "},
    };
}