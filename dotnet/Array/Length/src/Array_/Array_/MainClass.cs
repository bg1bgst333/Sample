// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �z����R���N�V�����������q�ŏ�����.
        int[] array = new int[] { 1, 2, 3, 4, 5 };  // array��{1, 2, 3, 4, 5}�ŏ�����.

        // �z��̊e�v�f���o��.
        for (int i = 0; i < array.Length; i++) // array.Length�̑O�܂ŌJ��Ԃ�.
        {

            // i�Ԗڂ��o��
            System.Console.WriteLine("array[" + i + "] = " + array[i]); // System.Console.WriteLine��array[i]�̒l���o��.

        }

    }

}