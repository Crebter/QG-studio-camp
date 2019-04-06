package com.hyc.service;

import com.hyc.pojo.User;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 11:02
 */
public interface UserService {
    boolean register(User user);
    User login(String userName,String password);
}
