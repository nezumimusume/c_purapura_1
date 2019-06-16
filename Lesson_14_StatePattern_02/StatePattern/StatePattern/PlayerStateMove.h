#pragma once
#include "IPlayerState.h"

class PlayerStateMove : public IPlayerState
{
public:
	virtual void Enter();
	virtual void Leave();
	virtual void Update();
	//�W�����v�ł���H
	virtual bool IsPossibleJump()
	{
		//��ׂ�B
		return true;
	}
	//���G�H
	virtual bool IsInvincible()
	{
		//���G�ł͂Ȃ�
		return false;
	}
};
