// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]) {	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// ���ʂ��i�[����hr.
	ITypeLib *pTypeLib = NULL;	// ITypeLib�|�C���^pTypeLib��NULL�ŏ�����.
	ITypeInfo *pTypeInfo = NULL;	// ITypeInfo�|�C���^pTypeInfo��NULL�ŏ�����.

	// COM�̏�����.
	CoInitialize(NULL);	// CoInitialize��COM��������.

	// ������1�Ԗڂ����󂯕t����.
	if (argc != 2) {	// ������2�ȊO.

		// �ُ�I��
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -1;	// -1��Ԃ��ďI��.

	}

	// �^�C�v���C�u�����̃��[�h.
	hr = LoadTypeLib(argv[1], &pTypeLib);	// LoadTypeLib�Ń^�C�v���C�u�����̃��[�h.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("LoadTypeLib NG!\n"));	// "LoadTypeLib NG!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -2;	// -2��Ԃ��ďI��.
	}

	// �擾����ITypeLib�C���^�[�t�F�[�X�|�C���^pTypeLib���o��.
	_tprintf(_T("pTypeLib = 0x%08x\n"), (unsigned long)pTypeLib);	// pTypeLib���o��.

	// �擪��ITypeInfo�|�C���^���擾.
	hr = pTypeLib->GetTypeInfo(0, &pTypeInfo);	// ITypeLib::GetTypeInfo��ITypeInfo�|�C���^���擾.
	if (FAILED(hr)) {	// ���s.
		_tprintf(_T("ITypeLib::GetTypeInfo NG!\n"));	// "ITypeLib::GetTypeInfo NG!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -3;	// -3��Ԃ��ďI��.
	}

	// �擾����ITypeInfo�C���^�[�t�F�[�X�|�C���^pTypeInfo���o��.
	_tprintf(_T("pTypeInfo = 0x%08x\n"), (unsigned long)pTypeInfo);	// pTypeInfo���o��.

	// pTypeInfo�̉��.
	pTypeInfo->Release();	// ITypeInfo::Release�ŉ��.

	// pTypeLib�̉��.
	if (pTypeLib != NULL) {
		pTypeLib->Release();
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}