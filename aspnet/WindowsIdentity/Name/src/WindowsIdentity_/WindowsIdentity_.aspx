<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                Title = User.Identity.Name;
            }
        </script>
    </head>
</html>