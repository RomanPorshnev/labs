#include "Field.h"
#include <vector>
#include "Player.h"
#include <iostream>
Field::Field()
{
	this->m = 20;
	this->n = 40;
}

Field::Field(int m, int n) : m(m), n(n)
{
}

Field::Field(const Field& obj)
{
    this->m = obj.m;
    this->n = obj.n;
    for (int i = 0; i <= m + 1; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j <= n + 1; j++)
        {
            if ((i == 0) || (i == m + 1) || (j == 0) || (j == n + 1))
            {
                Cell ever_cell('@');
                row.push_back(ever_cell);
                continue;
            }
            Cell ever_cell(' ');
            row.push_back(ever_cell);
        }
        matrix.push_back(row);
    }
}

Field& Field::operator=(const Field& obj)
{
    for (auto row : this->matrix) {
        this->matrix.clear();
    }
    matrix.clear();
    for (int i = 0; i <= m + 1; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j <= n + 1; j++)
        {
            if ((i == 0) || (i == m + 1) || (j == 0) || (j == n + 1))
            {
                Cell ever_cell('@');
                row.push_back(ever_cell);
                continue;
            }
            Cell ever_cell(' ');
            row.push_back(ever_cell);
        }
        matrix.push_back(row);
    }
    return *this;
}

Field::Field(Field&& obj)
{
    std::swap(this->m, obj.m);
    std::swap(this->n, obj.n);
    std::swap(this->matrix, obj.matrix);
}

Field& Field::operator=(Field&& obj)
{
    if (this != &obj) {
        std::swap(this->m, obj.m);
        std::swap(this->n, obj.n);
        std::swap(this->matrix, obj.matrix);
    }
    return *this;
}

Field::~Field()
{
    for (auto row : this->matrix) {
        row.clear();
    }
    matrix.clear();
}

void Field::InitMatrix()
{
    for (int i = 0; i <= m + 1; i++)
    {
        std::vector<Cell> row;
        for (int j = 0; j <= n + 1; j++)
        {
            if ((i == 0) || (i == m + 1) || (j == 0) || (j == n + 1))
            {
                Cell ever_cell('@');
                row.push_back(ever_cell);
                continue;
            }
            Cell ever_cell(' ');
            row.push_back(ever_cell);
        }
        matrix.push_back(row);
    }
}

void Field::SetPosPlayer(Player *Plr)
{
    matrix[Plr->GetX()][Plr->GetY()].SetC('+');
}

std::vector<std::vector<Cell>> Field::GetField()
{
    return matrix;
}


void Field::SetMatrix(std::vector<std::vector<Cell>> newmatrix)
{
    matrix = newmatrix;
}

int Field::GetM()
{
    return this->m;
}

int Field::GetN()
{
    return this->n;
}
