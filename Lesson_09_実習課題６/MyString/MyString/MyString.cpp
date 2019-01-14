#define  _CRT_SECURE_NO_WARNINGS //おまじない。
#include "MyString.h"
#include <string>


MyString::MyString()
{
}


MyString::~MyString()
{
	//確保したメモリはちゃんと開放する！
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
}

void MyString::operator=(const char* str)
{
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
	//コピー元の文字列の長さを調べる。
	int len = strlen(str);

	//コピーすることが可能なメモリを動的に確保する。
	//malloc関数は確保するメモリのサイズを引数に受け取ります。
	//戻り値は、確保したメモリのアドレスを返してきます。
	m_string = (char*)malloc(len + 1);

	//文字列を確保したメモリにコピーする。
	strcpy(
		m_string,	//コピー先のメモリの先頭アドレス。
		str			//コピー元の文字列の先頭アドレス。
	);
}
void MyString::Copy(const char* str)
{
	if (m_string != nullptr) {
		//m_stringにアドレスが入っていたら開放する。
		free(m_string);
	}
	//コピー元の文字列の長さを調べる。
	int len = strlen(str);

	//コピーすることが可能なメモリを動的に確保する。
	//malloc関数は確保するメモリのサイズを引数に受け取ります。
	//戻り値は、確保したメモリのアドレスを返してきます。
	m_string = (char*)malloc( len + 1 );

	//文字列を確保したメモリにコピーする。
	strcpy(
		m_string,	//コピー先のメモリの先頭アドレス。
		str			//コピー元の文字列。
	);
}
void MyString::Add(const char* str)
{
	///////////////////////////////////////////////////// 
	//�@ 連結後の文字列の長さを計算する。
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//元の文字列の長さを加算する。
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//�A 新しい文字列を記憶するための、メモリを確保する。
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc( len + 1 );

	/////////////////////////////////////////////////////
	//�B 文字列連結
	/////////////////////////////////////////////////////
	//まず、newStrにm_stringが指している文字列をコピーする。
	strcpy(newStr, m_string);
	//続いて文字列を連結させる。
	strcat(newStr,str);

	/////////////////////////////////////////////////////
	//�C m_stringが指している古い文字列を解放して、
	//   新しい文字列のアドレスを代入する。
	/////////////////////////////////////////////////////
	//古い文字列のアドレスを解放する。
	free(m_string);
	//m_string新しく確保した
	//文字列のアドレスを代入する。
	m_string = newStr;
}
//+=演算子をオーバーロード。
void MyString::operator+=(const char* str)
{
	///////////////////////////////////////////////////// 
	//�@ 連結後の文字列の長さを計算する。
	///////////////////////////////////////////////////// 
	int len = strlen(str);
	//元の文字列の長さを加算する。
	len += strlen(m_string);

	/////////////////////////////////////////////////////
	//�A 新しい文字列を記憶するための、メモリを確保する。
	/////////////////////////////////////////////////////
	char* newStr = (char*)malloc(len + 1);

	/////////////////////////////////////////////////////
	//�B 文字列連結
	/////////////////////////////////////////////////////
	//まず、newStrにm_stringが指している文字列をコピーする。
	strcpy(newStr, m_string);
	//続いて文字列を連結させる。
	strcat(newStr, str);

	/////////////////////////////////////////////////////
	//�C m_stringが指している古い文字列を解放して、
	//   新しい文字列のアドレスを代入する。
	/////////////////////////////////////////////////////
	//古い文字列のアドレスを解放する。
	free(m_string);
	//m_string新しく確保した
	//文字列のアドレスを代入する。
	m_string = newStr;
}
//==演算子をオーバーロード。
bool MyString::operator==(const char* str)
{
	//文字列の比較はstrcmpを使う。
	int result = strcmp(m_string, str);

	if (result == 0) {
		//strcmpの戻り値が0なら文字列は等しいので、trueを返す。
		return true;
	}
	//ここに来たということは、等しくないということなので
	//falseを返す。
	return false;
}
/// <summary>
/// m_stringが指している文字列の長さを求める関数。
/// </summary>
/// <remarks>
/// m_stringが指している文字列が"Hello"であれば、5を返します。
/// m_stringが指している文字列が"Hello World"であれば10を返します。
/// </remarks>
/// <returns>m_stringが指している文字列の長さ</returns>
int MyString::Length()
{
	return 0;
}

/// <summary>
/// m_stringが指している文字列から、引数で渡された
/// 文字(ch)がある位置を返す関数です。
/// 位置は一番最初に見つかった位置を返します。
/// なお、見つからなかった場合は-1を返してください。
/// </summary>
/// <remarks>
/// m_stringに"Hello"が設定されている場合に、
///		・chに'l'が渡された場合は2を返します。
///		・chに'H'が渡された場合は0を返します。
///		・chに'a'が渡された場合は-1を返します。
/// 　　　→見つからなかった。
/// </remarks>
/// <param name="ch">検索する文字</param>
/// <returns>
/// 文字が見つかった位置。
/// 見つからなかった場合は、-1を返します。
/// </returns>
int MyString::Search(char ch)
{
	return -100;
}
/// <summary>
/// m_stringが指している文字列に、指定された場所(insertPos)に指定された文字(ch)を挿入します。
/// </summary>
/// <remarks>
/// m_stringに"Hello"が設定されている場合に、
///		・insertPosに2、chに'a'が渡された場合は、m_stringが指している文字列は"Heallo"になります。
///		・insertPosに0、chに'b'が渡された場合は、m_stringが指している文字列は"bHello"になります。
/// </remarks>
/// <param name="insertPos"></param>
/// <param name="ch"></param>
void MyString::Insert(int insertPos, char ch)
{
	return;
}