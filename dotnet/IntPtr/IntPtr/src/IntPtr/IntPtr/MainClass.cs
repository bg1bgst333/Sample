// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Runtime.InteropServices;   // COM���݉^�p�ƃv���b�g�t�H�[���Ăяo��(System.Runtime.InteropServices���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // DLL�̃C���|�[�g
    [DllImport("user32.dll", CharSet = CharSet.Auto)] // DllImport��"user32.dll"�̃C���|�[�g.(CharSet.Auto�ɂ���.)
    public static extern int MessageBox(IntPtr hWnd, string lpText, string lpCaption, uint Type);   // WindowsAPI��MessageBox�̐錾.

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // ���b�Z�[�W�{�b�N�X�̕\��.
        IntPtr handle = new IntPtr(0);  // IntPtr�^handle�𐶐���, �R���X�g���N�^��0���Z�b�g.(0�Ȃ̂�null�̃E�B���h�E�n���h����\��.)
        MessageBox(handle, "����������", "DllImportAttribute_", 0);    // MessageBox��"����������"��\��.

    }

}