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
        public void OnCompleted()
        {
            //throw new NotImplementedException();
        }

        public void OnError(Exception error)
        {
            //throw new NotImplementedException();
        }

        public void OnNext(string value)
        {
            // valueの表示.
            MessageBox.Show("OnNext: " + value);    // MessageBox.Showでvalueを表示.
            //throw new NotImplementedException();
        }
    }
}
