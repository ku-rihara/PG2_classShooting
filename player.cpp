#include "player.h"


Player::Player() {

	Init();

}

void Player::Init() {
	
	velocity_ = {};
	acceleration_ = {};
	scale_ = {1,1};
	size_ = {};
	theta_ = 0;

	//頂点とマトリックス
	vertexPos_ = {};
	screenVertex_ = {};
	localVertex_ = {};
	matrix_ = {};
	wvpVpMatrix_ = {};
}

void Player::Update(Camela& camela) {

	BaseObj::RenderingPipeline(camela);
}

void Player::Draw() {

}