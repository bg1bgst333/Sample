// ���O��Ԃ̓o�^
using System;       // ���ʃf�[�^�^�Ɗ�{�N���X(System���O���)
using System.Xml.Serialization; // XML�V���A���C�U(System.Xml.Serialization���O���)
using System.IO;    // �t�@�C�����o�͂ƃf�[�^�X�g���[��(System.IO���O���)

// ���C���N���X
class MainClass // MainClass�N���X�̒�`
{

    // ���C�����\�b�h
    static void Main()  // Main���\�b�h�̒�`
    {

        // �V���A���C�U�̐���.
        XmlSerializer serializer = new XmlSerializer(typeof(UserInfo)); // UserInfo��XmlSerializer�I�u�W�F�N�gserializer�𐶐�.
        
        // �I�u�W�F�N�g�̐���.
        UserInfo userInfo = new UserInfo(); // UserInfo�I�u�W�F�N�g�𐶐�.

        // test.xml���f�V���A���C�Y.
        using (FileStream fs = new FileStream("test.xml", FileMode.Open)) // FileStream��test.xml���J��.
        {
            userInfo = (UserInfo)serializer.Deserialize(fs);  // serializer.Deserialize��fs��userInfo�Ƀf�V���A���C�Y. 
            Console.WriteLine("userInfo.name = " + userInfo.name); // userInfo.name���o��.
            Console.WriteLine("userInfo.age = " + userInfo.age); // userInfo.age���o��.
            Console.WriteLine("userInfo.address = " + userInfo.address); // userInfo.address���o��.
        }

    }

}