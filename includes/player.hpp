#ifndef PLAYER_HPP
# define PLAYER_HPP

# include <raylib.h>

class Player {
public:
	Player();
	void		draw(void);
private:
	Vector2		pos;
	Texture2D	texture;
};

#endif
