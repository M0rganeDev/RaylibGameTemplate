#ifndef TEXTURE_MANAGER_HPP
# define TEXTURE_MANAGER_HPP

# include "macros.hpp"
# include "raylib.h"
# include <string>

class TextureWrapper
{
public:
	Texture2D	get() { return m_Texture; }
	std::string	id() { return m_Name; }
private:
	Texture2D	m_Texture;
	std::string	m_Name;
	SET_ONCE(m_Texture);
	SET_ONCE(m_Name);
};

Texture2D	load_texture(std::string filename);
void		unload_texture(Texture2D texture);
void		unload_texture(std::string filename);
void		remove_unused_textures(void);

# endif
