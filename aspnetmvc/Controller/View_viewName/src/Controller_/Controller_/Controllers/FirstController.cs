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

        public ActionResult Index()
        {
            return View();
        }

        // GET: /First/Post

        public ActionResult Post()
        {
            return View();
        }

        // POST: /First/Post
        [AcceptVerbs(HttpVerbs.Post)]
        public ActionResult Post(string name)
        {
            ViewData["name"] = name;
            return View("Result");
        }

    }
}
