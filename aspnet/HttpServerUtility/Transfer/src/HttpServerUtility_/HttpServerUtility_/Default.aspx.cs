using System;
using System.Data;
using System.Diagnostics;
using System.Configuration;
using System.Collections;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace HttpServerUtility_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Debug.WriteLine("_Default.Page_Load");
            Debug.WriteLine("_Default Transfer before: " + Response.Status);
            Server.Transfer("NextPage.aspx");
            Debug.WriteLine("_Default Transfer after: " + Response.Status);
        }
    }
}
