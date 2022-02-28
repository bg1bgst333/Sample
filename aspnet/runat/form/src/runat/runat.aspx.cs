using System;

public partial class runat : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        button1.ServerClick += new EventHandler(Button1_ServerClick);
    }

    void Button1_ServerClick(object sender, EventArgs e)
    {
        button1.InnerText = "Clicked!";
    }
}
