<%@ Page Language="C#" %>
<%@ Import namespace="System.Security.Principal" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                IIdentity identity = User.Identity;
                Title = identity.Name;
            }
        </script>
    </head>
</html>