<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">HttpRequest_</title>
  </head>
  <body>
    <form action="HttpRequest_.aspx?key1=value1&key2=value2" method="POST">
      <input type="submit" value="OK" />
    </form>
    <%
      for (int i = 0; i < Request.QueryString.Count; i++){
        Response.Write(Request.QueryString.GetKey(i) + " = " + Request.QueryString.Get(i) + "<br />");
      }
      Response.Write("Request.QueryString[\"key1\"] = " + Request.QueryString["key1"] + "<br />");
      Response.Write("Request.QueryString[\"key2\"] = " + Request.QueryString["key2"] + "<br />");
    %>
  </body>
</html>