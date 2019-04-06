package com.hyc.test;

import com.hyc.dao.Impl.UserDaoImpl;
import com.hyc.dao.UserDao;
import com.hyc.pojo.User;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 10:56
 */
public class TestDao {
    public static void main(String[] args) {
        UserDao userDao = new UserDaoImpl();
        //测试查询功能
        User user = userDao.findUser("test");
        System.out.println(user.getGender());
        //测试插入功能
        user= new User();
        user.setUserName("test2");
        user.setPassword("1234");
        user.setNickName("testnickname");
        user.setGender("男");
        userDao.addUser(user);
    }
}
