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
    <script runat="server">
      protected void Page_Load(object sender, EventArgs e)
      {
        button1.ServerClick += new EventHandler(Button1_ServerClick);
      }
      void Button1_ServerClick(object sender, EventArgs e)
      {
        button1.InnerText = "Clicked!";
      }
    </script>
  </head>
  <body>
    <form runat="server">
      <button id="button1" onclick="button1_click();" runat="server">button1</button>
    </form>
  </body>
</html>