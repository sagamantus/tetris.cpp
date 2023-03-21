#include <iostream>
#include <ncurses.h>
#include "../lib/playfield.h"
#include "../lib/tetromino.h"

void Tetromino::drop(Playfield &pf)
{
    while (!this->is_overlapping(pf, {this->position.first + 1, this->position.second}))
    {
        this->position.first++;
    }
    // write into playfield grid
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (this->tetromino_grid[i][j] != " ")
                pf.game_grid[this->position.first + i][this->position.second + j] = this->tetromino_grid[i][j];
        }
    }
    *this = this->generate_tetromino(pf);
    this->move_down(pf);
    this->move_down(pf);
    pf.clear_filled();
}

bool Tetromino::is_overlapping(Playfield &pf, std::vector<std::vector<std::string>> new_orientation)
{
    bool overlapping = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (new_orientation[i][j] != " " && pf.game_grid[this->position.first + i][this->position.second + j] != " ")
            {
                overlapping = true;
                return overlapping;
            }
        }
    }
    return overlapping;
}

bool Tetromino::is_overlapping(Playfield &pf, std::pair<int, int> new_position)
{
    bool overlapping = false;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (this->tetromino_grid[i][j] != " " && pf.game_grid[new_position.first + i][new_position.second + j] != " ")
            {
                overlapping = true;
                return overlapping;
            }
        }
    }
    return overlapping;
}

void Tetromino::move_down(Playfield &pf)
{
    if (this->position.first == -1)
    {
        if (!this->is_overlapping(pf, {1, (pf.columns / 2) - 1}))
        {
            this->position = std::pair<int, int>({0, (pf.columns / 2) - 1});
        }
        else
        {
            // game over
            ungetch('q');
        }
    }
    else if (!this->is_overlapping(pf, {this->position.first + 1, this->position.second}))
    {
        this->position.first++;
    }
    else
    {
        // write into playfield grid
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (this->tetromino_grid[i][j] != " ")
                    pf.game_grid[this->position.first + i][this->position.second + j] = this->tetromino_grid[i][j];
            }
        }
        *this = this->generate_tetromino(pf);
        this->move_down(pf);
        this->move_down(pf);
        pf.clear_filled();
    }
}

void Tetromino::move_left(Playfield &pf)
{
    if (!this->is_overlapping(pf, {this->position.first, this->position.second - 1}))
    {
        this->position.second--;
    }
}

void Tetromino::move_right(Playfield &pf)
{
    if (!this->is_overlapping(pf, {this->position.first, this->position.second + 1}))
    {
        this->position.second++;
    }
}

void Tetromino::rotate(Playfield &pf)
{
    std::vector<std::vector<std::string>> matrix = this->tetromino_grid;
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
    }
    else
    {
        if (!this->is_overlapping(pf, matrix))
        {
            this->tetromino_grid = result;
        }
    }
}

Tetromino Tetromino::generate_tetromino(Playfield &pf)
{
    srand(time(NULL));
    Tetromino tetrominos[] = {ITetromino(), JTetromino(), LTetromino(), OTetromino(), STetromino(), TTetromino(), ZTetromino()};
    Tetromino selected = tetrominos[rand() % 7];
    for (int i = 0; i < rand() % 4; ++i)
    {
        selected.rotate(pf);
    }
    return selected;
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