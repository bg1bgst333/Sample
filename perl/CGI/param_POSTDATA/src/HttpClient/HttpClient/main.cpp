// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <stdlib.h>		// �W�����C�u����
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI

// _tmain�֐��̒�`
int _tmain() {	// main�֐���tchar��.

	// �ϐ��̐錾�E������
	WSADATA wsaData;					// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;							// �������̌���iRet.
	char hostname[256] = "localhost";	// �z�X�g��hostname��"localhost"�ŏ�����.
	int port = 80;						// �|�[�g�ԍ�port��80�ŏ�����.
	struct hostent* host;				// �z�X�g�����i�[����hostent�\���̂ւ̃|�C���^host.
	SOCKET soc;							// SOCKET�^�̃\�P�b�g�t�@�C���f�B�X�N���v�^soc.
	u_short ns_port;					// �|�[�g�ԍ��̃l�b�g���[�N�o�C�g�I�\�_�l.
	struct sockaddr_in saiTargetAddr;	// �ڑ���T�[�o�̂̏��saiTargetAddr.
	char request_str[1024];				// ���N�G�X�g������request_str.(����1024)
	HANDLE hFile;						// HANDLE�^�t�@�C���n���h��hFile
	DWORD dwSize;						// DWORD�^�t�@�C���T�C�YdwSize
	BYTE* pbtBuf = NULL;				// BYTE�^�|�C���^pbtBuf��NULL�ŏ�����.
	DWORD dwReadBytes;					// DWORD�^�ǂݍ��񂾃o�C�g��dwReadBytes.
	char content_len_str[256];			// Content-Length�s�̕�����content_len_str
	char response_buf[4096];			// ���X�|���X�o�b�t�@response_buf.(����4096)

	// WinSock�̏�����
	iRet = WSAStartup(MAKEWORD(2, 2), &wsaData);	// WSAStartup��WinSock�̏�����.
	if (iRet) {	// 0�łȂ��ꍇ.

		// �G���[����.
		_tprintf(_T("Error!(iRet = %d.)\n"), iRet);	// �߂�l���o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// �������������b�Z�[�W.
	_tprintf(_T("WSAStartup success!\n"));	// "WSAStartup success!"�Əo��.

	// �z�X�g���̎擾.
	host = gethostbyname(hostname);	// gethostbyname�Ŏw�肵���z�X�g���̃z�X�g�����擾.
	if (host == NULL) {	// host��NULL�Ȃ�.

		// �G���[
		_tprintf(_T("gethostbyname Error!\n"));	// �G���[���b�Z�[�W�o��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �z�X�g�����瓱���o���ꂽIP�A�h���X���.
	_tprintf(_T("host->h_addr_list[0][0] = %02x, host->h_addr_list[0][1] = %02x, host->h_addr_list[0][3] = %02x, host->h_addr_list[0][3] = %02x\n"), host->h_addr_list[0][0], host->h_addr_list[0][1], host->h_addr_list[0][2], host->h_addr_list[0][3]);	// host->h_addr_list�̒��g���o��.

	// �\�P�b�g�̍쐬
	soc = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, 0);	// WSASocket�Ń\�P�b�g�쐬.
	if (soc == INVALID_SOCKET) {	// soc��INVALID_SOCKET( == -1)�Ȃ�.

		// �G���[����
		_tprintf(_T("WSASocket Error!\n"));	// "WSASocket Error!"�Əo��.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// soc�̒l���o��.
	_tprintf(_T("soc = %lu\n"), soc);	// soc�̒l���o��.

	// �|�[�g�ԍ��̕ϊ�.
	WSAHtons(soc, port, &ns_port);	// WSAHtons�Ń|�[�g�ԍ����l�b�g���[�N�o�C�g�I�\�_�ɕϊ�.

	// �|�[�g�ԍ��̏o��.
	_tprintf(_T("port = %04x, ns_port = %04x\n"), port, ns_port);	// �|�[�g�ԍ��ƃl�b�g���[�N�o�C�g�I�\�_�ȃ|�[�g�ԍ����o��.

	// �ڑ���T�[�o���saiTargetAddr�̐ݒ�.
	saiTargetAddr.sin_family = AF_INET;														// IPv4�t�@�~���[AF_INET
	saiTargetAddr.sin_port = ns_port;														// �|�[�g�ԍ���ns_port.
	saiTargetAddr.sin_addr.S_un.S_addr = *(u_long*)host->h_addr_list[0];					// host��IP�A�h���X�����Z�b�g.(u_long�Ƃ���.)

	// �ڑ�
	if (WSAConnect(soc, (struct sockaddr*)&saiTargetAddr, sizeof(saiTargetAddr), NULL, NULL, NULL, NULL) == SOCKET_ERROR) {	// WSAConnect�Őڑ���, SOCKET_ERROR�Ȃ�G���[.

		// �G���[����
		_tprintf(_T("WSAConnect Error!\n"));	// "WSAConnect Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ��Ĉُ�I��.

	}

	// ����������"WSAConnect success."
	_tprintf(_T("WSAConnect success.\n"));	// _tprintf��"WSAConnect success."�Əo��.

	// �t�@�C�����J��
	hFile = CreateFile(_T("image1.bmp"), GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);	// CreateFile��"image1.bmp"���J����, �擾�����n���h����hFile�Ɋi�[.
	if (hFile == INVALID_HANDLE_VALUE) {	// hFile��INVALID_HANDLE_VALUE�Ȃ�.

		// �G���[����
		_tprintf(_T("CreateFile Error!\n"));	// _tprintf��"CreateFile Error!"�Əo��.
		closesocket(soc);	// closesocket��soc�����.
		WSACleanup();	// WSACleanup�ŏI������.
		return -1;	// -1��Ԃ�.

	}

	// �t�@�C���T�C�Y�̎擾.
	dwSize = GetFileSize(hFile, NULL);	// GetFileSize��"test.txt"�̃t�@�C���T�C�Y���擾����.

	// �������̊m��.
	pbtBuf = (BYTE*)malloc(sizeof(BYTE) * (dwSize + 1));	// malloc��(dwSize + 1)���m��.

	// �t�@�C���̓ǂݍ���.
	ReadFile(hFile, pbtBuf, dwSize, &dwReadBytes, NULL);	// hFile��ǂݍ���, pbtBuf
	pbtBuf[dwReadBytes] = 0;

	// ���N�G�X�g������̃N���A.
	memset(request_str, 0, sizeof(char) * 1024);	// memset��request_str��0�Ŗ��߂�.

	// ���N�G�X�g������̃Z�b�g.
	sprintf(request_str, "POST %s HTTP/1.0\r\n", "/cgi-bin/CGI.cgi");	// sprintf��POST���N�G�X�g���Z�b�g.
	sprintf(content_len_str, "Content-Length: %d\r\n", dwSize);	// Content-Length�̍s��g�ݗ���.
	strcat(request_str, content_len_str);	// content_len_str��A��.
	strcat(request_str, "Content-Type: image/bmp\r\n");	// Content-Type�̍s��A��.
	strcat(request_str, "\r\n");	// 1�s�󂯂�.

	// ���M
	send(soc, request_str, strlen(request_str), 0);	// send��request_str�𑗐M.

	// �t�@�C���o�C�i���̑��M.
	send(soc, (char*)pbtBuf, dwSize, 0);	// send��pbtBuf�𑗐M.

	// ���X�|���X������̃N���A.
	memset(response_buf, 0, sizeof(char) * 4096);	// memset��response_buf��0�Ŗ��߂�.

	// ��M
	recv(soc, response_buf, sizeof(char) * 4096, 0);	// ��M�������b�Z�[�W��response_buf�Ɋi�[.

	// ���.
	free(pbtBuf);	// pbtBuf�����.

	// ���X�|���X��������o��.
	printf("%s\n", response_buf);	// response_buf���o��.

	// �t�@�C�������.
	CloseHandle(hFile);

	// �\�P�b�g�����.
	closesocket(soc);	// closesocket��soc�����.

	// WinSock�̏I������.
	WSACleanup();	// WSACleanup�ŏI������.

	// �v���O�����̏I��.
	return 0;

}