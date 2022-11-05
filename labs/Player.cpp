#include "Player.h"

Player::Player(int x, int y) : x(x), y(y)
{
    this->hp = 3;
    this->ammo = 10;
    this->score = 0;
}

Player::~Player()
{
}

int Player::GetX()
{
    return this->x;
}

int Player::GetY()
{
    return this->y;
}

int Player::GetHP()
{
    return this->hp;
}

int Player::GetScore()
{
    return this->score;
}

int Player::GetAmmo()
{
    return this->ammo;
}

void Player::SetX(int x_new)
{
    x = x_new;
}

void Player::SetY(int y_new)
{
    y = y_new;
}

void Player::SetHP(int new_hp)
{
    this->hp = new_hp;
}

void Player::SetScore(int new_score)
{
    this->score = new_score;
}

void Player::SetAmmo(int new_ammo)
{
    this->ammo = new_ammo;
}

