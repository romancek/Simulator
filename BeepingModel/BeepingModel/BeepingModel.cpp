// BeepingModel.cpp : ���C�� �v���W�F�N�g �t�@�C���ł��B

#include "stdafx.h"

using namespace BeepingModel;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// �R���g���[�����쐬�����O�ɁAWindows XP �r�W���A�����ʂ�L���ɂ��܂�
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	int NODE_SIZE = 5;
	float PEN_WIDTH = 0.1f;
	// ���C�� �E�B���h�E���쐬���āA���s���܂�
	Application::Run(gcnew Form1());
	return 0;
}
