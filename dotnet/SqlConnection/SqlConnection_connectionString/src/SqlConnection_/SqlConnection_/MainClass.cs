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
        string connStr = @"Data Source=XXX;Initial Catalog=xxx;Integrated Security=True;";
        SqlConnection sqlConn = new SqlConnection(connStr);    // �R���X�g���N�^��connStr��n����, SqlConnection�I�u�W�F�N�gsqlConn���쐬.

        // sqlConn���o��.
        Console.WriteLine("sqlConn = " + sqlConn);  // Console.WriteLine��sqlConn���o��.

    }

}