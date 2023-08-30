#include "Enemy.h"

Enemy::Enemy() {}

Enemy::~Enemy() 
{ 
	delete modelEnemy_;
	delete modelEnemy2_;
}

void Enemy::Initialize(ViewProjection viewProjection) 
{
	viewProjection_ = viewProjection;

	textureHandleEnemy_ = TextureManager::Load("enemy.png");

	modelEnemy_ = Model::Create();
	worldTransformEnemy_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy_.Initialize();

	textureHandleEnemy2_ = TextureManager::Load("enemy2.png");

	modelEnemy2_ = Model::Create();
	worldTransformEnemy2_.scale_ = {0.5f, 0.5f, 0.5f};
	worldTransformEnemy2_.Initialize();

	input_ = Input::GetInstance();

	srand((unsigned int)time(NULL));
}

void Enemy::Update(int gameTimer) {
	Move(gameTimer);
	Born();
	Jump();
	/// エネミー更新
	worldTransformEnemy_.matWorld_ = MakeAffineMatrix(
	    worldTransformEnemy_.scale_, 
		worldTransformEnemy_.rotation_,
	    worldTransformEnemy_.translation_);
	worldTransformEnemy_.TransferMatrix();

	worldTransformEnemy2_.matWorld_ = MakeAffineMatrix(
	    worldTransformEnemy2_.scale_, 
		worldTransformEnemy2_.rotation_,
	    worldTransformEnemy2_.translation_);
	worldTransformEnemy2_.TransferMatrix();

	worldTransformEnemy_.translation_.x = max(worldTransformEnemy_.translation_.x, -4);
	worldTransformEnemy_.translation_.x = min(worldTransformEnemy_.translation_.x, 4);
}

void Enemy::Move(int gameTimer) {
	if (aliveFlag_ == 1)
	{
		worldTransformEnemy_.rotation_.x -= 0.1f;
		worldTransformEnemy_.translation_.x -= xSpeed_;
		worldTransformEnemy_.translation_.z -= 0.3f;
		
		worldTransformEnemy2_.translation_.z -= 0.3f;
		worldTransformEnemy2_.translation_.x -= xSpeed2_;
		if (worldTransformEnemy_.translation_.x <= -4.0) {
			xSpeed_ *= -1;
		} else if (worldTransformEnemy_.translation_.x >= 4.0) {
			xSpeed_ *= -1;
		}
		if (worldTransformEnemy2_.translation_.x <= -4.0) {
			xSpeed2_ *= -1;
		} else if (worldTransformEnemy2_.translation_.x >= 4.0) {
			xSpeed2_ *= -1;
		}
		if (worldTransformEnemy_.translation_.z <= -5.0f) {
			aliveFlag_ = 0;
		}
		if (worldTransformEnemy2_.translation_.z <= -5.0f) {
			aliveFlag2_ = 0;
		}
		worldTransformEnemy_.translation_.z -= 0.1f;
		worldTransformEnemy_.translation_.z -= gameTimer / 1000.0f;

		worldTransformEnemy2_.translation_.z -= 0.1f;
		worldTransformEnemy2_.translation_.z -= gameTimer / 1000.0f;
	}
}

void Enemy::Born()
{
	if (rand()%10 == 0) {

		if (!aliveFlag_) {
			int x = rand() % 80;
			float x2 = (float)x / 10 - 4;

			worldTransformEnemy_.translation_.x = x2;
			worldTransformEnemy_.translation_.y = 0;
			worldTransformEnemy_.translation_.z = 40.0f;

			aliveFlag_ = 1;

			if (rand() % 2 == 0) {
				xSpeed_ = 0.1f;
			} else {
				xSpeed_ = -0.1f;
			}
		}
		if (!aliveFlag2_) {
			
			int x3 = rand() % 80;
			float x4 = (float)x3 / 10 - 4;
			worldTransformEnemy2_.translation_.x = x4;
			worldTransformEnemy2_.translation_.y = 1.0f;
			worldTransformEnemy2_.translation_.z = 40.0f;
			aliveFlag2_ = 1;

			if (rand() % 2 == 0) {
				xSpeed2_ = 0.1f;
			} else {
				xSpeed2_ = -0.1f;
			}
		}
		
	}
	
}


void Enemy::Start() 
{ 
	worldTransformEnemy_.translation_.z = 40.0f;
	worldTransformEnemy2_.translation_.z = 40.0f;

	aliveFlag_ = 0;
	aliveFlag2_ = 0;
}

void Enemy::Jump() 
{
	if (aliveFlag_ == 2) {

		worldTransformEnemy_.translation_.y += jumpSpeed_;

		jumpSpeed_ -= 0.1f;

		worldTransformEnemy_.translation_.x += xSpeed_ * 4;

		if (worldTransformEnemy_.translation_.y < -3) {
			worldTransformEnemy_.translation_.y = 0;
			aliveFlag_ = 0;
		}
	}
	if (aliveFlag2_ == 2) {

		worldTransformEnemy2_.translation_.y += jumpSpeed_;

		jumpSpeed_ -= 0.1f;

		worldTransformEnemy2_.translation_.x += xSpeed2_ * 4;

		if (worldTransformEnemy2_.translation_.y < -3) {
			worldTransformEnemy2_.translation_.y = 0;
			aliveFlag2_ = 0;
		}
	}
}

void Enemy::Draw3D() {

	if (!(!aliveFlag_)) {
		modelEnemy_->Draw(worldTransformEnemy_, viewProjection_, textureHandleEnemy_);
	}
	if (!(!aliveFlag2_)) {
		    modelEnemy2_->Draw(worldTransformEnemy2_, viewProjection_, textureHandleEnemy2_);
	}
}

