using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

namespace Controller_.Controllers
{
    public class FirstController : Controller
    {
        //
        // GET: /First/
        /*
        public ActionResult Index()
        {
            ViewData["msg"] = "ABCDE";
            var vr = View();
            return vr;
        }
        */

        //
        // GET: /First/id

        public ActionResult Index(string id)
        {
            ViewData["msg"] = "ABCDE";
            ViewData["id"] = id;
            var vr = View();
            return vr;
        }

    }
}
