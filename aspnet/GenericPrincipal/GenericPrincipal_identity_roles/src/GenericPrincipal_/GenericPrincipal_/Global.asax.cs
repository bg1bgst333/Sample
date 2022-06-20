using System;
using System.Data;
using System.Configuration;
using System.Collections;
using System.Security.Principal;
using System.Web;
using System.Web.Security;
using System.Web.SessionState;

namespace GenericPrincipal_
{
    public class Global : System.Web.HttpApplication
    {

        protected void Application_Start(object sender, EventArgs e)
        {

        }

        protected void Application_End(object sender, EventArgs e)
        {

        }

        protected void Application_AuthenticateRequest(object sender, EventArgs e)
        {
            HttpCookie cookie = Context.Request.Cookies[FormsAuthentication.FormsCookieName];
            if (cookie == null)
            {
                return;
            }
            FormsAuthenticationTicket ticket = null;
            try
            {
                ticket = FormsAuthentication.Decrypt(cookie.Value);
            }
            catch (Exception ex)
            {
                return;
            }
            if (ticket == null)
            {
                return;
            }
            string role = ticket.UserData;
            FormsIdentity identity = new FormsIdentity(ticket);
            GenericPrincipal principal = new GenericPrincipal(identity, new string[] { role });
        }
    }
}