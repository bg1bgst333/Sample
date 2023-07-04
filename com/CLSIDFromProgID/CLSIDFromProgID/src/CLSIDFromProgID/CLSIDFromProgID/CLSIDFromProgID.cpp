// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]) {	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// CLSIDFromProgID�̌��ʂ��i�[����hr.
	CLSID clsid;	// CLSID���i�[����clsid.
	WCHAR *lpwszCLSID;	// CLSID��������w��WCHAR�|�C���^lpwszCLSID.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// Word��ProgID����CLSID���擾.
	hr = CLSIDFromProgID(_T("Word.Application"), &clsid);	// CLSIDFromProgID��"Word.Application"��clsid���擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("CLSIDFromProgID NG!\n"));	// "CLSIDFromProgID NG!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -1;	// -1��Ԃ��ďI��.
	}

	// clsid�𕶎���ɕϊ���, �o��.
	StringFromCLSID(clsid, &lpwszCLSID);	// clsid��lpwszCLSID�ɕϊ�.
	wprintf(L"lpwszCLSID = %s\n", lpwszCLSID);	// lpwszCLSID���o��.

	// lpwszCLSID�̉��.
	CoTaskMemFree(lpwszCLSID);	// CoTaskMemFree��lpwszCLSID�����.

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}