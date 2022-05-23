<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>
<%@
page import = "javax.servlet.http.*"
 %>
<%!
Cookie ck,ck1;
String name,roll;

%>
<%
name = request.getParameter("name");
roll = request.getParameter("roll");

//out.println(name.getClass().getSimpleName());
//name = "Shruti";
//out.println(name.getClass().getSimpleName());
//roll = "roll123";
ck = new Cookie("roll",request.getParameter("roll"));
ck1 = new Cookie("name",request.getParameter("name"));

out.println("<h3>Cookie created for "+ck.getName()+" and value is "+ck.getValue());
out.println("<br> Cookie created for "+ck1.getName()+" and value is "+ck1.getValue()+"<h3>");
%>
</body>
</html>