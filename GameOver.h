#pragma once

#include "DirectXCommon.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"
#include "Input.h"
#include "Title.h"
#include "GamePlay.h"
#include "Audio.h"

class GameOver 
{
public:
	GameOver();
	~GameOver();

	void Start();

	void Initialize();
	int Update();
	void Draw2DNear();

private:

	uint32_t textureHandlegameover_ = 0;
	Sprite* spritegameover_ = nullptr;

	uint32_t textureHandleEnter_ = 0;
	Sprite* spriteEnter_ = nullptr;

	Input* input_ = nullptr;

	int timer_ = 0;

	GamePlay* gameplay_ = nullptr;

	Audio* audio_ = nullptr;
	uint32_t soundataHandleGameOverBGM_ = 0;
	uint32_t voiceHandleBGM_ = 0;
	
};
