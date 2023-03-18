#include <iostream>
#include <ncurses.h>
#include "../lib/tetromino.h"

// void rotate(playfield pf){}
void Tetromino::rotate(std::vector<std::vector<std::string>> &matrix)
{
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
    matrix = result;
}

ITetromino::ITetromino()
{
    this->tetromino_grid = {
        {" ", "_", " ", " "},
        {" ", "_", " ", " "},
        {" ", "_", " ", " "},
        {" ", "_", " ", " "},
    };
}
TTetromino::TTetromino()
{
    this->tetromino_grid = {
        {" ", " ", "_", " "},
        {" ", "_", "_", " "},
        {" ", " ", "_", " "},
        {" ", " ", " ", " "},
    };
}
ZTetromino::ZTetromino()
{
    this->tetromino_grid = {
        {" ", " ", "_", " "},
        {" ", "_", "_", " "},
        {" ", "_", " ", " "},
        {" ", " ", " ", " "},
    };
}
STetromino::STetromino()
{
    this->tetromino_grid = {
        {" ", "_", " ", " "},
        {" ", "_", "_", " "},
        {" ", " ", "_", " "},
        {" ", " ", " ", " "},
    };
}
OTetromino::OTetromino()
{
    this->tetromino_grid = {
        {" ", "_", "_", " "},
        {" ", "_", "_", " "},
        {" ", " ", " ", " "},
        {" ", " ", " ", " "},
    };
}
JTetromino::JTetromino()
{
    this->tetromino_grid = {
        {" ", " ", "_", " "},
        {" ", " ", "_", " "},
        {" ", "_", "_", " "},
        {" ", " ", " ", " "},
    };
}
LTetromino::LTetromino()
{
    this->tetromino_grid = {
        {" ", "_", " ", " "},
        {" ", "_", " ", " "},
        {" ", "_", "_", " "},
        {" ", " ", " ", " "},
    };
}