using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

namespace ViewDataDictionary_.Controllers
{
    public class FirstController : Controller
    {
        //
        // GET: /First/

        public ActionResult Index()
        {
            ViewData["msg"] = "ABCDE";
            return View();
        }

    }
}
