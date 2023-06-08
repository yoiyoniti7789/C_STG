#pragma once

#include "DirectXCommon.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"

class Stage
{
public:
	Stage();
	~Stage();

	void Initialize(ViewProjection viewProjection);
	void Update();
	void Draw2DFar();
	void Draw3D();

private:
	uint32_t textureHandleBG_ = 0;
	Sprite* spriteBG_ = nullptr;

	ViewProjection viewProjection_;

	uint32_t textureHandleStage_ = 0;
	Model* modelStage_ = nullptr;
	WorldTransform worldTransformStage_;

};
