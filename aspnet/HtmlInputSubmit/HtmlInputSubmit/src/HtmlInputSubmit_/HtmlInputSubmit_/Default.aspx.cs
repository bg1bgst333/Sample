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

namespace HtmlInputSubmit_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            Type submit1Type = submit1.GetType();
            string strSubmit1Type = submit1Type.ToString();
            submit1.Value = strSubmit1Type;
        }
    }
}
