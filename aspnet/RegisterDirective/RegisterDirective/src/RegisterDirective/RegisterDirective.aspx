<%@ Page Language="C#"%>
<%@ Register Tagprefix="ucr" Tagname="UserControlRed" Src="UserControlRed.ascx" %>
<%@ Register Tagprefix="ucb" Tagname="UserControlBlue" Src="UserControlBlue.ascx" %>
<html>
    <head runat="server">
        <script runat="server">
        </script>
        <title>RegisterDirective</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <ucr:UserControlRed id="usercontrolred1" runat="server" />
            </div>
            <div>
                <ucb:UserControlBlue id="usercontrolblue1" runat="server" />
            </div>
        </form>
    </body>
</html>