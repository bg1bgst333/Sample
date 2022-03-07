using System;
using System.Diagnostics;
using System.Web.UI.HtmlControls;

namespace HtmlButton_
{
    public class CustomHtmlButton : HtmlButton
    {
        protected override void OnServerClick(EventArgs e)
        {
            Debug.WriteLine("CustomHtmlButton.OnServerClick begin");
            base.OnServerClick(e);
            Debug.WriteLine("CustomHtmlButton.OnServerClick end");
        }
    }
}