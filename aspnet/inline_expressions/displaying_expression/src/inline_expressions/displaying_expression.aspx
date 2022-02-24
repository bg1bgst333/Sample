<%@ Page Language="C#" %>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">displaying_expression</title>
  </head>
  <body>
    <% int x = 123; %>
    <% int y = 100; %>
    <% string s1 = "ABCDE"; %>
    <% string s2 = "XYZ"; %>
    <div>
      <%= x + y %>
    </div>
    <div>
      <%= s1 + s2 %>
    </div>
  </body>
</html>