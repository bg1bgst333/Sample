<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">Page_</title>
  </head>
  <body>
    <%
      Type resType = Response.GetType();
      string strResType = resType.ToString();
      Response.Write(strResType);
    %>
  </body>
</html>