// ConsoleApplication1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//3Dモデルを描画するクラスの疑似コード。
class SkinModelRender {
	int indexBuffer[6]; //インデックスバッファ
public:
	SkinModelRender()
	{
		//適当にインデックスバッファに値を埋める。
		//特にこれに意味はない。
		for (int i = 0; i < 6; i++) {
			indexBuffer[i] = i;
		}
	}
	//3Dモデルを描画する関数。
	void Draw()
	{
		cout << "プレイヤーの描画すたーと\n";
		for (int i = 0; i < 6; i++) {
			cout << indexBuffer[i] << "\n";
		}
		cout << "プレイヤーの描画しゅうりょう\n";
	}
};
//プレイヤークラスの疑似コード。
class Player {
	SkinModelRender* skinModelRender;
public:
	Player()
	{
		//スキンモデルレンダーのインスタンスを作成。
		skinModelRender = new SkinModelRender;
	}
	~Player()
	{
		//ちゃんと後始末を行う。
		delete skinModelRender;
	}
	void Draw()
	{
		//プレイヤーの絵を描画。
		skinModelRender->Draw();
	}
};
//
void DrawPlayer(Player& pl) 
{
	pl.Draw();
}
//メイン関数。
int main()
{
	Player p1;	//プレイヤー１
	//ここでははちゃんと実行できる。
	DrawPlayer(p1);
	DrawPlayer(p1); //ここでクラッシュが発生する！

	return 0;
}

