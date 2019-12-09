#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Textures.h"
#include "j1Fonts.h"

#include "SDL\include\SDL.h"

#pragma comment( lib, "SDL_ttf/libx86/SDL2_ttf.lib" )

j1Fonts::j1Fonts() : j1Module()
{

}

// Destructor
j1Fonts::~j1Fonts()
{}

// Called before render is available
bool j1Fonts::Awake(pugi::xml_node& conf)
{
	name.create("fonts");
	LOG("Init True Type Font library");
	bool ret = true;

	if (TTF_Init() == -1)
	{
		LOG("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		ret = false;
	}
	else
	{
		const char* path = conf.child("default_font").attribute("file").as_string(DEFAULT_FONT);
		int size = conf.child("default_font").attribute("size").as_int(DEFAULT_FONT_SIZE);
		default = Load(path, size);
		mapOfFonts.PushBack("defaultFont", default);

		TTF_Font* aux = Load("fonts/CopperPlate/CopperPlate_BoldItalic.ttf", 48);
		mapOfFonts.PushBack("CooperPlateBI48", aux);

		aux = App->font->Load("fonts/CopperPlate/CopperPlate_BoldItalic.ttf", 24);
		mapOfFonts.PushBack("CooperPlateBI24", aux);

		aux = App->font->Load("fonts/CopperPlate/CopperPlate_BoldItalic.ttf", 12);
		mapOfFonts.PushBack("CooperPlateBI12", aux);

		aux = App->font->Load("fonts/CopperPlate/CopperPlate_BoldItalic.ttf", 36);
		mapOfFonts.PushBack("CooperPlateBI36", aux);

		aux = App->font->Load("fonts/open_sans/OpenSans-Bold.ttf", 12);
		mapOfFonts.PushBack("OpenSAnsSB12", aux);
	}

	return true;
}

// Called before quitting
bool j1Fonts::CleanUp()
{
	LOG("Freeing True Type fonts and library");
	p2List_item<TTF_Font*>* item;

	for (item = fonts.start; item != NULL; item = item->next)
	{
		TTF_CloseFont(item->data);
	}

	fonts.clear();
	TTF_Quit();
	return true;
}

// Load new texture from file path
TTF_Font* const j1Fonts::Load(const char* path, int size)
{
	TTF_Font* font = TTF_OpenFont(path, size);

	if (font == NULL)
	{
		LOG("Could not load TTF font with path: %s. TTF_OpenFont: %s", path, TTF_GetError());
	}
	else
	{
		LOG("Successfully loaded font %s size %d", path, size);
		fonts.add(font);
	}

	return font;
}

// Print text using font

SDL_Texture * j1Fonts::Print(const char * text, SDL_Color color, _TTF_Font * font)
{
	SDL_Texture* ret = NULL;
	SDL_Surface* surface = TTF_RenderText_Blended((font) ? font : default, text, color);

	if (surface == NULL)
	{
		LOG("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		ret = App->tex->LoadSurface(surface);
		SDL_FreeSurface(surface);
	}

	return ret;
}

// calculate size of a text
bool j1Fonts::CalcSize(const char* text, int& width, int& height, _TTF_Font* font) const
{
	bool ret = false;

	if (TTF_SizeText((font) ? font : default, text, &width, &height) != 0)
		LOG("Unable to calc size of text surface! SDL_ttf Error: %s\n", TTF_GetError());
	else
		ret = true;

	return ret;
}