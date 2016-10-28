package bg.elsys.ip.servlet;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.Filter;
import javax.servlet.FilterChain;
import javax.servlet.FilterConfig;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.ServletResponse;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class MyFilter implements Filter {

	private Cookie cookie;

	@Override
	public void destroy() {
	}

	@Override
	public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain)
			throws IOException, ServletException {
		PrintWriter out = response.getWriter();

		String username = request.getParameter("name");
		String password = request.getParameter("password");

		if (checkCookie(request)) {
			chain.doFilter(request, response);
		} else if ("admin".equals(username) && "pass".equals(password)) {
			((HttpServletResponse) response).addCookie(new Cookie("testCookie", "testValue"));
			chain.doFilter(request, response);
		} else {
			out.print("Username or password error!");
			RequestDispatcher dispatcher = request.getRequestDispatcher("index.html");
			dispatcher.forward(request, response);
		}

	}

	@Override
	public void init(FilterConfig arg0) throws ServletException {
	}

	private boolean checkCookie(ServletRequest request) {
		HttpServletRequest req = (HttpServletRequest) request;

		Cookie[] cookies = req.getCookies();
		if (cookies != null) {
			for (Cookie ck : cookies) {
				if ("testCookie".equals(ck.getName()) && "testValue".equals(ck.getValue())) {
					return true;
				}
			}
		}
		return false;
	}

}
