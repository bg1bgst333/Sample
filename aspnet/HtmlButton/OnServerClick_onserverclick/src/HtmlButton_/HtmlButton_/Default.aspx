<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="HtmlButton_._Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
    <head runat="server">
        <title>無題のページ</title>
    </head>
    <script runat="server">
        protected void Button1_ServerClick(object sender, EventArgs e)
        {
            button1.InnerText = "Clicked!";
        }
    </script>
    <body>
        <form id="form1" runat="server">
            <button id="button1" onserverclick="Button1_ServerClick" runat="server">Button1</button>
        </form>
    </body>
</html>
