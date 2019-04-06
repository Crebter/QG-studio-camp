package com.hyc.test;

import com.hyc.pojo.User;
import com.hyc.service.Impl.UserServiceImpl;
import com.hyc.service.UserService;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 11:10
 */
public class TestService {

    public static void main(String[] args) {
    UserService userService = new UserServiceImpl();
        User user = new User();
        user.setUserName("testService");
        user.setPassword("1234");
        user.setNickName("testnickname");
        user.setGender("男");
        //测试注册功能
        userService.register(user);
        //测试重复注册
        userService.register(user);
        //测试登陆功能：密码登陆不成功会返回null
        user = userService.login("testService","1234");
        System.out.println(user.getGender());
        System.out.println(user.getNickName());

    }
}
