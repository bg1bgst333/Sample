<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Index.aspx.cs" Inherits="Page1" %>
<html>
    <head>
        <title>Index</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <asp:Menu id="menu1" runat="server" DataSourceID="smd">
            </asp:Menu>
            <asp:SiteMapDataSource id="smd" runat="server" />
            <asp:Button id="button1" Text="Button1" OnClick="button1_Click" runat="server" />
        </form>
    </body>
</html>
