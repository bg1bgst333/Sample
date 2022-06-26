<%@ Page Language="C#" Inherits="System.Web.Mvc.ViewPage" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Post</title>
</head>
<body>
    <div>
        <%
          Response.Write("ViewData[\"name\"] = " + ViewData["name"]);
        %>
        <form action="/First/Post/" method="post">
            <input id="name" name="name" type="text" value="" />
            <input type="submit" value="submit" />
        </form>
    </div>
</body>
</html>
