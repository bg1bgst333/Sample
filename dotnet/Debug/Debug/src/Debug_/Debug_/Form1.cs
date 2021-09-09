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
            // Debug.Write, Debug.WriteLine, Debug.Print�ɂ��f�o�b�O�o��.
            Debug.Write("Debug\n");    // Debug.Write��"Debug"���o��.(���s�������K�v)
            Debug.WriteLine("Debug");  // Debug.WriteLine��"Debug"���o��.(���s�������s�v)
            Debug.Print("{0}, {1}, {2}", "Debug(1)", "Debug(2)", "Debug(3)");    // �����w��q��3�̕����񃊃e�������o��.(Debug.WriteLine�ł͂Ȃ�Debug.Print)
            Debug.Print("{0:D}, {1:N}, {2:X}", 123, 0.25, 10);    // �����w��q��10�i����, ����, 16�i�������o��.(Debug.WriteLine�ł͂Ȃ�Debug.Print)
        }
    }
}