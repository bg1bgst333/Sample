<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                if (User.IsInRole("Users"))
                {
                    Title = "Users";
                }
                else
                {
                    Title = "Not Users";
                }
            }
        </script>
    </head>
</html>