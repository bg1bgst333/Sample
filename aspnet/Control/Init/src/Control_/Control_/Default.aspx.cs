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

namespace Control_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected override void OnInit(EventArgs e)
        {
            Init += new EventHandler(Page_Init);
            Debug.WriteLine("Page.OnInit before");
            base.OnInit(e);
            Debug.WriteLine("Page.OnInit after");
        }
        protected void Page_Init(object sender, EventArgs e)
        {
            Debug.WriteLine("Page_Init");
        }
        protected void Page_Load(object sender, EventArgs e)
        {
            Debug.WriteLine("Page_Load");
        }
    }
}
