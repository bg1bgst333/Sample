<%@ Page Language="C#"%>
<%@ Register Tagprefix="uc" Tagname="UserControlRed" Src="UserControlRed.ascx" %>
<%@ Register Tagprefix="uc" Tagname="UserControlBlue" Src="UserControlBlue.ascx" %>
<html>
    <head runat="server">
        <script runat="server">
        </script>
        <title>RegisterDirective</title>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <uc:UserControlRed id="usercontrolred1" runat="server" />
            </div>
            <div>
                <uc:UserControlBlue id="usercontrolblue1" runat="server" />
            </div>
        </form>
    </body>
</html>