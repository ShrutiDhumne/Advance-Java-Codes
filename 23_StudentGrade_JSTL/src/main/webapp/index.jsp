<%@ page language="java" contentType="text/html; charset=UTF-8"
 pageEncoding="UTF-8"%>
 <%@taglib uri='http://java.sun.com/jsp/jstl/core' prefix='c' %>
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Student Grade</title>
</head>
<body>

<link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@4.5.3/dist/css/bootstrap.min.css"
integrity="sha384-TX8t27EcRE3e/ihU7zmQxVncDAy5uIKz4rEkgIXeMed4M0jlfIDPvg6uqKI2xXr2"
crossorigin="anonymous">
</head>
<body style="background-color:LightBlue;">
<div class="form-group col-12 p-0">
</div>
<form id="form" action="index.jsp" method="get" class="form-horizontal">
	<div class="form-group">
		<div class="col-sm-12">
			<h2 style="text-align: center">Grade Calculation</h2>
		</div>
	</div>
	<hr/>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label>Name</label>
		<input type="text" name="myname" class="form-control" >
		</div>
	</div>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label >DAA </label>
		<input type="number" name="daa" class="form-control" >
		</div>
	</div>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label>CD </label>
		<input type="number" name="cd" class="form-control" >
		</div>
	</div>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label>Java</label>
		<input type="number" name="java" class="form-control" >
		</div>
	</div>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label>SE</label>
		<input type="number" name="se" class="form-control" >
	</div>
	</div>
	<div class="form-group">
		<div class="col-sm-4"></div>
		<div class="col-sm-4 mx-auto">
		<label>ML</label>
		<input type="number" name="ml" class="form-control" >
		</div>
	</div>
	<br/>
	<div class="form-group" align="center">
		<div class="col-sm-6">
		<div class="col-sm-2">
		<Button class="btn btn-success" style="width: 80px;">Submit</Button>
		</div>
		<div class="col-sm-4">
		</div>
		</div>
	</div>
</form>
<hr>

<h3>Name: <c:out value="${param.myname}" /></h3>
<!-- 1.Set - Declare variable and scope -->
<c:set var="cd" value="${param.cd}" scope="application"> </c:set>
<c:set var="daa" value="${param.daa}" scope="application"> </c:set>
<c:set var="java" value="${param.java}" scope="application"> </c:set>
<c:set var="se" value="${param.se}" scope="application"> </c:set>
<c:set var="ml" value="${param.ml}" scope="application"> </c:set>

<!-- 2.Out-printing -->
<h3>SE : <c:out value="${se}"></c:out></h3>
<h3>DAA : <c:out value="${daa}"></c:out></h3>
<h3>Java : <c:out value="${java}"></c:out></h3>
<h3>SE : <c:out value="${se}"></c:out></h3>
<h3>ML : <c:out value="${ml}"></c:out></h3>
<br>
<c:set var="grade" value="${((cd+daa+java+se+ml)*100)/500}" scope="application"> </c:set>
<h3>Grade : <c:out value="${grade}"></c:out></h3>
<br>


<c:choose>
	<c:when test="${grade >= 75.00}">
	<center><h3>***Distintion***</h3></center>
	</c:when>
	<c:when test="${grade >= 60.00}">
	<center><h3>***First class***</h3></center>
	</c:when>
	<c:when test="${grade >= 35.00}">
	<center><h3>***Second Class***</h3></center>
	</c:when>
	<c:when test="${grade <= 35.00}">
	<center><h3>***You are failed*** </h3></center>
	</c:when>
</c:choose>
<hr>


</body>
</html>