#include "ScenePlay.h"

ScenePlay::ScenePlay() {

		player_ = new Player();
		enemy_ = new Enemy();
		renditionBox_ = new RenditionBox();
		background_ = new BackGround();
		colligion_ = new Colligion();
		operateUI_ = new OperateUI();
		Init();
}

void ScenePlay::Init() {
	
}

void ScenePlay::Update(char *keys,char*preKeys) {
	
	//背景動かす
	background_->Update();

	renditionBox_->ScaleDown();//演出ブロックの更新

	//画面遷移終わったら敵をスポーンさせる
	if (renditionBox_->GetIsSaleDownEnd() == true&&enemy_->GetIsSponeEnd()==false) {
		enemy_->Spone();
	}

	//敵がスポーンし終わったらゲーム開始
	if (enemy_->GetIsSponeEnd() == true||enemy_->GetIsResporn()==true) {

		player_->Update(keys, preKeys);//プレイヤ―の更新
		enemy_->Update(player_->GetWorldPos());//敵の更新
	}

	//プレイヤーが死んだらタイトルに戻る
	if (player_->GetIsDeath() == true) {
		renditionBox_->ScaleUp();
		if (renditionBox_->GetIsScaleUpEnd() == true) {
			BaseScene::isChange_ = true;
			BaseScene::isDecrement_ = true;
		}
	}

	//敵が死んだらクリア画面に行く
	if (enemy_->GetIsLose() == true) {
		renditionBox_->ScaleUp();
		if (renditionBox_->GetIsScaleUpEnd() == true) {
			BaseScene::isChange_ = true;
			BaseScene::isIncrement_ = true;
		}
	}

	//当たり判定
	if (enemy_->GetIsDeath() == false) {	
		colligion_->PlayerEnemyColligion(*player_, *enemy_);//敵と自機

		for (int i = 0; i < playerBulletMax; i++) {
			colligion_->BulletColligion(*player_->GetBullet(i), *enemy_);//プレイヤーの弾と敵
		}

		for (int i = 0; i < EnemyBulletMax; i++) {
			colligion_->BulletColligion(*enemy_->GetEnemyBullet(i), *player_);//敵の弾とプレイヤ―
		}
	}
		//レンダリングパイプライン
		player_->RenderingPipeline();
		enemy_->RenderingPipeline();
}

void ScenePlay::Draw() {
	background_->Draw();
	enemy_->Draw();
	player_->Draw();
	operateUI_->Draw();
	renditionBox_->Draw();
}
