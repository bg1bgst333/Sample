using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace IObserver_T
{
    class CustomObserver : IObserver<string>
    {
        private int i;
        public CustomObserver(int i)
        {
            this.i = i; // 引数をメンバにセット.
        }
        public void OnCompleted()
        {
            //throw new NotImplementedException();
        }

        public void OnError(Exception error)
        {
            MessageBox.Show("OnError[" + i.ToString() + "]: " + error.Message); // MessageBox.Showでiとerror.Messageを表示.
            //throw new NotImplementedException();
        }

        public void OnNext(string value)
        {
            // valueの表示.
            MessageBox.Show("OnNext[" + i.ToString() + "]: " + value);    // MessageBox.Showでiとvalueを表示.
            //throw new NotImplementedException();
        }
    }
}
