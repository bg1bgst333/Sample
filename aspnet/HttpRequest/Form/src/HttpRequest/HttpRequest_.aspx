<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">HttpRequest_</title>
  </head>
  <body>
    <form action="HttpRequest_.aspx" method="POST">
      <input type="text" name="key1" value="value1" />
      <input type="text" name="key2" value="value2" />
      <input type="submit" value="OK" />
    </form>
    <%
      for (int i = 0; i < Request.Form.Count; i++){
        Response.Write(Request.Form.GetKey(i) + " = " + Request.Form.Get(i) + "<br />");
      }
      Response.Write("Request.Form[\"key1\"] = " + Request.Form["key1"] + "<br />");
      Response.Write("Request.Form[\"key2\"] = " + Request.Form["key2"] + "<br />");
    %>
  </body>
</html>