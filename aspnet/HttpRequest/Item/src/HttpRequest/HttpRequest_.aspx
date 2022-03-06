<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">HttpRequest_</title>
  </head>
  <body>
    <form action="HttpRequest_.aspx?querykey1=queryvalue1&querykey2=queryvalue2" method="POST">
      <input type="text" name="formkey1" value="formvalue1" />
      <input type="text" name="formkey2" value="formvalue2" />
      <input type="submit" value="OK" />
    </form>
    <%
      Response.Write("Request[\"querykey1\"] = " + Request["querykey1"] + "<br />");
      Response.Write("Request[\"querykey2\"] = " + Request["querykey2"] + "<br />");
      Response.Write("Request[\"formkey1\"] = " + Request["formkey1"] + "<br />");
      Response.Write("Request[\"formkey2\"] = " + Request["formkey2"] + "<br />");
    %>
  </body>
</html>