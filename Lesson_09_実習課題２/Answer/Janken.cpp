// Janken.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <iostream>
#include <random>

using namespace std;

void DispResultMessage(int result)
{
	//勝敗に応じたメッセージを格納する
	const char* message[] = {
		"あなたの勝ちです\n\n",
		"引き分けです\n\n",
		"あなたの負けです\n\n",
	};
	cout << message[result];
}
void DispComNoTe(int te) {
	const char* str[] = {
		"コンピューターの手はグーです。\n",
		"コンピューターの手はチョキです。\n",
		"コンピューターの手はパーです。\n",
	};
	cout << str[te];
}
void DispPlayerNoTe(int te) {
	const char* str[] = {
		"プレイヤーの手はグーです。\n",
		"プレイヤーの手はチョキです。\n",
		"プレイヤーの手はパーです。\n",
	};
	cout << str[te];
}
int main()
{
	//メルセンヌツイスタアルゴリズムを使った乱数生成器を初期化する。
	random_device rnd;
	mt19937 mtRnd(rnd());

	//COMが入力した手が格納される。０はグー、１はチョキ、２はパー。
	int comNoTe = 0;		
	//プレイヤーが入力した手が格納される。０はグー、１はチョキ、２はパー。
	int playerNoTe = 0;
	while (true) {
		//comの手を0～2の範囲でランダムに決定する。
		comNoTe = mtRnd() % 3;

		//プレイヤーの手を入力させる。
		cout << "手を選択してください。0:グー、1:チョキ、2:パー\n";
		cin >> playerNoTe;

		//勝敗テーブル。
		//0だとあなたの勝ち、1だと引き分け、2だとあなたの負け。
		int resultTbl[3][3] = {
			{1, 0, 2 },
			{2, 1, 0 },
			{0, 2, 1 },
		};
		//Comの手を表示。
		DispComNoTe(comNoTe);
		//プレイヤーの手を表示。
		DispPlayerNoTe(playerNoTe);
		////////////////////////////////////////////////////////////
		//実習課題
		//DispResultMessage関数に渡す引数を考えよう！
		//この関数の仕様は下記のとおりです。
		//引数に0を渡すと、「あなたの勝ちです。」と表示されます。
		//引数に1を渡すと、「引き分けです。」と表示されます。
		//引数に2を渡すと、「あなたの負けです。」と表示されます。
		//
		//ヒント　resultTblを使います。
		//
		////////////////////////////////////////////////////////////
		DispResultMessage(resultTbl[playerNoTe][comNoTe]);
	}

	return 0;
}


