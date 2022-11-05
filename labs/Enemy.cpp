#include "Enemy.h"

Enemy::Enemy(int x, int y) : x(x), y(y)
{
    this->hp = 3;
}

Enemy::~Enemy()
{
}

int Enemy::GetX()
{
    return this->x;
}

int Enemy::GetY()
{
    return this->y;
}

int Enemy::GetHP()
{
    return this->hp;
}

void Enemy::SetX(int x_new)
{
    this->x = x_new;
}

void Enemy::SetY(int y_new)
{
    this->y = y_new;
}

void Enemy::SetHP(int hp_new)
{
    this->hp = hp_new;
}
