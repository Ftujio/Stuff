package bg.elsys.ip.servlet;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class AdminServlet extends HttpServlet{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -8155830247707217687L;
	
	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		response.setContentType("test/html");
		
		request.setAttribute("users", getUsers());
		getServletContext().getRequestDispatcher('/WEB-INF/admin.jsp').forward(request, response);
	}
	
	private List<User> getUsers(){
		List<User> users = new ArrayList<>();
		users.add(new User(1, "admin", "admin@admin.bg"));
		users.add(new User(2, "user", "user@gmail.bg"));
		
		return users;
	}
	
	public void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");
		PrintWriter out = response.getWriter();
		
		out.print("Welcome, Admin");
		out.close();
	}
	
}
