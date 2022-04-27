<%@ Page Language="C#" %>
<%@ Import namespace="System.IO" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                string filename = Server.MapPath(".") + @"\test.txt";
                StreamWriter sw = new StreamWriter(filename);
                sw.WriteLine("ABCDE");
                sw.Close();
            }
        </script>
    </head>
</html>