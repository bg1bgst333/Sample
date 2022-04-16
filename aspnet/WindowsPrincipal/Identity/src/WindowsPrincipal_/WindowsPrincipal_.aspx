<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                Type identityType = User.Identity.GetType();
                string strIdentityType = identityType.ToString();
                Title = strIdentityType;
            }
        </script>
    </head>
</html>