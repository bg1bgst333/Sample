<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="Control_._Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
    <head runat="server">
        <title>無題のページ</title>
    </head>
    <script runat="server">
    </script>
    <body>
        <%
            Type vsType = ViewState.GetType();
            string strVSType = vsType.ToString();
            Response.Write(strVSType);
        %>
    </body>
</html>
