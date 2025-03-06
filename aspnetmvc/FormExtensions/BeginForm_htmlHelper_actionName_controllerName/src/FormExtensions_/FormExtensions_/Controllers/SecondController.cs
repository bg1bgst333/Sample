using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

namespace FormExtensions_.Controllers
{
    public class SecondController : Controller
    {
        //
        // GET: /Second/

        public ActionResult Index()
        {
            return View();
        }

        //
        // Post: /Second/

        [AcceptVerbs(HttpVerbs.Post)]
        public ActionResult Index(String name)
        {
            ViewData["msg"] = String.Format("‚±‚ñ‚É‚¿‚Í, " + name + "‚³‚ñ!");
            return View("Result");
        }

    }
}
