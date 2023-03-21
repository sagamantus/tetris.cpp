#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <vector>
#include <utility>
#include "../lib/playfield.h"

class Tetromino
{
public:
    std::pair<int, int> position;
    std::vector<std::vector<std::string>> tetromino_grid;

    void drop(Playfield& pf);
    bool is_overlapping(Playfield& pf, std::vector<std::vector<std::string>> new_orientation);
    bool is_overlapping(Playfield& pf, std::pair<int,int> new_position);
    void move_down(Playfield& pf);
    void move_left(Playfield& pf);
    void move_right(Playfield& pf);
    void rotate(Playfield& pf);
    Tetromino generate_tetromino(Playfield& pf);
};

class ITetromino : public Tetromino
{
public:
    ITetromino();
};

class JTetromino : public Tetromino
{
public:
    JTetromino();
};

class LTetromino : public Tetromino
{
public:
    LTetromino();
};

class OTetromino : public Tetromino
{
public:
    OTetromino();
};

class STetromino : public Tetromino
{
public:
    STetromino();
};

class TTetromino : public Tetromino
{
public:
    TTetromino();
};

class ZTetromino : public Tetromino
{
public:
    ZTetromino();
};

#endif