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
        DateTime after5Minutes = dateTime.AddMinutes(5);    // dateTime.AddMinutes��5������.
        Console.WriteLine("after5Minutes.ToString() = " + after5Minutes.ToString());  // after5Minutes.ToString()���o��.

    }

}