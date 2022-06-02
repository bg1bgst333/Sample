<%@ Page Language="C#" %>
<html>
    <head runat="server">
        <script runat="server">
            void Page_Load(object sender, EventArgs e)
            {
                Title = "main";
            }
            void logout_Click(object sender, EventArgs e)
            {
                FormsAuthentication.SignOut();
                FormsAuthentication.RedirectToLoginPage();
            }
            void add_Click(object sender, EventArgs e)
            {
                HttpCookie cookie = new HttpCookie("first");
                cookie.Name = "second";
                cookie.Value = "abcde";
                Response.Cookies.Add(cookie);
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:Label id="label1" Text="main" runat="server" />
            </div>
            <div>
                <asp:Button id="logout" Text="Logout" OnClick="logout_Click" runat="server" />
            </div>
            <div>
                <asp:Button id="add" Text="Add" OnClick="add_Click" runat="server" />
            </div>
            <div>
                <%
                  HttpCookieCollection reqCookies = Request.Cookies;
                  Response.Write("reqCookies.Count = " + reqCookies.Count);
                %>
            </div>
            <div>
                <%
                  if (reqCookies.Count > 0)
                  {
                      for (int i = 0; i < reqCookies.Count; i++)
                      {
                          HttpCookie cookie = reqCookies[i];
                          Response.Write("cookie.Name = " + cookie.Name + "<br />");
                          Response.Write("cookie.Value = " + cookie.Value + "<br />");
                      }
                  }
                %>
            </div>
            <div>
                <%
                  HttpCookieCollection resCookies = Response.Cookies;
                  Response.Write("resCookies.Count = " + resCookies.Count);
                %>
            </div>
        </form>
    </body>
</html>