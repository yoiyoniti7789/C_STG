#include "Title.h"

Title::Title() {}

Title::~Title() 
{
	delete spriteTitle_;
}

void Title::Initialize() 
{
	textureHandleTitle_ = TextureManager::Load("title.png");
	spriteTitle_ = Sprite::Create(textureHandleTitle_, {0, 0});

	textureHandleEnter_ = TextureManager::Load("enter.png");
	spriteEnter_ = Sprite::Create(textureHandleEnter_, {400, 500});

	input_ = Input::GetInstance();

	audio_ = Audio::GetInstance();
	soundataHandleBGM_ = audio_->LoadWave("Audio/Ring05.wav");

	Start();
}

int Title::Update() 
{ 
	timer_++;

	if (input_->TriggerKey(DIK_RETURN)) 
	{
		audio_->StopWave(voiceHandleBGM_);
		return 0;
	}

	return 1;
}

void Title::Draw2DNear() 
{ 
	spriteTitle_->Draw();

	if (timer_ % 40 >= 20) 
	{
		spriteEnter_->Draw();
	}
}

void Title::Start() 
{ 
	voiceHandleBGM_ = audio_->PlayWave(soundataHandleBGM_,true);
}
