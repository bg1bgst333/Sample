// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]) {	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// ���ʂ��i�[����hr.
	ITypeLib *pTypeLib = NULL;	// ITypeLib�|�C���^pTypeLib��NULL�ŏ�����.
	ITypeInfo *pTypeInfo = NULL;	// ITypeInfo�|�C���^pTypeInfo��NULL�ŏ�����.
	TYPEATTR *pTypeAttr;	// TYPEATTR�\���̃|�C���^pTypeAttr.
	BSTR strDocString;	// BSTR������strDocString.

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

	// ITypeInfo�|�C���^�̐����擾.
	int nCount = pTypeLib->GetTypeInfoCount();	// ITypeLib::GetTypeInfoCount��ITypeInfo�|�C���^�̐����擾.
	_tprintf(_T("nCount = %d\n"), nCount);	// nCount���o��.

	// ���ꂼ���ITypeInfo�|�C���^���擾.
	for (int i = 0; i < nCount; i++) {
		pTypeLib->GetTypeInfo(i, &pTypeInfo);	// ITypeLib::GetTypeInfo��ITypeInfo�|�C���^���擾.
		pTypeInfo->GetTypeAttr(&pTypeAttr);	// ITypeInfo::GetTypeAttr�Ō^�̑������擾.
		if (pTypeAttr->typekind == TKIND_DISPATCH) {
			pTypeLib->GetDocumentation(i, &strDocString, NULL, NULL, NULL);	// ITypeLib::GetDocumentation��strDocString�擾.
			_tprintf(_T("strDocString = %s\n"), strDocString);	// strDocString���o��.
			SysFreeString(strDocString);	// SysFreeString��strDocString�����.
		}
		pTypeInfo->ReleaseTypeAttr(pTypeAttr);	// ITypeInfo::ReleaseTypeAttr��pTypeAttr�����.
		pTypeInfo->Release();
	}

	// pTypeLib�̉��.
	if (pTypeLib != NULL) {
		pTypeLib->Release();
	}

	// COM�̏I������.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}