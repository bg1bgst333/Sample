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

namespace Button_
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            CustomButton customButton = new CustomButton();
            customButton.ID = "custom1";
            customButton.Text = "custom1";
            customButton.Click += new EventHandler(customButton_Click);
            form1.Controls.Add(customButton);
        }

        void customButton_Click(object sender, EventArgs e)
        {
            Debug.WriteLine("customButton_Click begin");
            Title = "Clicked!";
            Debug.WriteLine("customButton_Click end");
        }
    }
}
