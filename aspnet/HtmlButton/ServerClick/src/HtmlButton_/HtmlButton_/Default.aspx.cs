using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace HtmlButton_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            button1.ServerClick += new EventHandler(button1_ServerClick);
            button1.ServerClick += new EventHandler(button1_ServerClick2);
        }

        void button1_ServerClick(object sender, EventArgs e)
        {
            button1.InnerText = "Clicked!";
            //throw new Exception("The method or operation is not implemented.");
        }

        void button1_ServerClick2(object sender, EventArgs e)
        {
            Title = "Clicked!";
        }
    }
}
