using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;   // �V�X�e���v���Z�X��C�x���g���O�Ƃ̑Θb���邽�߂̃N���X.(System.Diagnostics���O���)

namespace Debug_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            // �ϐ��̏�����
            bool b = true;      // b��true�ɏ�����.
            char c = 'X';       // c��'X'�ɏ�����.
            int i = 100;        // i��100�ɏ�����.
            float f = 0.25f;    // f��0.25�ɏ�����.
            string s = "XYZ";   // s��"XYZ"�ɏ�����.

            // Debug.Write�͉��s������.
            Debug.Write(b);     // Debug.Write��b���o��.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(c);     // Debug.Write��c���o��.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(i);     // Debug.Write��i���o��.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(f);     // Debug.Write��f���o��.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(s);     // Debug.Write��s���o��.
            Debug.Write('\n');  // Debug.Write�ŉ��s.

            // Write�̈����͊�{object�^�������e�����l�ł�������.
            Debug.Write(false); // �^�U�l���e����false.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write('A');   // �������e����'A'.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(10);    // �������e����10.
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write(1.23f); // ���������_�����e����1.23f
            Debug.Write('\n');  // Debug.Write�ŉ��s.
            Debug.Write("ABC"); // �����񃊃e����"ABC"
            Debug.Write('\n');  // Debug.Write�ŉ��s.
        }
    }
}