#ifndef __j1PLAYER_1_H__
#define __j1PLAYER_1_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Player.h"

class Animation;
class j1Render;
class j1Input;
class j1Entity;

struct Collider;
struct SDL_Texture;

class j1Player1 : public j1Player		//j1Player1 inherits from j1Player. This class is used to differentiatie between players.
{
public://methods

	j1Player1(int x, int y, ENTITY_TYPE type);
	// Destructor
	virtual ~j1Player1();

	bool Init();

	bool Awake(pugi::xml_node&);

	bool Start();

	bool PreUpdate();

	bool Update(float dt, bool doLogic);

	bool PostUpdate();

	bool CleanUp();

public: //P1 Variables
	void TeleportP2ToP1();										//Moves P2 directly in front of P1. It takes into account where P1 is looking at.
	void RespawnP1ToP2();										//Moves P1 directly behind P2 on death.
	void SetPlayer1Position();									//Sets P1's origin position in a map. Takes into account which map is being loaded (firstMap and secondMap).
	//void ApplyGravity(float dt);
	void LivesCheck(int lives);									//Checks if the player has any lives left.
	void OnCollision(Collider* C1, Collider* C2);				//Collision Logic Handling.

	bool Load(pugi::xml_node &node);							//Loading from xml file.
	bool Save(pugi::xml_node &node) const;						//Saving to xml file.
	void Restart();												//Resets P1's position to where P1 started the level. 
	void GodModeInput();										//Enables / Disables the God Mode.

	//bool LoadPlayer1Textures();								//Loads P1's textures on screen.
};

#endif // __j1Player_1_H__