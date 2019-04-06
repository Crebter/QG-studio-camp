package com.hyc.service.Impl;

import com.hyc.dao.Impl.UserDaoImpl;
import com.hyc.dao.UserDao;
import com.hyc.pojo.User;
import com.hyc.service.UserService;
import com.hyc.util.Md5Utils;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 11:04
 */
public class UserServiceImpl implements UserService {
    UserDao userDao = new UserDaoImpl();

    @Override
    public boolean register(User user) {
        if(userDao.findUser(user.getUserName())==null) {
            userDao.addUser(user);
            return true;
        }
        return false;
    }

    @Override
    public User login(String userName, String password) {
        User user = userDao.findUser(userName);
        password= Md5Utils.getDigest(password);
        if(user!=null&&user.getPassword().equals(password)){
            return user;
        }
        return null;
    }
}
