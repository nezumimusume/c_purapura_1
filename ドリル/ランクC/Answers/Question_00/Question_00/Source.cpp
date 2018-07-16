#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は40人の成績をランダムに生成して、それを
	//score配列に格納します。
	//この配列を利用してのクラスの合計点を計算して、sumに代入しなさい。
	//そしてその結果をAnswer関数に渡しなさい。
	//答えがあっていれば、正解のメッセージボックスが表示されます。
	//なお、小数点は切り捨てになります。
	int score[40];
	GenerateScore(score);
	
	int sum = 0;
	for (int i = 0; i < 40; i++) {
		sum += score[i];
	}
	//答え合わせ。
	SubmissionAnswer(sum);
	return 0;
}