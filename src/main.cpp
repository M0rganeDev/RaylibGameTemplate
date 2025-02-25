#include "TextureManager.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include "imgui.h"

int	main(int argc, char **argv, char **envp)
{
	Texture2D	texture;

	InitWindow(1280, 720, "Hello World !");
	SetTargetFPS(60);

	rlImGuiSetup(true);

	texture = load_texture("missing.png");

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		DrawTexture(texture, 256, 256, WHITE);
		rlImGuiBegin();
		bool open = true;
		open = true;
		if (ImGui::Begin("Test Window", &open))
		{
			ImGui::TextUnformatted("Hello World");

			rlImGuiImage(&texture);
		}
		ImGui::End();
		rlImGuiEnd();
    	EndDrawing();
	}
	remove_unused_textures();
	rlImGuiShutdown();
	CloseWindow();
	return (0);
}
