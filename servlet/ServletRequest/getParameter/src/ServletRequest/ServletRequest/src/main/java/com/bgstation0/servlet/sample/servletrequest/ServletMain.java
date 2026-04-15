package com.bgstation0.servlet.sample.servletrequest;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/ServletMain")
public class ServletMain extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        resp.setContentType("text/html");
        String selected = req.getParameter("radiobutton");

        PrintWriter out = resp.getWriter();
        out.println("<html><head></head><body>");
        out.println("<p>selected = " + selected + "</p>");
        out.println("</body></html>");
    }
}
