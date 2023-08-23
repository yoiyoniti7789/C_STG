#pragma once

#include "DirectXCommon.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"
#include "Input.h"
#include "Audio.h"

class Title 
{
public:
	Title();
	~Title();

	void Initialize();
	int Update();
	void Draw2DNear();

	void Start();

private:
	uint32_t textureHandleTitle_ = 0;
	Sprite* spriteTitle_ = nullptr;

	uint32_t textureHandleEnter_ = 0;
	Sprite* spriteEnter_ = nullptr;

	Input* input_ = nullptr;

	int timer_ = 0;


	Audio* audio_ = nullptr;
	uint32_t soundataHandleBGM_ = 0;
	uint32_t voiceHandleBGM_ = 0;
};
