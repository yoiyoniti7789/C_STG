#include "Stage.h"

Stage::Stage() {}

Stage::~Stage() 
{ 
	delete spriteBG_;
	delete modelStage_;
}

void Stage::Initialize(ViewProjection viewProjection) {
	viewProjection_ = viewProjection;

	textureHandleBG_ = TextureManager::Load("bg.jpg");
	spriteBG_ = Sprite::Create(textureHandleBG_, {0, 0});

	textureHandleStage_ = TextureManager::Load("stage2.jpg");
	modelStage_ = Model::Create();
	for (int i = 0; i < 20;i++) {
		worldTransformStageTable_[i].Initialize();
	}
	for (int i = 0; i < 20; i++) {
		worldTransformStageTable_[i].translation_ = {0.0f, -1.5f, 2.0f * i - 5};
		worldTransformStageTable_[i].scale_ = {4.5f, 1, 1};

		worldTransformStageTable_[i].matWorld_ = MakeAffineMatrix(
		    worldTransformStageTable_[i].scale_, 
			worldTransformStageTable_[i].rotation_,
		    worldTransformStageTable_[i].translation_);

		worldTransformStageTable_[i].TransferMatrix();
	}
}

void Stage::Update() 
{
	for (int i = 0; i < 20; i++) {
		worldTransformStageTable_[i].translation_.z -= 0.1f;

		if (worldTransformStageTable_[i].translation_.z < -5) {
			worldTransformStageTable_[i].translation_.z += 40;

		}
		worldTransformStageTable_[i].matWorld_ = MakeAffineMatrix(
		    worldTransformStageTable_[i].scale_, 
			worldTransformStageTable_[i].rotation_,
		    worldTransformStageTable_[i].translation_);

		worldTransformStageTable_[i].TransferMatrix();
	}
}

void Stage::Draw2DFar() 
{ 
	spriteBG_->Draw(); 
}

void Stage::Draw3D() 
{
	for (int i = 0; i < 20; i++) {
		modelStage_->Draw(worldTransformStageTable_[i], viewProjection_, textureHandleStage_);
	}
}
