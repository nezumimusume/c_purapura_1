// main.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	//乱数を初期化。
	srand(time(NULL));
	
	int score[40];

	//40人分の点数をランダムに作成する。
	for (int i = 0; i < 40; i++) {
		score[i] = rand() % 101;	//0～100までの点数をランダムに作る。
	}

	//クラスの合計点を計算。
	int goukeiTen = 0;
	for (int i = 0; i < 40; i++) {
		goukeiTen += score[i];
	}
	cout << "クラスの合計点は" << goukeiTen << "です。\n";
	
	//課題２　クラスの平均点を計算して、それを表示しなさい。
    return 0;
}

