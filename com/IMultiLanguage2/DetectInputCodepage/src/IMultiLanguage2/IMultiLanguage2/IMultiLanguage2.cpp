// �w�b�_�t�@�C���̃C���N���[�h
#include <windows.h>	// �W��WindowsAPI
#include <tchar.h>		// TCHAR�Ή�
#include <stdio.h>		// C�W�����o��
#include <mlang.h>		// ������

// _tmain�֐��̒�`
int _tmain(int argc, TCHAR *argv[]){	// main�֐���TCHAR��.

	// �ϐ��̐錾�Ə�����.
	HRESULT hr;		// COM�̏������̌��ʂ��i�[����hr.
	HRESULT hr2;	// IMultiLanguage2�̐������ʂ��i�[����hr2.
	HRESULT hr3;	// IMultiLanguage2::DetectInputCodepage�̌��ʂ��i�[����hr3.
	IMultiLanguage2 *pMultiLang = NULL;	// IMultiLanguage2�C���^�[�t�F�[�X�|�C���^pMultiLang��NULL�ŏ�����.
	DetectEncodingInfo dei[10];	// ���o�G���R�[�h���̔z��dei.
	char input[] = "�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B�����̓V�C�͐���ōō��C����5���ł��B";	// ���͕�����input.
	int len;	// input�̒���len.
	int num = 10;	// �z��dei�̗v�f��num��10�ŏ�����.

	// COM�̏�����.
	hr = CoInitialize(NULL);	// CoInitialize��COM����������, �߂�l��hr�Ɋi�[.
	if (FAILED(hr)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		return -1;	// -1��Ԃ��Ĉُ�I��.
	}

	// IMultiLanguage2�C���^�[�t�F�[�X�̐���.
	hr2 = CoCreateInstance(CLSID_CMultiLanguage, 0, CLSCTX_INPROC_SERVER, IID_IMultiLanguage2, (LPVOID *)&pMultiLang);	// CoCreateInstance��, IMultiLanguage2�C���^�[�t�F�[�X�𐶐�.
	if (FAILED(hr2)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -2;	// -2��Ԃ��Ĉُ�I��.
	}

	// CoCreateInstance�͐���.
	_tprintf(_T("CoCreateInstance OK!\n"));	// "CoCreateInstance OK!"�Əo��.

	// �擾����IMultiLanguage2�C���^�[�t�F�[�X�|�C���^pMultiLang���o��.
	_tprintf(_T("pMultiLang = 0x%08x\n"), (unsigned long)pMultiLang);	// pMultiLang���o��.

	// ���͕����R�[�h�̌��o.
	len = strlen(input);	// strlen��input�̒������擾��, len�Ɋi�[.
	hr3 = pMultiLang->DetectInputCodepage(MLDETECTCP_NONE, 0, input, &len, dei, &num);	// IMultiLanguage2::DetectInputCodepage�Ō��o.
	if (FAILED(hr2)){	// FAILED�}�N���Ŕ���.
		_tprintf(_T("FAILED!\n"));	// "FAILED!"�Əo��.
		pMultiLang->Release();	// IMultiLanguage2::Release�ŉ��.
		CoUninitialize();	// CoUninitialize�ŏI������.
		return -3;	// -3��Ԃ��Ĉُ�I��.
	}

	// num�̕��J��Ԃ�.
	for (int i = 0; i < num; i++){
		_tprintf(_T("dei[%d].nCodePage = %lu, dei[%d].nDocPercent = %lu\n"), i, dei[i].nCodePage, i, dei[i].nDocPercent);	// dei�̒��g���o��.
	}

	// COM�̏I������.
	pMultiLang->Release();	// IMultiLanguage2::Release�ŉ��.
	CoUninitialize();	// CoUninitialize�ŏI������.

	// �v���O�����̏I��.
	return 0;	// 0��Ԃ��ďI��.

}