<%@ Page Language="VB" %>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">Language</title>
  </head>
  <body>
    <% For i As Integer = 0 To 9 %>
      <div>
        <% Response.Write(i) %>
      </div>
    <% Next %>
  </body>
</html>