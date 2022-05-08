<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void button1_Click(object sender, EventArgs e)
            {
                if (IsPostBack)
                {
                    if (checkBox1.Checked)
                    {
                        Title = "Checked!";
                    }
                    else
                    {
                        Title = "Not checked!";
                    }
                }
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:CheckBox id="checkBox1" Text="checkBox1" runat="server" />
            </div>
            <div>
                <asp:Button id="button1" Text="Button1" OnClick="button1_Click" runat="server" />
            </div>
        </form>
    </body>
</html>