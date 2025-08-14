package com.bgstation0.servlet.sample.genericservlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebInitParam;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(
	urlPatterns = {"/Param"},
	initParams =
	{
		@WebInitParam(name = "param1", value = "123"),
		@WebInitParam(name = "param2", value = "abc")
	}
)
public class ServletMain extends HttpServlet {
	@Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        String param1 = getInitParameter("param1");
        String param2 = getInitParameter("param2");
        resp.setContentType("text/html");
        PrintWriter out = resp.getWriter();
        out.println("<html><body>");
        out.println("<h1>Windows-Eclipse-Servlet</h1>");
        out.println("<p>param1 = " + param1 + "</p>");
        out.println("<p>param2 = " + param2 + "</p>");
        out.println("</body></html>");
    }
}
