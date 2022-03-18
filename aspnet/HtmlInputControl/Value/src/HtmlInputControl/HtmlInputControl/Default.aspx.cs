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

namespace HtmlInputControl
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            input1.ServerClick += new EventHandler(input1_ServerClick);
        }

        void input1_ServerClick(object sender, EventArgs e)
        {
            input1.Value = "Clicked!";
        }
    }
}
