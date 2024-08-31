<%@ Page Language="C#" Inherits="System.Web.Mvc.ViewPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Index</title>
</head>
<body>
    <div>
        <%
            string str1 = "<b>‚ ‚¢‚¤‚¦‚¨</b>";
            Response.Write(str1);
            string str2 = Html.Encode(str1);
            Response.Write(str2);
        %>
    </div>
</body>
</html>
