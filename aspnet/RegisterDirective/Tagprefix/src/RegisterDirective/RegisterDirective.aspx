<%@ Page Language="C#"%>
<%@ Register Tagprefix="ucr" Tagname="UserControl" Src="UserControlRed.ascx" %>
<%@ Register Tagprefix="ucb" Tagname="UserControl" Src="UserControlBlue.ascx" %>
<html>
    <head runat="server">
        <script runat="server">
        </script>
        <title>RegisterDirective</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <ucr:UserControl id="usercontrolred1" runat="server" />
            </div>
            <div>
                <ucb:UserControl id="usercontrolblue1" runat="server" />
            </div>
        </form>
    </body>
</html>