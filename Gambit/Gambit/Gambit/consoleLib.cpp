#include <iostream>
#include "consoleLib.h"

//�}�b�v�̍����B
const int FRAME_BUFFER_HEIGHT = 20;
//�}�b�v�̕��B
const int FRAME_BUFFER_WIDTH = 32;

static char sFrameBuffer[FRAME_BUFFER_HEIGHT][FRAME_BUFFER_WIDTH];

void kbcDrwaMojiRetu(int startPosX, int posY, const char* mojiretu)
{
	for (int i = 0; mojiretu[i] != '\0'; i++) {
		kbcDrawMoji(startPosX + i, posY, mojiretu[i]);
	}
}
bool kbcDrawMoji(int posX, int posY, char moji)
{
	//�t���[���o�b�t�@�̕��ƍ����𒴂��Ă��Ȃ����`�F�[�b�N�B
	if (posX < FRAME_BUFFER_WIDTH && posY < FRAME_BUFFER_HEIGHT) {
		sFrameBuffer[posY][posX] = moji;
		//�`����
		return true;
	}
	//�`���Ȃ������B
	return false;
}
void kbcBeginFrame()
{
	//�t�H���g�̃T�C�Y�̐ݒ�B
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = { sizeof info };
	info.dwFontSize.X = 32;
	info.dwFontSize.Y = 32;
	SetCurrentConsoleFontEx(hConsole, 0, &info);

	//�R���\�[���̏c�Ɖ��̍s����ݒ�B
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwSize = { 9999, 9999 };
	SetConsoleScreenBufferSize(
		hCons,			// HANDLE hConsoleOutput
		dwSize);        // COORD dwSiz

	//�R���\�[���̍�����ݒ�B
	SMALL_RECT consoleWindow = { 0, 0, 40, 20 };
	BOOL ret = SetConsoleWindowInfo(
		hCons, // HANDLE hConsoleOutput
		TRUE,           // BOOL bAbsolute
		&consoleWindow);// CONST SMALL_RECT *lpConsoleWindow

	//�t���[���o�b�t�@���N���A�B
	memset(sFrameBuffer, 0, sizeof(sFrameBuffer));
}
bool isPressA = false;
bool isTriggerA = false;

void kbcEndFrame()
{
	//�t���[���o�b�t�@�̓��e����ʂɕ\������B
	for (int i = 0; i < FRAME_BUFFER_HEIGHT; i++) {
		for (int j = 0; j < FRAME_BUFFER_WIDTH; j++) {
			std::cout << sFrameBuffer[i][j];
		}
		std::cout << "\n";
	}
	//A�L�[�������܂őҋ@done
	while (GetAsyncKeyState('A') == 0) {}


	//32�~���b����B
	Sleep(100);

	//�W���o�̓R���\�[���̃n���h�����擾�B
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = 0;
	pos.Y = 0;
	//�W���R���\�[���̃J�[�\����0�s�ځA0��ɖ߂��B
	SetConsoleCursorPosition(hCons, pos);

	CONSOLE_CURSOR_INFO cci;
	// CONSOLE_CURSOR_INFO�\���̂̌��݂̏�Ԃ��擾����
	GetConsoleCursorInfo(hCons, &cci);

	// �����o�ϐ��ł���bVisible���J�[�\���̕\���E��\���𐧌䂷��ϐ��Ȃ̂ŁA�����FALSE�ɂ��鎖�ŃJ�[�\�����\���ɂł���
	cci.bVisible = FALSE;

	// �ύX�����\���̏����R���\�[��Window�ɃZ�b�g����
	SetConsoleCursorInfo(hCons, &cci);
}