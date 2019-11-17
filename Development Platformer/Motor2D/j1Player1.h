#ifndef __j1PLAYER_1_H__
#define __j1PLAYER_1_H__

#include "j1Module.h"
#include "p2Point.h"
#include "j1Render.h"
#include "j1Input.h"
#include "Animation.h"

struct Collider;
struct SDL_Texture;

enum P1_State
{
	idle_P1,
	goingRight_P1,
	goingLeft_P1,
	crouching_P1,
	jumping_P1,
	falling_P1,
	boost_jump_P1,
	teleporting_P1,
	dying_P1
};

struct Player1
{
	p2Point<float>	position;				//Point with the position of P1 on the world.
	p2Point<float>	spawn_position;			//Keeps record of the first position(x, y) of P1 when spawns in the map.
	p2Point<float>	speed;					//P1's Speed Vector Variable. (Not actually declared as a vector but that is irrelevant to us right now)
	p2Point<float>	max_speed;				//P1's Cruiser Speed for both axis.
	p2Point<float>	acceleration;			//Sets how much time it takes P1 to reach Cruiser Speed horizontally and/or vertically.
	p2Point<float>	boost_jump;				//Sets how much vertical or horizontal impulse will P1 get.
	p2Point<int>	body_margin;			//Collider adjustment to the body of P1.
	p2Point<int>	sprite_measures;		//Sprite measurements (w, h), sets the width and height of the collider.. / Calculate center pos: mid_pos = p1.position.x +/- (p1.hitbox.width / 2). +/- depending on which side P1 is facing.
	float			gravity;				//Acceleration variable for jumps. Gravitational Pull.
	float			tpCdCount;				//Keeps track of how much time has passed since tp was last used.
	float			tpCdTime;				//Amount of cooldown time the tp skill has.
	float			godModeSpeed;			//P1's speed while in God Mode.
	float			frontflipStart;			//At which point of the boost jump the frontflip animation should start.
	float			frontflipEnd;			//At which point of the boost jump the frontflip animation should end.
	int				lives;					//Number of lives P1 has. It just defines how many times P1 can get impaled with spikes before having to restart the whole level over.
	int				max_lives;				//Maximum number of lives a player can have.


	bool			grounded;				//Keeps track of P1 and returns true when P1 is not jumping or falling.
	bool			airborne;				//Keeps track whether the player is on the air ir not.
	bool			flip;					//Keeps track of which direction P1's is looking at. Changes the sprite orientation when returns true.
	bool			isCrouching;			//Keeps track of the action P1 is performing. In this case crouching.
	bool			isJumping;				//Keeps track of the action P1 is performing. In this case jumping.
	bool			isBoostJumping;			//Keeps track of the action P1 is performing. In this case boost jumping.
	bool			item_activated;			//Keeps track of the items P1 interacts with.
	bool			isGoingRight;			//Keeps track of whether or not P1 is going to the right.
	bool			isGoingLeft;			//Keeps track of whether or not P1 is going to the left.
	bool			platformDrop;			//Keeps track whether or not P1 wants to drop from a platform.
	bool			tpInCd;					//Keeps track whether or not P1's tp is on cooldown.
	bool			isAlive;				//If P1 runs out of lives, then this bool returns false.
	bool			isDying;				//If P1 runs out of lives, then this bool returns true.
	bool			againstRightWall;		//If P1 is against a right wall then this is true.
	bool			againstLeftWall;		//If P1 is against a left  wall then this is true.
	bool			againstCeiling;			//If P1 is against a ceiling then this is true.
	bool			fading;					//Fade character when changing scenes.
	bool			GodMode;				//Defines whether GodMode is active or not.
	bool			switch_sprites;			//Defines which sprite will P1 have.
	
	//Animation Variables
	SDL_Texture* texture = nullptr;
	
	Animation	idle;				//Idle animation.
	Animation	running;			//Running animation.
	Animation	crouching;			//Crouching animation.
	Animation	jumping;			//Jumping animation.
	Animation	frontflip;			//Frontflip  animation.
	Animation	falling;			//Falling animation.
	Animation	boosted_jump;		//Boosted Jump Animation.
	Animation	death;				//Death animation.
	Animation*	current_animation;	//P1's current animation.

	//Sound Variables
	uint		jumpFX;				//Jump sfx.
	uint		deathFX;			//Death sfx.
	uint		duoFX;				//Boost Jump sfx.
	uint		goalFX;				//Goal Reached sfx.
	uint		tpFX;				//Teleport sfx.
	uint		activateFX;			//Item Activation sfx.
	

	SDL_Rect	HitBox;				//Rectangle that represents P1.
	SDL_Rect	atkHitBox;			//Rectangle that represents P1's attack reach / range.
	P1_State	state;				//Adds the state enum to P1's variables.
	Collider*	collider;			//Collider that will be assigned to P1. 
	Collider*	atkCollider;		//Collider that  will be assigned to P1 as it's attack reach.
};

class j1Player1 : public j1Module 
{
public://methods

	j1Player1();
	// Destructor
	virtual ~j1Player1();

	bool Init();

	bool Awake(pugi::xml_node&);

	bool Start();

	bool PreUpdate();

	bool Update(float dt);

	bool PostUpdate();

	bool CleanUp();

public: //P1 Variables
	
	Player1 p1;

	void TeleportP2ToP1();										//Moves P2 directly in front of P1. It takes into account where P1 is looking at.
	void RespawnP1ToP2();										//Moves P1 directly behind P2 on death.
	void LivesCheck(int lives);
	void TpCooldownCheck(float dt);								//Keeps track of the tp skill cooldown.
	void OnCollision(Collider* C1, Collider* C2);				//Collision Logic Handling.

	bool Load(pugi::xml_node &node);							//Loading from xml file.
	bool Save(pugi::xml_node &node) const;						//Saving to xml file.
	bool LoadPlayer1();											//Loads P1 on screen (Position, Colliders...)
	bool LoadPlayer1Properties(pugi::xml_node&);				//Loads P2's data from the config xml file.
	bool AddAnimationPushbacks();								//Adds P1's animation pushbacks.
	//bool LoadPlayer1Textures();								//Loads P1's textures on screen.
	void Restart();												//Resets P1's position to where P1 started the level. 
	void GodModeInput();										//Enables / Disables the God Mode.

	void SkillCooldown(bool& inCd, float& cdCounter, float& cdTime);		//Keeps track of any skill's cooldown. Revise --> Pass dt as an argument?

private:
	float half = 0.5f;
	float quarter = 0.25f;
	float threeFourths = 0.75f;
};

#endif __j1Player_1_H__