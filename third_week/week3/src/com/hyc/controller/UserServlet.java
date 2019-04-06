package com.hyc.controller;

import com.hyc.pojo.User;
import com.hyc.service.Impl.UserServiceImpl;
import com.hyc.service.UserService;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 11:29
 */
@WebServlet("/User")
public class UserServlet extends HttpServlet {
    UserService serv = new UserServiceImpl();

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        req.setCharacterEncoding("utf-8");
        String method = req.getParameter("method");
        Map message = null;
        if ("注册".equalsIgnoreCase(method)) {
            User user = userMapper(req, resp);
            //检查有效性
            message = user.validate();
            if (message != null) {
                req.setAttribute("message", message);
                req.getRequestDispatcher("index.jsp").forward(req, resp);
            } else {
                serv.register(user);
                resp.sendRedirect("login.jsp");
            }
        } else if ("登陆".equalsIgnoreCase(method)) {
            User user = userMapper(req, resp);
            //检查有效性
            message=loginValidate(user);
            if (message!=null) {
                req.setAttribute("message", message);
                req.getRequestDispatcher("login.jsp").forward(req, resp);
            } else {
                user = serv.login(user.getUserName(), user.getPassword());
                if (user != null) {
                    req.setAttribute("login", user);
                    req.getRequestDispatcher("myinfo.jsp").forward(req, resp);
                } else {
                    //TODO 登陆失败，输出提示
                    message = new HashMap<>();
                    message.put("error","你的登陆不成功，可能是账号不存在，或者密码错误");
                    req.setAttribute("message", message);
                    req.getRequestDispatcher("login.jsp").forward(req, resp);
                }
            }
        }
    }

    private User userMapper(HttpServletRequest req, HttpServletResponse resp) {
        User user = new User();
        user.setUserName(req.getParameter("userName"));
        user.setPassword(req.getParameter("password"));
        user.setNickName(req.getParameter("nickName"));
        user.setGender(req.getParameter("gender"));
        return user;
    }

    private Map<String, String> loginValidate(User user) {
        Map<String, String> map = new HashMap<String, String>();
        if (user.getUserName()== null || user.getUserName().trim().isEmpty()) {
            map.put("userName", "用户名不能为空");
        }
        if (user.getPassword() == null || user.getPassword().trim().isEmpty()) {
            map.put("password", "密码不能为空");
        }
        if (map.size() > 0) {
            return map;
        } else {
            return null;
        }
    }
}
