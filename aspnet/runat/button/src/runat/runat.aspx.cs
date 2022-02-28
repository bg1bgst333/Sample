using System;

public partial class runat : System.Web.UI.Page{
    protected void Page_Load(object sender, EventArgs e)
    {
        button1.InnerText = "Loaded!";
    }
}