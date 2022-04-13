<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
		Type userType = User.GetType();
            	string strUserType = userType.ToString();
            	Title = strUserType;
            }
        </script>
    </head>
</html>