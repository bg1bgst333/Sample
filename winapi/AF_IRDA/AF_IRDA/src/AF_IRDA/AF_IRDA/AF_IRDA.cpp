// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI
#include <af_irda.h>	// IrDA

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾.
	WSADATA wsaData;	// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;	// WSAStartup�̌��ʂ��i�[����iRet.
	int soc;	// �\�P�b�gsoc.

	// WinSock�̏�����.
	iRet = WSAStartup(MAKEWORD(2,2), &wsaData);	// WSAStartup��WinSock�̏�����.
	if (iRet == 0){	// 0�Ȃ琬��.

		// ���ʐ����̏o��.
		_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"���o��.

		// �ԊO���\�P�b�g�̍쐬.
		soc = socket(AF_IRDA, SOCK_STREAM, 0);	// socket��AF_IRDA��soc���쐬.
		if (soc != INVALID_SOCKET){	// INVALID_SOCKET�łȂ���.

			// �\�P�b�g�f�B�X�N���v�^���o��.
			_tprintf(_T("soc = %d\n"), soc);	// soc���o��.

			// soc�����.
			closesocket(soc);	// closesocket��soc�����.

		}

		// �I������.
		WSACleanup();	// WSACleanup�ŏI������.

	}

	// �v���O�����̏I��.
	return 0;

}