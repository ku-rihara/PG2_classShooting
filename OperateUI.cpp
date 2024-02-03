#include "OperateUI.h"


OperateUI::OperateUI() {

	space_.Handle = Novice::LoadTexture("./Resources/space_small.png");
	wasd_.Handle = Novice::LoadTexture("./Resources/wasd.png");

}


void OperateUI::Draw() {
	Novice::DrawBox(900, 0, 380, 720, 0, BLACK, kFillModeSolid);
	Novice::DrawSprite(1000, 150, wasd_.Handle, 1, 1, 0, WHITE);
	Novice::DrawSprite(1000, 300, space_.Handle, 1, 1, 0, WHITE);
}