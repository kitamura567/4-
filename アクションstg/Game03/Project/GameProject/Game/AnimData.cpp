#include "AnimData.h"


static TexAnim playerIdle[] = {
	
	{ 1,2 },
	
	
};
static TexAnim playerRun[] = {
	
	{ 8,2 },
	{ 7,2 },
	{ 6,2 },
	
	
};
static TexAnim playerJumpUp[] = {
	{ 8,4 },
	{ 7,4 },
	{ 6,4 },

};
static TexAnim playerJumpDown[] = {
	{ 8,4 },
	{ 7,4 },
	{ 6,4 },

};
static TexAnim playerAttack01[] = {
	{ 40,3 },
	{ 41,3 },
	{ 42,3 },
	{ 43,2 },
	{ 44,2 },
	{ 45,3 },
	{ 46,4 },
};
static TexAnim playerAttack01End[] = {
	{ 48,4 },
	{ 49,4 },
	{ 50,4 },
	{ 51,4 },
	{ 52,4 },
};
static TexAnim playerAttack02[] = {
	{ 56,6 },
	{ 57,6 },
	{ 58,4 },
	{ 59,2 },
	{ 60,2 },
	{ 61,2 },
	{ 62,4 },
};
static TexAnim playerAttack02End[] = {
	{ 64,4 },
	{ 65,4 },
	{ 66,4 },
	{ 67,4 },
	{ 68,4 },
};
static TexAnim playerAttack03[] = {
	{ 72,6 },
	{ 73,6 },
	{ 74,4 },
	{ 75,4 },
	{ 76,3 },
	{ 77,2 },
	{ 78,2 },
	{ 79,4 },
};
static TexAnim playerAttack03End[] = {
	{ 80,4 },
	{ 81,4 },
	{ 82,4 },
	{ 83,4 },
};

static TexAnim playerDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim playerDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim playerDeath[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,8 },
	{ 3,4 },
	{ 4,4 },
	{ 5,4 },
	{ 6,4 },
	{ 7,4 },
};

static TexAnim playerDown[] = {
	{ 104,4 },
	{ 105,4 },
	{ 106,4 },
	{ 107,4 },
	{ 108,4 },
};
static TexAnim playerDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim playerWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim playerGuard[] = {
	{ 120,4 },
	{ 121,4 },
	{ 122,4 },
};
static TexAnim playerGuardEnd[] = {
	{ 122,4 },
	{ 121,4 },
	{ 120,4 },
};
static TexAnim playerCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,90 },
};
static TexAnim playerCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim playerExtAttack01[] = {
	{ 144,4 },
	{ 145,4 },
	{ 146,12 },
	{ 147,2 },
	{ 148,2 },
	{ 149,2 },
	{ 150,16 },
};
static TexAnim playerExtAttack01End[] = {
	{ 151,4 },
	{ 152,4 },
};
static TexAnim playerExtAttack02[] = {
	{ 160,2 },
	{ 161,2 },
	{ 162,2 },
	{ 163,2 },
	{ 164,2 },
	{ 165,2 },
	{ 166,2 },
	{ 167,2 },
	{ 168,2 },
};
static TexAnim playerExtAttack02End[] = {
	{ 169,16 },
	{ 170,4 },
	{ 171,4 },
};
static TexAnim playerStep[] = {
	{ 120,4 },
	{ 121,4 },
	{ 122,4 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerRun),
	ANIMDATA(playerJumpUp),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerAttack01End),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerAttack02End),
	ANIMDATA(playerAttack03),
	ANIMDATA(playerAttack03End),
	ANIMDATA(playerDamage),
	ANIMDATA(playerDamageEnd),
	ANIMDATA(playerDeath),
	ANIMDATA(playerDown),
	ANIMDATA(playerDownGround),
	ANIMDATA(playerWakeup),
	ANIMDATA(playerGuard),
	ANIMDATA(playerGuardEnd),
	ANIMDATA(playerCrash),
	ANIMDATA(playerCrash01End),
	ANIMDATA(playerExtAttack01),
	ANIMDATA(playerExtAttack01End),
	ANIMDATA(playerExtAttack02),
	ANIMDATA(playerExtAttack02End),
	ANIMDATA(playerStep),
};

