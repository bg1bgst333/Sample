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
            // Debug.WriteLine()�ł��܂��܂ȏo��.
            Debug.WriteLine(false); // Debug.WriteLine��false���f�o�b�O�o�͂����s.
            Debug.WriteLine('A');   // Debug.WriteLine��'A'���f�o�b�O�o�͂����s.
            Debug.WriteLine(10);    // Debug.WriteLine��10���f�o�b�O�o�͂����s.
            Debug.WriteLine(1.23f); // Debug.WriteLine��1.23f���f�o�b�O�o�͂����s.
            Debug.WriteLine("ABC"); // Debug.WriteLine��"ABC"���f�o�b�O�o�͂����s.
            Debug.WriteLine(null);  // Debug.WriteLine��null���w�肷���, ���s�̂ݍs��.
            Debug.WriteLine("XYZ"); // Debug.WriteLine��"XYZ"���f�o�b�O�o�͂����s.
        }
    }
}