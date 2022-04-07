<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Label_._Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
    <head runat="server">
        <title>無題のページ</title>
    </head>
    <script runat="server">
        void button1_Click(object sender, EventArgs e)
        {
            label1.Text = "Clicked!";
        }
    </script>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:Label id="label1" Text="Label1" runat="server" />
            </div>
            <div>
                <asp:Button id="button1" Text="Button1" OnClick="button1_Click" runat="server" />
            </div>
        </form>
    </body>
</html>
