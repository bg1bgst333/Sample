// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�^
#include <stdio.h>		// �W�����o��
#include <shlwapi.h>	// �V�F��API

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	TCHAR tszFilePath[] = _T("C:\\Users\\B.G\\Documents\\test\\test.txt");	// tszFilePath��"test.txt"�̃p�X�ŏ�����.
	TCHAR tszFolderPath[] = _T("C:\\Users\\B.G\\Documents\\test\\folder");	// tszFolderPath��"folder"�̃p�X�ŏ�����.
	TCHAR tszDrivePath[] = _T("C:");	// tszDrivePath��"C:"�̃p�X�ŏ�����.
	TCHAR tszDeviceName[] = _T("\\Device\\HarddiskVolume2\\Windows\\explorer.exe");	// tszDeviceName��"explorer.exe"�̃f�o�C�X���ŏ�����.

	// �t�@�C�����̂ݎ擾.
	PathStripPath(tszFilePath);	// PathStripPath�Ńt�@�C���������c��.

	// �ŉ��w�̃t�H���_���̂ݎ擾.
	PathStripPath(tszFolderPath);	// PathStripPath�ōŉ��w�̃t�H���_�������c��.

	// �h���C�u�̃��[�g�t�H���_�̏ꍇ.
	PathStripPath(tszDrivePath);	// PathStripPath�Ńh���C�u���Ȃǂ͂��̂܂�.

	// �f�o�C�X���̏ꍇ.
	PathStripPath(tszDeviceName);	// tszDeviceName�Ńt�@�C���������c��.

	// ���ʂ̏o��.
	_tprintf(_T("tszFilePath = %s\n"), tszFilePath);	// tszFilePath�̏o��.
	_tprintf(_T("tszFolderPath = %s\n"), tszFolderPath);	// tszFolderPath�̏o��.
	_tprintf(_T("tszDrivePath = %s\n"), tszDrivePath);	// tszDrivePath�̏o��.
	_tprintf(_T("tszDeviceName = %s\n"), tszDeviceName);	// tszDeviceName�̏o��.

	// �v���O�����̏I��.
	return 0;

}