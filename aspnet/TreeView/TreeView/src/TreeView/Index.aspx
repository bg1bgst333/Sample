<%@ Page Language="C#" AutoEventWireup="true" %>
<html>
    <head>
        <title>Index</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <asp:TreeView id="tree1" runat="server" DataSourceID="smd">
            </asp:TreeView>
            <asp:SiteMapDataSource id="smd" runat="server" />
        </form>
    </body>
</html>
