#include "ScenePlay.h"

ScenePlay::ScenePlay() {

	
		player_ = new Player();
		enemy_ = new Enemy(500, 100);
		playerBullet_ = new PlayerBullet();
		enemyBullet_ = new EnemyBullet();
		renditionBox_ = new RenditionBox();
		background_ = new BackGround();
		colligion_ = new Colligion();
	
}

void ScenePlay::Init() {

}

void ScenePlay::Update(char *keys,char*preKeys) {
	
	//背景動かす
	background_->Update();

	renditionBox_->ScalingUpdate();//演出ブロックの更新

	//画面遷移終わったら敵をスポーンさせる
	if (renditionBox_->GetIsEnd() == true) {
		enemy_->Spone();
	}

	if (enemy_->GetIsSponeEnd() == true) {

	}

	player_->Update(keys, preKeys);//プレイヤ―の更新
	enemy_->Update(player_->GetWorldPos());//敵の更新

	//当たり判定
	colligion_->PlayerEnemyColligion(*player_,*enemy_);
	colligion_->BulletColligion(*playerBullet_, *enemy_);
	colligion_->BulletColligion(*enemyBullet_, *player_);
	
}

void ScenePlay::Draw() {
	background_->Draw();
	player_->Draw();
	enemy_->Draw();
	renditionBox_->Draw();
}
