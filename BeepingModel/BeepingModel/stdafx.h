// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B
#pragma once
#include "Controller.h"
#include "Node.h"
#include "Channel.h"

#define N_SIZE 1000
#define M_SIZE 1000
//action state
#define beeping 0
#define listen 1
//node state
#define inactive 2
#define competing 3
#define MIS 4
//hearing state
#define beep 5
#define silent 6
// TODO: �v���O�����ɕK�v�Ȓǉ��w�b�_�[�������ŎQ�Ƃ��Ă��������B
