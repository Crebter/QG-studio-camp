package com.hyc.dao.Impl;

import com.hyc.dao.UserDao;
import com.hyc.pojo.User;
import com.hyc.util.JdbcUtils;
import com.hyc.util.Md5Utils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 10:31
 */
public class UserDaoImpl implements UserDao {
    private static Connection conn = null;
    private static PreparedStatement ps = null;
    private static ResultSet rs = null;
    private User user = null;

    @Override
    public User findUser(String userName) {
        User user = null;
        conn = JdbcUtils.getConnection();
        try {
            ps = conn.prepareStatement("select * from tb_user ,tb_info where tb_user.user_name=? and tb_info.user_id = tb_user.id ");
            ps.setString(1,userName);
            rs = ps.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e.getMessage(), e);

        }
        try {
            if (rs.next()) {
                user = new User();
                user.setUserName(rs.getString("user_name"));
                user.setPassword(rs.getString("password"));
                user.setGender(rs.getString("gender"));
                user.setNickName(rs.getString("nick_name"));
            }
        } catch (SQLException e) {
            throw new RuntimeException(e.getMessage(), e);

        }
        return user;
    }

    @Override
    public void addUser(User user) {
        conn = JdbcUtils.getConnection();
        String password = Md5Utils.getDigest(user.getPassword());

        try {
            ps = conn.prepareStatement("insert into tb_user (user_name,password) value (?,?)");
            ps.setString(1,user.getUserName());
            ps.setString(2,password);
            ps.executeUpdate();
            ps= conn.prepareStatement("insert into tb_info (user_id,nick_name,gender) value (last_insert_id(),?,?)");
            ps.setString(1,user.getNickName());
            ps.setString(2,user.getGender());
            ps.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e.getMessage(), e);

        }


    }
}
