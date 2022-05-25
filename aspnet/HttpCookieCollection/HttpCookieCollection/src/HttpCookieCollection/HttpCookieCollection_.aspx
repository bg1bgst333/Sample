<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">HttpCookieCollection_</title>
  </head>
  <body>
    <%
      HttpCookieCollection cookies = Response.Cookies;
      Response.Write("cookies.Count = " + cookies.Count);
    %>
  </body>
</html>