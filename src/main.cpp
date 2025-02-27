#include "pa_texture_manager.hpp"
#include "event.hpp"
#include "macros.hpp"
#include "raylib.h"
#include "rlImGui.h"
#include "player.hpp"

static Player *player;

void	on_render(RenderWorldEvent *event)
{
	player->draw();
	DrawFPS(0, 0);
}

int		main(int argc, char **argv, char **envp)
{
	InitWindow(1280, 720, "Hello World !");
	SetTargetFPS(60);
	rlImGuiSetup(true);

	LOG(INFO, "hello world !");
	REGISTER_LISTENER(on_render, RenderWorldEvent);
	player = new Player();

	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(DARKGRAY);
		fire_event(new RenderWorldEvent());

		rlImGuiBegin();
		fire_event(new RenderImguiEvent());
		rlImGuiEnd();

    	EndDrawing();
	}
	delete player;
	remove_unused_textures();
	rlImGuiShutdown();
	CloseWindow();
	return (0);
}
