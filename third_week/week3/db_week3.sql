/*
 Navicat Premium Data Transfer

 Source Server         : hyc
 Source Server Type    : MySQL
 Source Server Version : 80015
 Source Host           : localhost:3306
 Source Schema         : db_week3

 Target Server Type    : MySQL
 Target Server Version : 80015
 File Encoding         : 65001

 Date: 06/04/2019 15:39:22
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for tb_info
-- ----------------------------
DROP TABLE IF EXISTS `tb_info`;
CREATE TABLE `tb_info`  (
  `user_id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `nick_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `gender` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`user_id`) USING BTREE,
  CONSTRAINT `fk_user_id` FOREIGN KEY (`user_id`) REFERENCES `tb_user` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of tb_info
-- ----------------------------
INSERT INTO `tb_info` VALUES (1, 'hello', '男');
INSERT INTO `tb_info` VALUES (3, 'testnickname', '男');
INSERT INTO `tb_info` VALUES (4, 'testnickname', '男');
INSERT INTO `tb_info` VALUES (5, 'testnickname', '男');
INSERT INTO `tb_info` VALUES (6, 'testnickname', '男');
INSERT INTO `tb_info` VALUES (7, 'qqq', '男');
INSERT INTO `tb_info` VALUES (8, 'qqq', '男');
INSERT INTO `tb_info` VALUES (9, 'qqq', '男');
INSERT INTO `tb_info` VALUES (10, 'qqq', '男');
INSERT INTO `tb_info` VALUES (11, 'qqq', '男');
INSERT INTO `tb_info` VALUES (12, 'qqq', '男');

-- ----------------------------
-- Table structure for tb_user
-- ----------------------------
DROP TABLE IF EXISTS `tb_user`;
CREATE TABLE `tb_user`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `user_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `password` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of tb_user
-- ----------------------------
INSERT INTO `tb_user` VALUES (1, 'test', '1234');
INSERT INTO `tb_user` VALUES (2, 'test1', '1234');
INSERT INTO `tb_user` VALUES (3, 'test1', '1234');
INSERT INTO `tb_user` VALUES (4, 'testService', '1234');
INSERT INTO `tb_user` VALUES (5, 'test2', '1234');
INSERT INTO `tb_user` VALUES (6, 'test2', '1234');
INSERT INTO `tb_user` VALUES (7, 'test4', '1234');
INSERT INTO `tb_user` VALUES (8, 'test5', '1234');
INSERT INTO `tb_user` VALUES (9, 'test6', '1234');
INSERT INTO `tb_user` VALUES (10, 'test7', 'gdyb21LQTcIANtvYMT7QVQ==');
INSERT INTO `tb_user` VALUES (11, 'test8', 'gdyb21LQTcIANtvYMT7QVQ==');
INSERT INTO `tb_user` VALUES (12, '15816019723', 'gdyb21LQTcIANtvYMT7QVQ==');

SET FOREIGN_KEY_CHECKS = 1;
