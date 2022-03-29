<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Page_._Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
    <head runat="server">
        <title>無題のページ</title>
        <script runat="server">
            void input1_ServerClick(object sender, EventArgs e)
            {
                text1.Value = "Clicked!";
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <input id="text1" type="text" value="text1" runat="server" />
            <input id="input1" type="button" value="input1" onserverclick="input1_ServerClick" runat="server" />
            <input id="submit1" type="submit" value="submit1" runat="server" />
        </form>
    </body>
</html>
