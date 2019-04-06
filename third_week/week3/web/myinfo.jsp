<%@ page import="com.hyc.pojo.User" %>
<%@ page import="java.util.Map" %><%--
  Created by IntelliJ IDEA.
  User: Misterchaos
  Date: 2019/4/6
  Time: 13:43
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%
    String userName = null;
    String nickName = null;
    String password = null;
    String gender = null;

    request.setCharacterEncoding("utf-8");
    User stu = (User) request.getAttribute("login");
    if (stu != null) {
        userName = stu.getUserName();
        nickName = stu.getNickName();
        password = "****";
        gender = stu.getGender();

    }
%>
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
        <h1 align="center">个人中心</h1>
        <p>请填写信息</p>
        <%
            Map<String, String> msg = (Map<String, String>) request.getAttribute("message");
            if (msg != null) {
                out.print("<hr><p>提示信息</p><p>\n");
                for (String key : msg.keySet()) {
                    out.print(msg.get(key) + "<br/>");
                }
                out.print("</p>");
            }
        %>
        <a href="/index.jsp" align="center" methods="post">
            <button type="button" class="btn btn-primary">注册新账号</button>
        </a>
        <a href="/login.jsp">
            <button name="method" class="btn btn-primary" value="登陆">重新登陆</button>
        </a>
    </div>
    <div class="jumbotron">
        <div class="table-responsive" align="center" style="padding: 80px">
            <table class="table table-striped" align="left" style="padding: 80px" border="1">
                <caption align="left"><%=userName%>的个人信息</caption>
                <tr>
                    <th align="left">用户名</th>
                    <th align="left">昵称</th>
                    <th align="left">密码</th>
                    <th align="left">性别</th>
                </tr>
                <tr>
                    <td align="left"><%=userName%>
                    </td>
                    <td align="left"><%=nickName%>
                    </td>
                    <td align="left"><%=password%>
                    </td>
                    <td align="left"><%=gender%>
                    </td>
                </tr>
            </table>
        </div>
    </div>

</div>
</body>
</html>

