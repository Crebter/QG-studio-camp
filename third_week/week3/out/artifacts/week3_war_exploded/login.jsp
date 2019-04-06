<%@ page import="java.util.Map" %><%--
  Created by IntelliJ IDEA.
  User: Misterchaos
  Date: 2019/4/6
  Time: 12:39
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>week3</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet"
          href="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
</head>
<body>
<div class="container">
    <div class="jumbotron">
        <h1 align="center">登陆</h1>
        <p>请填写信息</p>
        <%
            Map<String, String> msg = (Map<String, String>) request.getAttribute("message");
            if (msg != null) {
                out.print("<hr><p>提示信息:</p><p>\n");
                for (String key : msg.keySet()) {
                    out.print(msg.get(key) + "<br/>");
                }
                out.print("</p>");
            }
        %>
    </div>
    <div class="jumbotron">
        <form action = "/User?method=登陆" method="post" >

            请输入用户名:<input type = "text" class="form-control"  name = "userName"/><br/>
            请输入密码  :<input type = "text"  class="form-control"  name = "password"/><br/>
            <a href="/User?method=登陆">
                <button class="btn btn-primary">登陆</button>
            </a>
            <a href="/index.jsp" align="center" methods="post">
                <button type="button" class="btn btn-primary">前往注册</button>
            </a>
        </form>
    </div>
</div>
</body>
</html>