static TexAnim enemyDown[] = {
	
	{ 0,2 },
	
};
static TexAnim enemyUp[] = {
	{ 4,2 },
	
};
static TexAnim enemyLeft[] = {
	{ 8,0 },
};
static TexAnim enemyRight[] = {
	{ 12,0 },
};

static TexAnim enemyAttack01[] = {
	{ 40,4 },
	{ 41,4 },
	{ 42,4 },
	{ 43,8 },
	{ 44,2 },
	{ 45,3 },
	{ 46,3 },
	{ 47,3 },
};
static TexAnim enemyAttack01End[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim enemyAttack02[] = {
	{ 0,0 },
};
static TexAnim enemyAttack02End[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03[] = {
	{ 0,0 },
};
static TexAnim enemyAttack03End[] = {
	{ 0,0 },
};
static TexAnim enemyDamage[] = {
	{ 88,2 },
	{ 89,2 },
	{ 90,2 },
	{ 91,2 },
};
static TexAnim enemyDamageEnd[] = {
	{ 92,2 },
	{ 93,2 },
	{ 94,2 },
	{ 95,2 },
};
static TexAnim enemyDeath[] = {
	{ 96,4 },
	{ 97,4 },
	{ 98,8 },
	{ 99,4 },
	{ 100,4 },
	{ 101,4 },
	{ 102,4 },
	{ 103,4 },
};


static TexAnim enemyDownGround[] = {
	{ 109,4 },
	{ 110,4 },
	{ 111,4 },
};
static TexAnim enemyWakeup[] = {
	{ 112,4 },
	{ 113,4 },
	{ 114,4 },
	{ 115,4 },
	{ 116,4 },
	{ 117,4 },
	{ 118,4 },
};
static TexAnim enemyGuard[] = {
	{ 0,4 },
};
static TexAnim enemyGuardEnd[] = {
	{ 0,4 },
};
static TexAnim enemyCrash[] = {
	{ 128,4 },
	{ 129,4 },
	{ 130,4 },
	{ 131,60 },
};
static TexAnim enemyCrash01End[] = {
	{ 131,4 },
	{ 130,4 },
	{ 129,4 },
	{ 128,4 },
};
static TexAnim enemyExt01Attack[] = {
	{ 0,4 },
};
static TexAnim enemyExtAttack01End[] = {
	{ 0,4 },
};
TexAnimData enemy_anim_data[] = {
	ANIMDATA(enemyDown),
	ANIMDATA(enemyLeft),
	ANIMDATA(enemyRight),
	ANIMDATA(enemyUp),
};
static TexAnim _effect_guard[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },

};
TexAnimData effect_guard_anim_data[] = {
	ANIMDATA(_effect_guard),
};

static TexAnim _effect_shothit[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	
};
TexAnimData effect_shothit_anim_data[] = {
	ANIMDATA(_effect_shothit),
};

static TexAnim _effect_blood[] = {
	{ 0,1 },
	{ 1,1 },
	{ 2,1 },
	{ 3,1 },
};
TexAnimData effect_blood_anim_data[] = {
	ANIMDATA(_effect_blood),
};
static TexAnim gun[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	
};
TexAnimData gun_anim_data[] = {
	ANIMDATA(gun),
};
static TexAnim _effect_smoke[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_smoke_anim_data[] = {
	ANIMDATA(_effect_smoke),
};

static TexAnim _effect_bomb[] = {
	{ 0,2 },
	{ 1,2 },
	{ 2,2 },
	{ 3,2 },
	{ 4,2 },
};
TexAnimData effect_bomb_anim_data[] = {
	ANIMDATA(_effect_smoke),
};
static TexAnim _effect_slash[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	{ 4,4 },
};
TexAnimData effect_slash_anim_data[] = {
	ANIMDATA(_effect_slash),
};