<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">HttpResponse_</title>
  </head>
  <body>
    <%
      Type resCookiesType = Response.Cookies.GetType();
      string strResCookiesType = resCookiesType.ToString();
      Response.Write(strResCookiesType);
    %>
  </body>
</html>