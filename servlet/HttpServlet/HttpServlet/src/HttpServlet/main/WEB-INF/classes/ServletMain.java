import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class ServletMain extends HttpServlet{
  public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException{
    PrintWriter out = response.getWriter();
    out.println("<html><head><title>main</title></head><body>ABCDE</body></html>");
    out.close();
  }
}
