using System;

public partial class Page1 : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        smd.SiteMapProvider = "TestProvider";
    }
    public void button1_Click(object sender, EventArgs e)
    {
        smd.SiteMapProvider = "TestProvider2";
    }
}