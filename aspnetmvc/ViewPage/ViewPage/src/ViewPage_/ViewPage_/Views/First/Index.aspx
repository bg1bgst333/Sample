<%@ Page Language="C#" Inherits="System.Web.Mvc.ViewPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Index</title>
</head>
<body>
    <div>
        <%
          Type type = GetType();
          string strType = type.ToString();
          Response.Write("strType = " + strType + "<br />");
          Type baseType = type.BaseType;
          string strBaseType = baseType.ToString();
          Response.Write("strBaseType = " + strBaseType);
        %>
    </div>
</body>
</html>
