<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                if (User.IsInRole("aspgroup"))
                {
                    Title = "aspgroup";
                }
                else
                {
                    Title = "Not aspgroup";
                }
            }
        </script>
    </head>
</html>