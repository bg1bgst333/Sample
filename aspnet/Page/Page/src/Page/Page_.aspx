<%@ Page Language="C#" CodeFile="Page_.aspx.cs" Inherits="Page_" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">Page_</title>
  </head>
  <body>
    <%
      Type t = GetType();
      string resStr = t.ToString();
      resStr = resStr + "<br />";
      Type baseType = t.BaseType;
      resStr = resStr + baseType.ToString();
      resStr = resStr + "<br />";
      Type baseBaseType = baseType.BaseType;
      resStr = resStr + baseBaseType.ToString();
      Response.Write(resStr);
    %>
  </body>
</html>