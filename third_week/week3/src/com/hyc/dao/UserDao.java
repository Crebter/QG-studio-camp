package com.hyc.dao;

import com.hyc.pojo.User;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 10:31
 */
public interface UserDao {
    User findUser(String userName);
    void addUser(User user);
}
