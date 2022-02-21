import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ServletMain extends HttpServlet{
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
    Class responseClass = response.getClass();
    PrintWriter out = response.getWriter();
    out.print("<html><head><title>main</title></head><body>");
    out.print(responseClass.toString());
    out.println("</body></html>");
    out.close();
  }
}
