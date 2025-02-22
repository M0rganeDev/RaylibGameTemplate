#include "TextureManager.hpp"
#include "raylib.h"

int	main(int argc, char **argv, char **envp)
{
	Texture2D	texture;

	InitWindow(1280, 720, "Hello World !");
	SetTargetFPS(60);

	texture = load_texture("missing.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawTexture(texture, 256, 256, WHITE);
    	EndDrawing();
	}
	unload_texture("missing.png");
	CloseWindow();
	return (0);
}
