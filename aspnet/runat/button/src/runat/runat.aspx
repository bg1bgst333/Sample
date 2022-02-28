<%@ Page Language="C#" CodeFile="runat.aspx.cs" Inherits="runat" %>
<html>
  <head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <title id="title_index">runat</title>
    <script>
      function button1_click(){
        alert("clicked!");
      }
    </script>
  </head>
  <body>
    <button id="button1" onclick="button1_click();" runat="server">button1</button>
  </body>
</html>