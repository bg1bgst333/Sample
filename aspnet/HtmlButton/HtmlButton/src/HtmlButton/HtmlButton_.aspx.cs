using System;

public partial class HtmlButton_ : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        button1.ServerClick += new EventHandler(Button1_ServerClick);
    }

    void Button1_ServerClick(object sender, EventArgs e)
    {
        Type button1Type = button1.GetType();
        string strButton1Type = button1Type.ToString();
        button1.InnerText = strButton1Type;
    }
}
