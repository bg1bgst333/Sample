using System;
using System.Diagnostics;
using System.Web.UI.WebControls;

namespace Button_
{
    public class CustomButton : Button
    {
        protected override void OnClick(System.EventArgs e)
        {
            Debug.WriteLine("CustomButton.OnClick begin");
            base.OnClick(e);
            Debug.WriteLine("CustomButton.OnClick end");
        }
    }
}