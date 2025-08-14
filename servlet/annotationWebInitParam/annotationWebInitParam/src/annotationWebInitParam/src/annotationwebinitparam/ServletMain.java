package annotationwebinitparam;

import java.io.*;
import javax.servlet.*;
import javax.servlet.annotation.*;
import javax.servlet.http.*;

@WebServlet(
    urlPatterns = {"/Param"},
    initParams =
    {
        @WebInitParam(name = "param1", value = "123")
    }
)
public class ServletMain extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        String param1 = getInitParameter("param1");
        resp.setContentType("text/html; charset=UTF-8");
        PrintWriter out = resp.getWriter();
        out.println("<html><body>");
        out.println("<h1>Windows-Servlet</h1>");
        out.println("<p>param1 = " + param1 + "</p>");
        out.println("</body></html>");
    }
}
