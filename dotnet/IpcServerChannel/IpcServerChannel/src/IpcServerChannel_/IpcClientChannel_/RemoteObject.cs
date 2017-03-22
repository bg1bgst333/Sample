using System;
using System.Collections.Generic;
using System.Text;

//namespace IpcClientChannel_
namespace Ipc_
{
    // クライアントとサーバで共有するオブジェクトRemoteObject
    public class RemoteObject : MarshalByRefObject
    {
        // メッセージを共有.
        private string message; // メッセー文字列message.
        public string Message   // messageの取得・設定を扱うプロパティMessage.
        {
            get
            {
                return message;
            }
            set
            {
                message = value;
            }
        }
    }
}