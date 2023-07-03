<%@ Page Language="C#"%>
<%@ Register Tagprefix="uc" Tagname="UserControl" Src="ControlDirective.ascx" %>
<html>
    <head runat="server">
        <script runat="server">
        </script>
        <title>ControlDirective</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <uc:UserControl id="usercontrol1" runat="server" />
        </form>
    </body>
</html>