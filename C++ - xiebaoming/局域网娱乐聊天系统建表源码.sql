create database qqdb;

use qqdb;  

CREATE TABLE `user` (
  `ID` int(11) NOT NULL,
  `userName` char(20) NOT NULL,
  `passwd` char(20) NOT NULL,
  `niName` char(20) NOT NULL,
  `sex` char(10) NOT NULL,
  `phone` char(20) DEFAULT NULL,
  `address` char(100) DEFAULT NULL,
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `list` (
  `ID` int(11) NOT NULL,
  `Name` char(40) NOT NULL,
  `Score` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
