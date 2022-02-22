<%@ Page Language="C#" %>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">embedded_code_blocks</title>
  </head>
  <body>
    <% for (int i = 0; i < 10; i++){%>
      <div>
        <% Response.Write(i); %>
      </div>
    <% }%>
  </body>
</html>