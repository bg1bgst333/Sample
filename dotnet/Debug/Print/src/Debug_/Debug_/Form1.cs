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
            // Debug.Print()�ŏ������w�肵�ďo��.
            Debug.Print("{0}, {1:D}, {2:N}, {3:X}", "ABC", 123, 0.25, 10);  // Debug.Print��"ABC, 123, 0.25, A"�Ńf�o�b�O�o��.
        }
    }
}