#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は40人の成績をランダムに生成して、それを
	//score配列に格納します。
	//この配列を利用しての平均点を計算して、avgに代入しなさい。
	//そしてその結果をAnswer関数に渡しなさい。
	//答えがあっていれば、正解のメッセージボックスが表示されます。
	//なお、小数点は切り捨てになります。
	int score[40];
	GenerateScore(score);

	int avg = 0;


	//答え合わせ。
	SubmissionAnswer(avg);
	return 0;
}