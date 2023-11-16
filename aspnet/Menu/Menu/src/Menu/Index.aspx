<%@ Page Language="C#" AutoEventWireup="true" %>
<html>
    <head>
        <title>Index</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <asp:Menu id="menu1" runat="server" DataSourceID="smd">
            </asp:Menu>
            <asp:SiteMapDataSource id="smd" runat="server" />
        </form>
    </body>
</html>
