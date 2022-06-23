using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.Web.Mvc.Ajax;

namespace ControllerBase_.Controllers
{
    public class FirstController : Controller
    {
        //
        // GET: /First/

        public ActionResult Index()
        {
            Type viewDataType = ViewData.GetType();
            return View();
        }

    }
}
