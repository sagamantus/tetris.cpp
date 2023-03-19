#ifndef TETROMINO_H
#define TETROMINO_H

#include <iostream>
#include <vector>

class Tetromino
{
public:
    std::vector<std::vector<std::string>> tetromino_grid;

    // void rotate(playfield pf){}
    void rotate(std::vector<std::vector<std::string>> &matrix);
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