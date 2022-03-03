<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">Page_</title>
  </head>
  <body>
    <%
      Type reqType = Request.GetType();
      string strReqType = reqType.ToString();
      Response.Write(strReqType);
    %>
  </body>
</html>