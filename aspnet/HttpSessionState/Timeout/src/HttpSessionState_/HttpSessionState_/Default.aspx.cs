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

namespace HttpSessionState_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (!IsPostBack)
            {
                Session.Timeout = 1;
                Session["data1"] = (object)"ABCDE";
                Session["data2"] = (object)"FGHIJ";
            }
            label1.Text = (string)Session["data1"];
            label2.Text = (string)Session["data2"];
        }
    }
}
