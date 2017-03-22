using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Runtime.Remoting;  // リモート(System.Runtime.Remoting名前空間)
using System.Runtime.Remoting.Channels; // チャネル(System.Runtime.Remoting.Channels名前空間)
using System.Runtime.Remoting.Channels.Ipc; // IPC(System.Runtime.Remoting.Channels.Ipc名前空間)
using System.Text;
using System.Windows.Forms;

//namespace IpcClientChannel_
namespace Ipc_
{
    public partial class Form1 : Form
    {
        // メンバフィールドの定義
        public RemoteObject remoteObj;  // 共有するRemoteObject型remoteObj.

        // コンストラクタ
        public Form1()
        {
            InitializeComponent();

            // IPCクライアントチャンネルを作成.
            IpcClientChannel client = new IpcClientChannel();   // IpcClientChannelオブジェクトclientを作成.

            // チャンネルを登録.
            ChannelServices.RegisterChannel(client, true);  // ChannelServices.RegisterChannelでチャンネルclientを登録.
        }

        // button1がクリックされた時.
        private void button1_Click(object sender, EventArgs e)
        {
            // リモートオブジェクトからテキストを取得.
            remoteObj = (RemoteObject)Activator.GetObject(typeof(RemoteObject), "ipc://ipcserver/message");   // Activator.GetObjectで取得してRemoteObjectにキャストしてremoteObjに格納.
            textBox1.Text = remoteObj.Message;  // textBox1.TextにremoteObj.Messageを格納.
        }
    }
}