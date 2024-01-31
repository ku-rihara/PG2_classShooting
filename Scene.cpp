#include "Scene.h"

Scene::Scene() {

	player_ = new Player();
	enemy_ = new Enemy(500,100);
	renditionBox_ = new RenditionBox();

	Init();
	backGround.Handle = Novice::LoadTexture("./Resources/backGround.png");
}

void Scene::Init() {
	sceneNo_ = TITLE;
	isChange_ = false;
	player_->Init();
	enemy_->Init(500,100);
	background1_=0;
	background2_=-720;
}

void Scene::Update(char*keys,char*preKeys) {

	switch (sceneNo_) {

	case TITLE://タイトルの処理-----------------------------------------------------------------

		//背景動かす
		background1_ += 1;
		background2_ += 1;
		if (background1_ == 720) {
			background1_ = 0;
			background2_ = -720;
		}

		//スペースキーでシーンチェンジ
		if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0&&isChange_==false) {
			isChange_ = true;
		}

		if (isChange_ == true) {
			renditionBox_->ScalingUpdate();
			if (renditionBox_->GetIsReturn() == true) {
				sceneNo_ = PLAY;
			}
		}
		break;
		
	case PLAY://ゲームプレイ中の処理-------------------------------------------------------------
		//背景動かす
		background1_ += 1;
		background2_ += 1;
		if (background1_ == 720) {
			background1_ = 0;
			background2_ = -720;
		}

		renditionBox_->ScalingUpdate();//演出ブロックの更新

		//画面遷移終わったら敵をスポーンさせる
		if (renditionBox_->GetIsEnd() == true) {
			enemy_->Spone();
		}

		if (enemy_->GetIsSponeEnd() == true) {

		}

		player_->Update(keys,preKeys);//プレイヤ―の更新
		enemy_->Update(player_->GetWorldPos());//敵の更新
		

		break;

		//クリア画面の処理
	case CLEAR:

		break;

	}
}

void Scene::Draw() {


	switch (sceneNo_) {

	case TITLE:
		Novice::DrawSprite(0, background1_, backGround.Handle, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, background2_, backGround.Handle, 1, 1, 0, WHITE);
		renditionBox_->Draw();
		break;

	case PLAY:

		Novice::DrawSprite(0, background1_, backGround.Handle, 1, 1, 0, WHITE);
		Novice::DrawSprite(0, background2_, backGround.Handle, 1, 1, 0, WHITE);

		player_->Draw();
		enemy_->Draw();
		renditionBox_->Draw();
		break;

	case CLEAR:

		break;

	}
}