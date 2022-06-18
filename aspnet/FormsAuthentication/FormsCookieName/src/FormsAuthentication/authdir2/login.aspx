<%@ Page Language="C#" %>
<%@ Import namespace="System.IO" %>
<%@ Import namespace="System.Xml" %>
<%@ Import namespace="System.Xml.Serialization" %>
<html>
    <head runat="server">
        <script runat="server">
            public class UserInfo
            {
                public string name;
                public string password;
                public string role;
            }
            public class AuthInfo
            {
                public UserInfo[] Users;
            }
            void login_Click(object sender, EventArgs e)
            {
                UserInfo userInfo;
                userInfo = Authenticate(username.Text, password.Text);
                if (userInfo != null)
                {
                    RedirectFromLoginPage(userInfo.name, userInfo.role, persist.Checked);
                }
                else
                {
                    label1.Text = "Authentication Failed!";
                }
            }
            UserInfo Authenticate(string username, string password)
            {
                AuthInfo authinfo = null;
                UserInfo result = null;
                FileStream stream = null;
                string filename = Server.MapPath("..") + "\\" + "users.xml";
                label1.Text = filename;
                try
                {
                    XmlSerializer serializer = new XmlSerializer(typeof(AuthInfo));
                    stream = new FileStream(filename, FileMode.Open, FileAccess.Read);
                    authinfo = (AuthInfo)serializer.Deserialize(stream);
                }
                catch (Exception ex)
                {
                    label1.Text = ex.Message;
                }
                finally
                {
                    if (stream != null)
                    {
                        stream.Close();
                    }
                }
                if (authinfo != null)
                {
                    foreach (UserInfo userinfo in authinfo.Users)
                    {
                        if (userinfo.name == username && userinfo.password == password)
                        {
                            result = userinfo;
                        }
                    }
                }
                return result;
            }
            void RedirectFromLoginPage(string username, string role, bool persistent)
            {
                FormsAuthenticationTicket ticket = new FormsAuthenticationTicket(1, username, DateTime.Now, DateTime.Now.AddMinutes(60), persistent, role);
                label1.Text = "FormsAuthentication.FormsCookieName = " + FormsAuthentication.FormsCookieName;
            }
        </script>
    </head>
    <body>
        <form id="form1" runat="server">
            <div>
                <asp:Label id="label1" Text="login" runat="server" />
            </div>
            <div>
                <asp:TextBox id="username" runat="server" />
            </div>
            <div>
                <asp:TextBox id="password" TextMode="Password" runat="server" />
            </div>
            <div>
                <asp:CheckBox id="persist" Text="Save credentials" runat="server" />
            </div>
            <div>
                <asp:Button id="login" Text="Login" OnClick="login_Click" runat="server" />
            </div>
        </form>
    </body>
</html>