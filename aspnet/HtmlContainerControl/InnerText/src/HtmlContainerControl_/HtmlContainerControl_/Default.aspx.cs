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

namespace HtmlContainerControl_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            button1.InnerText = "Loaded!";
            button1.ServerClick += new EventHandler(button1_ServerClick);
        }

        void button1_ServerClick(object sender, EventArgs e)
        {
            button1.InnerText = "Clicked!";
        }
    }
}
