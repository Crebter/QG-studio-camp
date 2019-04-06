package com.hyc.util;

import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;

/**
 * @author HYC kobe524348@gmail.com
 * @program week3
 * @description
 * @date 2019-04-06 14:15
 */
public class Md5Utils {
    private static final String ENCODING = "UTF-8";

    private Md5Utils() {
    }

    public static String getDigest(String originText) {
        MessageDigest md = null;
        byte[] digest = null;
        try {
//          1. 获取实例：MessageDigest.getInstance("md5");
            md = MessageDigest.getInstance("md5");
//          2. 调用digest方法，传入参数和返回值都是byte数组
            digest = md.digest(originText.getBytes(ENCODING));
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("无法支持md5加密", e);
        } catch (UnsupportedEncodingException e) {
            throw new RuntimeException("无法支持UTF-8编码格式", e);
        }
//      3.使用Base64编码将二进制数据转成字符串
        return Base64.getEncoder().encodeToString(digest);
    }
}
