// ���O��Ԃ̓o�^
using System;   // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)

// MainClass�̒�`
class MainClass
{

    // Main���\�b�h�̒�`
    static void Main()
    {

        // ���ݓ����̏o��.
        DateTime dateTime = DateTime.Now;   // DateTime.Now�Ō��ݓ������擾��, dateTime�Ɋi�[.
        Console.WriteLine("dateTime.ToString() = " + dateTime.ToString());  // dateTime.ToString()���o��.
        DateTime after50Years = dateTime.AddYears(50);  // dateTime.AddYears��50�N����.
        Console.WriteLine("after50Years.ToString() = " + after50Years.ToString());  // after50Years.ToString()���o��.

    }

}