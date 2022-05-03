<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                textBox1.TextMode = TextBoxMode.Password;
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:TextBox id="textBox1" runat="server" />
            </div>
        </form>
    </body>
</html>