#include <iostream>
#include "lib.h"

using namespace std;

int main()
{
	//GenerateScore関数は変数aとbにランダムな数値を代入します。
	//aとbの比較を行って、変数cに大きいほうの値を代入しなさい。
	int a, b;
	GenerateScore(a, b);
	
	int c = 0;



	//答え合わせ。
	SubmissionAnswer(c);
	return 0;
}