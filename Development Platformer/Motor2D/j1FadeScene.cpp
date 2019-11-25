#include <math.h>
#include "p2Log.h"
#include "j1App.h"
#include "j1FadeScene.h"
#include "j1Render.h"
#include "j1Scene.h"
#include "j1Window.h"
#include "j1Player1.h"
#include "j1Player2.h"
#include "j1Audio.h"
#include "j1Map.h"
#include "j1Collisions.h"
#include "j1EntityManager.h"

#include "SDL\include\SDL_render.h"
#include "SDL\include\SDL_timer.h"


j1Fade_Scene::j1Fade_Scene()
{
}

j1Fade_Scene::~j1Fade_Scene()
{}

bool j1Fade_Scene::Awake(pugi::xml_node&)
{
	screen = { 0, 0, App->win->width*App->win->scale, App->win->height*App->win->scale };
	return true;
}

bool j1Fade_Scene::Start()
{
	LOG("Preparing Fade Screen");
	SDL_SetRenderDrawBlendMode(App->render->renderer, SDL_BLENDMODE_BLEND);
	return true;
}

bool j1Fade_Scene::Update(float dt)
{
	if (current_step == fade_step::none)
	{
		return true;
	}

	uint now = SDL_GetTicks() - start_time;
	float normalized = 1.0f < ((float)now / (float)total_time) ? 1.0f : ((float)now / (float)total_time);


	switch (current_step)
	{
		case fade_step::fade_to_black:
		{
			if (now >= total_time) //Point where the screen is totally black, and the new map is loaded.
			{
				ChangeMap(mapName);								//Here the map is changed
				
				total_time += total_time;
				start_time = SDL_GetTicks();
				fading = false;
				current_step = fade_step::fade_from_black;
			}
		}
		break;

		case fade_step::fade_from_black:
		{
			normalized = 1.0f - normalized;

			if (now >= total_time)
			{
				current_step = fade_step::none;
			}

		}
		break;
	}

	SDL_SetRenderDrawColor(App->render->renderer, 0, 0, 0, (Uint8)(normalized * 255.0f));
	SDL_RenderFillRect(App->render->renderer, &screen);

	return true;
}

bool j1Fade_Scene ::FadeToBlack(const char* mapname, float time)
{
	bool ret = false;

	mapName = mapname;

	if (current_step == fade_step::none)
	{
		current_step = fade_step::fade_to_black;
		start_time = SDL_GetTicks();
		total_time = (Uint32)(time * 0.5f * 1000.0f);
		ret = true;
	}

	App->entityManager->player->Restart();					//Returns P1 to the starting position of the map.
	App->entityManager->player2->Restart();					//Returns P2 to the starting position of the map.
	
	return ret;
}

bool j1Fade_Scene::ChangeMap(const char* newMap)
{
	bool ret = true;

	//Put this on scene CleanUp()
	App->scene->CleanUp();

	//App->collisions->collider_list.clear();					//Deletes all colliders from memory.		//Change for an array. To Clear set the collider_delete bool to true for all colliders.
	//App->entityManager->player->CleanUp();					//Deletes all data related to P1. 
	//App->entityManager->player2->CleanUp();					//Deletes all data related to P2.
	////App->audio->CleanUp();

	//App->map->CleanUp();						//Deletes everything related with the map from memory. (Tilesets, Layers and ObjectGroups)

	App->map->Load(newMap);						//Loads a specified map
	App->collisions->LoadColliderFromMap();		//Load Collisions
	
	//App->entityManager->CreatePlayers();
	App->entityManager->player->Start();		//Load / Reset P1	//REVISE THIS HERE. Should players be loaded like this?
	App->entityManager->player2->Start();		//Load / Reset P2
	//App->entityManager->SpawnEnemies();
	//App->scene->Start();						//This breaks the game

	return ret;
}

bool j1Fade_Scene::IsChanging() const
{
	return current_step != fade_step::none;
}