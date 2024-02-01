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

	renditionBox_->ScalingUpdate();//���o�u���b�N�̍X�V

	//��ʑJ�ڏI�������G���X�|�[��������
	if (renditionBox_->GetIsEnd() == true) {
		enemy_->Spone();
	}

	if (enemy_->GetIsSponeEnd() == true) {

	}

	player_->Update(keys, preKeys);//�v���C���\�̍X�V
	enemy_->Update(player_->GetWorldPos());//�G�̍X�V
}

void ScenePlay::Draw() {

	player_->Draw();
	enemy_->Draw();
	renditionBox_->Draw();
}
