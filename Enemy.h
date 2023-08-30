#pragma once

#include "DirectXCommon.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "MathUtilityForText.h"
#include "Input.h"
#include <time.h>

class Enemy 
{
public:
	Enemy();
	~Enemy();

	void Initialize(ViewProjection viewProjection);
	void Update(int gameTimer);
	void Draw3D();
	void Move(int gameTimer);
	void Born();
	float GetX() { return worldTransformEnemy_.translation_.x; }
	float GetY() { return worldTransformEnemy_.translation_.y; }
	float GetZ() { return worldTransformEnemy_.translation_.z; }
	int GetFlag() { return aliveFlag_; }
	void Hit() {aliveFlag_ = 2;}
	void JumpHit() { jumpSpeed_ = 1; };
	float GetX2() { return worldTransformEnemy2_.translation_.x; }
	float GetY2() { return worldTransformEnemy2_.translation_.y; }
	float GetZ2() { return worldTransformEnemy2_.translation_.z; }
	int GetFlag2() { return aliveFlag2_; }
	void Hit2() { aliveFlag2_ = 2; }
	void JumpHit2() { jumpSpeed2_ = 1; };
	void Start();
	void Jump();

private:
	ViewProjection viewProjection_;

	uint32_t textureHandleEnemy_ = 0;
	Model* modelEnemy_ = nullptr;
	WorldTransform worldTransformEnemy_;

	uint32_t textureHandleEnemy2_ = 0;
	Model* modelEnemy2_ = nullptr;
	WorldTransform worldTransformEnemy2_;

	Input* input_ = nullptr;

	int aliveFlag_ = 0;

	int aliveFlag2_ = 0;

	float xSpeed_ = 0;

	float xSpeed2_ = 0;

	float jumpSpeed_ = 0;

	float jumpSpeed2_ = 0;
};
