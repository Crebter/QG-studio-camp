package com.hyc.pojo;

import java.util.HashMap;
import java.util.Map;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 10:29
 */
public class User {
    private String userName;
    private String password;
    private String gender;
    private String nickName;

    public Map<String, String> validate() {
        Map<String, String> map = new HashMap<String, String>();

        if (userName == null || userName.trim().isEmpty()) {
            map.put("userName", "用户名不能为空");
        }

        if (password == null || password.trim().isEmpty()) {
            map.put("password", "密码不能为空");
        }

        if (gender == null || gender.trim().isEmpty()) {
            map.put("gender", "性别不能为空");
        }

        if (nickName == null || nickName.trim().isEmpty()) {
            map.put("nickName", "昵称不能为空");
        }

        if (map.size() > 0) {
            return map;
        }else {
            return null;
        }
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getNickName() {
        return nickName;
    }

    public void setNickName(String nickName) {
        this.nickName = nickName;
    }

    private Enum userType;

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public Enum getUserType() {
        return userType;
    }

    public void setUserType(Enum userType) {
        this.userType = userType;
    }
}
