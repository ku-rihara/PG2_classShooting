#include "ScenePlay.h"

ScenePlay::ScenePlay() {

	player_ = new Player();
	enemy_ = new Enemy(500,100);
	renditionBox_ = new RenditionBox();

}

void ScenePlay::Init() {

}

void ScenePlay::Update(char *keys,char*preKeys) {
	/*background1_ += 1;
	background2_ += 1;
	if (background1_ == 720) {
		background1_ = 0;
		background2_ = -720;
	}*/

	renditionBox_->ScalingUpdate();//演出ブロックの更新

	//画面遷移終わったら敵をスポーンさせる
	if (renditionBox_->GetIsEnd() == true) {
		enemy_->Spone();
	}

	if (enemy_->GetIsSponeEnd() == true) {

	}

	player_->Update(keys, preKeys);//プレイヤ―の更新
	enemy_->Update(player_->GetWorldPos());//敵の更新
}

void ScenePlay::Draw() {

	player_->Draw();
	enemy_->Draw();
	renditionBox_->Draw();
}
