<%@ Page Language="C#" %>
<%@ Import namespace="System.Security.Principal" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                WindowsIdentity current = WindowsIdentity.GetCurrent();
                Title = current.Name;
            }
        </script>
    </head>
</html>