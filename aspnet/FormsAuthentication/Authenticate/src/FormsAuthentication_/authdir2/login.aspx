<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void login_Click(object sender, EventArgs e)
            {
                if (FormsAuthentication.Authenticate(username.Text, password.Text))
                {
                    label1.Text = "Authentication Success!";
                }
                else
                {
                    label1.Text = "Authentication Failed!";
                }
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:Label id="label1" Text="login" runat="server" />
            </div>
            <div>
                <asp:TextBox id="username" runat="server" />
            </div>
            <div>
                <asp:TextBox id="password" TextMode="Password" runat="server" />
            </div>
            <div>
                <asp:CheckBox id="persist" Text="Save credentials" runat="server" />
            </div>
            <div>
                <asp:Button id="login" Text="Login" OnClick="login_Click" runat="server" />
            </div>
        </form>
    </body>
</html>