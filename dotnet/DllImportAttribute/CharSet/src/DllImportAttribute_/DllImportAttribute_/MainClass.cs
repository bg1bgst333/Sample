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

        // ���b�Z�[�W�{�b�N�X�̕\��
        MessageBox((IntPtr)0, "����������", "DllImportAttribute_", 0);    // MessageBox��"����������"��\��.

    }

}