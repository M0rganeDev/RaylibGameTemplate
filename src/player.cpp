#include "player.hpp"
#include "TextureManager.hpp"
#include <raylib.h>

Player::Player()
{
	this->pos = { 250, 250 };
	this->texture = load_texture("missing.png");
}

void Player::draw(void)
{
	if (IsKeyDown(KEY_UP))
		pos.y -= 5;
	else if (IsKeyDown(KEY_DOWN))
		pos.y += 5;
	if (IsKeyDown(KEY_LEFT))
		pos.x -= 5;
	else if (IsKeyDown(KEY_RIGHT))
		pos.x += 5;
	DrawTexture(this->texture, pos.x, pos.y, WHITE);
}
