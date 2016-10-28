package bg.elsys.ip.servlet;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class AdminServlet extends HttpServlet {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1126486565983113076L;

	public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		response.setContentType("text/html");

		request.setAttribute("users", getUsers());
		getServletContext().getRequestDispatcher("/WEB-INF/admin.jsp")
			.forward(request, response);
	}
	
	private List<User> getUsers() {
		List<User> users = new ArrayList<>();
		users.add(new User(1, "admin", "admin@admin.bg"));
		users.add(new User(2, "user", "user@gmail.com"));
		return users;
	}

}
