using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

namespace FormExtensions_.Controllers
{
    public class FirstController : Controller
    {
        //
        // GET: /First/

        public ActionResult Index()
        {
            return View();
        }

        //
        // Post: /First/

        [AcceptVerbs(HttpVerbs.Post)]
        public ActionResult Index(String name)
        {
            ViewData["msg"] = String.Format("Hello, " + name + "!");
            return View("Result");
        }
    }
}
