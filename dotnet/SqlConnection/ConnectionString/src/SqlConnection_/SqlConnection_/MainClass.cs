// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Data.SqlClient;    // SQL�N���C�A���g(System.Data.SqlClient���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // SqlConnection�I�u�W�F�N�g�̍쐬.
        SqlConnection sqlConn = new SqlConnection();    // SqlConnection�I�u�W�F�N�gsqlConn���쐬.

        // �ڑ�������̃Z�b�g.
        sqlConn.ConnectionString = @"Data Source=XXX;Initial Catalog=xxx;Integrated Security=True;";

        // sqlConn���o��.
        Console.WriteLine("sqlConn = " + sqlConn);  // Console.WriteLine��sqlConn���o��.

    }

}