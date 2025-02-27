#include "pa_texture_manager.hpp"
#include "raylib.h"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

// Used to cache textures as I have no clues if Raylib do it
static std::vector<TextureWrapper *> textures = { };

static TextureWrapper	*is_texture_loaded(std::string filename)
{
	for (TextureWrapper *text : textures)
		if(!strcmp(filename.c_str(), text->id().c_str()))
			return (text);
	return (NULL);
}

Texture2D	load_texture(std::string filename)
{
	TextureWrapper	*texture;

	texture = is_texture_loaded(filename);

	if (texture != NULL)
		return (texture->get());

	// if nothing goes wrong, will be deleted
	// automatically by remove_unused_textures
	// once a room system / entity system will be made
	texture = new TextureWrapper();
	texture->set_m_Name(filename);
	texture->set_m_Texture(LoadTexture(std::string("resources/" + filename).c_str()));

	textures.push_back(texture);
	return (texture->get());
}

void		unload_texture(std::string name)
{
	TextureWrapper	*texture;

	texture = is_texture_loaded(name);
	if (texture != NULL)
	{
		UnloadTexture(texture->get());
        auto it = std::find(textures.begin(), textures.end(), texture);
		textures.erase(it);
		delete texture;
        texture = NULL;
		printf("Deleted texture %s\n", name.c_str());
	}
}

void		unload_texture(Texture2D name)
{
	TextureWrapper	*temp;
	int				index;

	temp = NULL;
	index = 0;
	for (TextureWrapper *texture : textures)
	{
		if (texture->get().id == name.id)
		{
			temp = texture;
			break ;
		}
		++index;
	}
	if (temp == NULL)
		return ;
	unload_texture(temp->id());
}

void		remove_unused_textures(void)
{
	for (TextureWrapper *texture : textures)
	{
		UnloadTexture(texture->get());
		auto it = std::find(textures.begin(), textures.end(), texture);
		textures.erase(it);
		delete texture;
        texture = NULL;
	}
}
