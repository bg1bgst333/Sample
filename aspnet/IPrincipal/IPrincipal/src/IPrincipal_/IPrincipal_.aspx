<%@ Page Language="C#" %>
<%@ Import namespace="System.Security.Principal" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                IPrincipal principal = User;
                if (principal.IsInRole("Users"))
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