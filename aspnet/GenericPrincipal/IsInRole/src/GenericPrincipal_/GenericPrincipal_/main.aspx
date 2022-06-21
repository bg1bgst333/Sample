<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="main.aspx.cs" Inherits="GenericPrincipal_.main" %>
<%@ Import namespace="System.Security.Principal" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>無題のページ</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <%
            FormsIdentity identity = (FormsIdentity)User.Identity;
            Response.Write("identity.Name = " + identity.Name + "<br />");
            GenericPrincipal principal = (GenericPrincipal)User;
            if (principal.IsInRole("admin"))
            {
                Response.Write("principal.IsInRole(\"admin\")"); 
            }
            if (principal.IsInRole("users"))
            {
                Response.Write("principal.IsInRole(\"users\")");
            }
        %>
    </div>
    </form>
</body>
</html>
