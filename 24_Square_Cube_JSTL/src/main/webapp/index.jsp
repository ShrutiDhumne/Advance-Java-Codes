<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
    pageEncoding="ISO-8859-1"%>
    
 <%@taglib uri='http://java.sun.com/jsp/jstl/core' prefix='c' %>
 
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<form action="index.jsp">
	<Label> Enter the Number : </Label>
	<input type = "number" name = "num"><br>
	
	<p>Please select your Option : </p>
	  <input type="radio" id="square" name="opt" value="square">
	  <label for="html">Square</label><br>
	  <input type="radio" id="cube" name="opt" value="cube">
	  <label for="css">Cube</label><br>
	  
	<br>
	<input type="submit" value="Submit"><br>
</form>

<c:set var="num" value="${param.num}" > </c:set>
<c:set var="opt" value="${param.opt}" > </c:set>

<c:if test="${opt eq 'square'}">
	<p>Square is: <c:out value="${num*num}"/><p>
</c:if>
<c:if test="${opt eq 'cube'}">
	<p>Cube is: <c:out value="${num*num*num}"/><p>
</c:if>


</body>
</html>