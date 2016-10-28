<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>

<!DOCTYPE html>
<html>
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Admin JSP</title>
</head>
<body>
	<table>
		<tr>
			<th>ID</th>
			<th>Username</th>
			<th>Email</th>
			<th>IP</th>
		</tr>
		
		<c:forEach var="user" items="${users}">
			<tr>
				<td>${user.id}</td>
				<td>${user.name}</td>
				<td>${user.email}</td>
				<td><a href="userServlet?name=${user.name}">Go to user page</a></td>
			</tr>
		</c:forEach>
		
		<tr>
			<td>${users[1].id}</td>
			<td>${users[1].name}</td>
			<td>${users[1].email}</td>
			<td>${ip}</td>
		</tr>
	</table>
	
	<br>
	<p id="time"></p>
	
	<script type="text/javascript">
		var d = new Date();
		document.getElementById("time").innerHTML = "Current date: " + d.getDate() + "." + (d.getMonth() + 1) + "." + (d.getYear() + 1900) + "<br>" 
		+ "Current time: " + " " + d.getHours() + ":" + d.getMinutes();
	</script>
	
</body>
</html>