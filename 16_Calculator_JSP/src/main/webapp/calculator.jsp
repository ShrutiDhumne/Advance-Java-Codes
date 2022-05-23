
<!DOCTYPE html>
<html>
<head>
<meta charset="ISO-8859-1">
<title>Insert title here</title>
</head>
<body>

<%!int no1; int no2;
String sign;
%>

<%
no1=Integer.parseInt(request.getParameter("no1"));
no2=Integer.parseInt(request.getParameter("no2"));
sign = request.getParameter("cal");

switch(sign){
case "ADD":
	out.println("Addition is -> "+(no1+no2)+"\n\n");
	break;
case "SUB":
	out.println("Subtraction is -> "+(no1-no2)+"\n\n");
	break;
case "MUL":
	out.println("Multiplication is -> "+(no1*no2)+"\n\n");
	break;
case "DIV":
	out.println("Division is -> "+(no1/no2)+"\n\n");
	break;
}

%>


</body>
</html>