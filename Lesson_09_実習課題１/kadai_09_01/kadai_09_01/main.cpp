// kadai_09_01.cpp : アプリケーションのエントリ ポイントを定義します。
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

	//実習１　クラスの合計点を計算して出力するプログラムを作成しなさい。

    return 0;
}

