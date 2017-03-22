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

//namespace IpcServerChannel_
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

            // IPCサーバーチャンネルを作成.
            IpcServerChannel server = new IpcServerChannel("ipcserver");    // ポート名が"ipcserver"なIpcServerChannelオブジェクトserverを生成.

            // チャンネルを登録.
            ChannelServices.RegisterChannel(server, true);    // ChannelServices.RegisterChannelでチャンネルserverを登録.

            // リモートオブジェクトの作成.
            remoteObj = new RemoteObject(); // RemoteObjectオブジェクトを生成し, remoteObjに格納.

            // リモートオブジェクトの公開.
            RemotingServices.Marshal(remoteObj, "message", typeof(RemoteObject));   //  RemotingServices.MarshalでremoteObjを公開.("ipc://ipcserver/message"というURIで公開される.)
        }

        // button1がクリックされた時.
        private void button1_Click(object sender, EventArgs e)
        {
            // 入力されたテキストをリモートオブジェクトに格納.
            remoteObj.Message = textBox1.Text;  // textBox1.TextをremoteObj.Messageに格納.
        }
    }
}