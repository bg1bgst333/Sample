using System;

public partial class Page1 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    public void button1_Click(object sender, EventArgs e)
    {
        button1.Text = smd.SiteMapProvider;
    }
}