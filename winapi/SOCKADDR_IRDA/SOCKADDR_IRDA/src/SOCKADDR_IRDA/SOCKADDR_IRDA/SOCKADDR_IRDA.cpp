// �w�b�_�t�@�C���̃C���N���[�h
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <string.h>		// �����񏈗�
#include <winsock2.h>	// Windows�\�P�b�g
#include <windows.h>	// �W��WindowsAPI
#include <af_irda.h>	// IrDA

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	WSADATA wsaData;	// WinSock�̏������ɕK�v��WSADATA�\���̕ϐ�wsaData.
	int iRet;			// WSAStartup�̌��ʂ��i�[����iRet.
	int soc;			// �\�P�b�gsoc.
	int iBind;			// �o�C���h����iBind.
	int iListen;		// ���b�X������iListen.
	SOCKADDR_IRDA soc_addr = {AF_IRDA, 0, 0, 0, 0, "OBEX"};	// soc_addr�����̂悤�ɏ�����.
	int acc;			// �\�P�b�gacc.
	SOCKADDR_IRDA acc_addr;	// ����̃A�h���X���acc_addr.
	int acc_addr_len = sizeof(SOCKADDR_IRDA);	// ����̃A�h���X���̒���acc_addr_len��SOCKADDR_IRDA�̃T�C�Y�ŏ�����.
	TCHAR tszServerName[256] = {0};	// �T�[�o�[��tszServerName��{0}�ŏ�����.
	int iServerNameLen = 0;	// �T�[�o�[��iServerNameLen��0�ŏ�����.
	BYTE btBytes[4096] = {0};	// BYTE�z��btBytes(�T�C�Y4096)��{0}�ŏ�����.
	int iRecvLen = 0;	// ��M�����f�[�^�̒���iRecvLen��0�ŏ�����.
	int i = 0;	// ���[�v�p�ϐ�i��0�ŏ�����.
	BYTE btResponseBytes[4096] = {0};	// ���X�|���XBYTE�z��btResponseBytes(�T�C�Y4096)��{0}�ŏ�����.
	WORD wPacketSize = 0;	// �p�P�b�g�T�C�YwPacketSize��0�ŏ�����.
	TCHAR tszName[256] = {0};	// tszName��{0}�ŏ�����.
	WORD wNameSize = 0;	// Name�̃T�C�YwNameSize��0�ŏ�����.
	char szName[256] = {0};	// char�^�z��szName(����256)��{0}�ŏ�����.

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

			// �o�C���h
			iBind = bind(soc, (const struct sockaddr *)&soc_addr, sizeof(SOCKADDR_IRDA));	// bind��soc��soc_addr���o�C���h.
			if (iBind != SOCKET_ERROR){	// SOCKET_ERROR�łȂ����.

				// ���ʐ����̏o��.
				_tprintf(_T("bind success!\n"));	// "bind success!"�Əo��.

				// ���b�X��
				iListen = listen(soc, 1);	// listen��1�҂��󂯂�.
				if (iListen != SOCKET_ERROR){	// SOCKET_ERROR�łȂ����.

					// ���ʐ����̏o��.
					_tprintf(_T("listen success!\n"));	// "listen success!"�Əo��.

					// �A�N�Z�v�g
					acc = accept(soc, (struct sockaddr *)&acc_addr, &acc_addr_len);	// accept�ő҂��󂯂�, �A�N�Z�v�g�\�P�b�g��acc�Ɋi�[.
					if (soc != INVALID_SOCKET){	// INVALID_SOCKET�łȂ���.

						// �A�N�Z�v�g�\�P�b�g�f�B�X�N���v�^��A�h���X�����o��.
						_tprintf(_T("acc = %d\n"), acc);	// acc���o��.
						_tprintf(_T("acc_addr.irdaAddressFamily = %hu\n"), acc_addr.irdaAddressFamily);	// acc_addr.irdaAddressFamily���o��.
						_tprintf(_T("acc_addr.irdaDeviceID = %02X %02X %02X %02X\n"), acc_addr.irdaDeviceID[3], acc_addr.irdaDeviceID[2], acc_addr.irdaDeviceID[1], acc_addr.irdaDeviceID[0]);	// acc_addr.irdaDeviceID���o��.
						iServerNameLen = MultiByteToWideChar(CP_ACP, 0, acc_addr.irdaServiceName, -1, NULL, 0);	// MultiByteToWideChar�Œ������擾.
						MultiByteToWideChar(CP_ACP, 0, acc_addr.irdaServiceName, -1, tszServerName, iServerNameLen);	// MultiByteToWideChar�ŕϊ�.
						_tprintf(_T("acc_addr.irdaServiceName = %s\n"), tszServerName);	// tszServerName���o��.

						// �f�[�^�̎�M
						while (TRUE){
							ZeroMemory(btBytes,  sizeof(btBytes));	// �������N���A.
							iRecvLen = recv(acc, (char *)btBytes, sizeof(btBytes), 0);	// recv�Ńf�[�^����M��, btBytes�Ɋi�[.
							_tprintf(_T("btBytes = "));	// "btBytes = "�Əo��.
							if (iRecvLen == 0){	// ��M�o���Ȃ�����.
								// �I������.
								break;	// ������.
							}
							else{	// ��M�o����.
								for (i = 0; i < iRecvLen; i++){	// iRecvLen���J��Ԃ�.
									_tprintf(_T("%02X "), btBytes[i]);	// btBytes��i�Ԗڂ��o��.
								}
								_tprintf(_T("\n"));	// ���s���o��.
								ZeroMemory(btResponseBytes,  sizeof(btResponseBytes));	// �������N���A.
								if (btBytes[0] == 0x80){	// �ŏ��̐ڑ����N�G�X�g�������Ƃ�.
									btResponseBytes[0] = 0xA0;	// ����.
									btResponseBytes[1] = 0x00;
									btResponseBytes[2] = 0x07;	// �T�C�Y��7�o�C�g.
									btResponseBytes[3] = 0x10;	// OBEX�o�[�W����1.0.
									btResponseBytes[4] = 0x00;	// �ڑ��t���O�Ȃ�.
									btResponseBytes[5] = 0x10;
									btResponseBytes[6] = 0x00;	// �ő�p�P�b�g�T�C�Y4K
									send(acc, (const char *)btResponseBytes, btResponseBytes[2], 0);	// send��btResponseBytes�𑗂�.
								}
								else if (btBytes[0] == 0x82){	// �Ōォ�f�[�^�������݂���Ă���.
									wPacketSize = MAKEWORD(btBytes[2], btBytes[1]);	// wPacketSize�̎擾.
									_tprintf(_T("wPacketSize = %hu\n"), wPacketSize);	// wPacketSize�̏o��.
									int iIndex = 3;
									// HI�̎��o�����[�v.
									while (TRUE){
										// HI���Ƃɕ�����.
										if (btBytes[iIndex] == 0x01){	// Name
											int iTemp = iIndex;
											wNameSize = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);	// wNameSize�̎擾.
											int iTemp2 = wNameSize;
											wNameSize = wNameSize - 3;	// HI for Name��Name Length��3�o�C�g�������Ȃ��Ƃ����Ȃ�.
											_tprintf(_T("wNameSize = %hu\n"), wNameSize);	// wNameSize�̏o��.
											memcpy(szName, (const char *)&btBytes[iIndex + 3], wNameSize);	// szName��Name���R�s�[.
											for (i = 0; i < (wNameSize - 1) / 2; i++){	// (wNameSize - 1) / 2�̕��J��Ԃ�.
												TCHAR t[2] = {0};	// t��{0}�ŏ�����.
												t[0] = MAKEWORD(szName[2 * i + 1], szName[2 * i]);	// ���C�h����t�𐶐�.
												t[1] = 0;	// t[1]��0.
												_tcscat(tszName, t);	// tszName��t��A��.
											}
											tszName[(wNameSize - 1) / 2] = 0;	// �Ō��0���Z�b�g.
											_tprintf(_T("tszName = %s\n"), tszName);
											iTemp = iTemp + iTemp2;
											iIndex = iTemp;
										}
										else if (btBytes[iIndex] == 0xC3){	// Length
											int iTemp = iIndex;
											WORD w1 = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);
											WORD w2 = MAKEWORD(btBytes[iIndex + 4], btBytes[iIndex + 3]);
											DWORD dwLength = MAKELONG(w2, w1);
											_tprintf(_T("dwLength = %08x\n"), dwLength);
											iIndex = iTemp + 5;
										}
										else if (btBytes[iIndex] == 0x49){	// End-of-Body
											WORD wSize = MAKEWORD(btBytes[iIndex + 2], btBytes[iIndex + 1]);
											WORD wBodySize = wSize - 3;
											_tprintf(_T("wBodySize = %08x\n"), wBodySize);
											btResponseBytes[0] = 0xA0;	// ����.
											btResponseBytes[1] = 0x00;
											btResponseBytes[2] = 0x03;	// �T�C�Y��3�o�C�g.
											send(acc, (const char *)btResponseBytes, 3, 0);	// ���������𑗐M.
											FILE *fp = _tfopen(tszName, _T("wb"));	// tszName�ŊJ��.
											if (fp != NULL){	// fp��NULL�łȂ�.
												int len = fwrite(&btBytes[iIndex + 3], sizeof(BYTE), wBodySize, fp);	// ��������.
												fclose(fp);	// ����.
											}
											break;
										}
									}
								}
								else{
									break;
								}
							}
						}

						// ���s.
						_tprintf(_T("\n"));	// ���s���o��.

						// acc�����.
						closesocket(acc);	// closesocket��acc�����.

					}
					
				}
				else{	// SOCKET_ERROR.

					// ���ʎ��s�̏o��.
					_tprintf(_T("listen failed!\n"));	// "listen failed!"�Əo��.

				}

			}
			else{	// SOCKET_ERROR.

				// ���ʎ��s�̏o��.
				_tprintf(_T("bind failed!\n"));	// "bind failed!"�Əo��.

			}

			// soc�����.
			closesocket(soc);	// closesocket��soc�����.

		}

		// �I������.
		WSACleanup();	// WSACleanup�ŏI������.

	}

	// �v���O�����̏I��.
	return 0;

}