#include <Novice.h>

#include"struct.h"

//class
#include"SceneManager.h"
#include"BaseScene.h"


const char kWindowTitle[] = "LC1A_12_クリハラ_ケイタ_タイトル";


 const int kWindowSizeX = 1280;
 const int kWindowSizeY = 720;
 bool BaseScene::isChange_;


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowSizeX, kWindowSizeY);

	//インスタンスを生成
	SceneManager *sceneManager = new SceneManager;
	

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		sceneManager->CangeScene(sceneManager->scene_);
		sceneManager->Update(keys,preKeys);
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		sceneManager->Draw();

		Novice::ScreenPrintf(0, 0, "%d", sceneManager->scene_);
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
