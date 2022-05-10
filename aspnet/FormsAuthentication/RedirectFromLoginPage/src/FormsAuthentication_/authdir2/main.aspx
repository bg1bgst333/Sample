<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                Title = "main";
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:Label id="label1" Text="main" runat="server" />
            </div>
        </form>
    </body>
</html>