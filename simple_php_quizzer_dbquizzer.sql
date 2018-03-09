-- phpMyAdmin SQL Dump
-- version 3.5.7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 13, 2015 at 12:51 PM
-- Server version: 5.5.29
-- PHP Version: 5.4.10

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `quizzer`
--

-- --------------------------------------------------------

--
-- Table structure for table `choices`
--
CREATE DATABASE quizzer;
use quizzer;
CREATE TABLE `choices` (
  `id` int(48) NOT NULL AUTO_INCREMENT,
  `question_number` int(11) NOT NULL,
  `is_correct` tinyint(4) NOT NULL DEFAULT '0',
  `choice` text COLLATE utf16_bin NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf16 COLLATE=utf16_bin AUTO_INCREMENT=12 ;

--
-- Dumping data for table `choices`
--

INSERT INTO `choices` (`id`, `question_number`, `is_correct`, `choice`) VALUES
(1, 1, 1, 'absolutely correct'),
(2, 1, 0, 'somewhat correct'),
(3, 1, 0, 'somewhat wrong'),
(4, 1, 0, 'absolutely wrong'),
(5, 2, 0, 'absolutely correct'),
(6, 2, 1, 'somewhat correct'),
(7, 2, 0, 'somewhat wrong'),
(8, 2, 0, 'absolutely wrong'),
(9, 3, 0, 'absolutely correct'),
(10, 3, 0, 'somewhat correct'),
(11,3,0,'somewhat wrong'),
(12, 3, 1, 'absolutely wrong'),
(13, 4, 1, 'absolutely correct'),
(14, 4, 1, 'somewhat correct'),
(15, 4, 1, 'somewhat wrong'),
(16, 4, 1, 'absolutely wrong'),
(17, 5, 1, 'absolutely correct'),
(18, 5, 1, 'somewhat correct'),
(19, 5, 1, 'somewhat wrong'),
(20, 5, 1, 'absolutely wrong'),
(21, 6, 1, 'absolutely correct'),
(22, 6, 1, 'somewhat correct'),
(23, 6, 1, 'somewhat wrong'),
(24, 6, 1, 'absolutely wrong'),
(25, 7, 1, 'absolutely correct'),
(26, 7, 1, 'somewhat correct'),
(27, 7, 1, 'somewhat wrong'),
(28, 7, 1, 'absolutely wrong'),
(29, 8, 1, 'absolutely correct'),
(30, 8, 1, 'somewhat correct'),
(31, 8, 1, 'somewhat wrong'),
(32, 8, 1, 'absolutely wrong'),
(33, 9, 1, 'absolutely correct'),
(34, 9, 1, 'somewhat correct'),
(35, 9, 1, 'somewhat wrong'),
(36, 9, 1, 'absolutely wrong'),
(37, 10, 1, 'absolutely correct'),
(38, 10, 1, 'somewhat correct'),
(39, 10, 1, 'somewhat wrong'),
(40, 10, 1, 'absolutely wrong'),
(41, 11, 1, 'absolutely correct'),
(42, 11, 1, 'somewhat correct'),
(43, 11, 1, 'somewhat wrong'),
(44, 11, 1, 'absolutely wrong'),
(45, 12, 1, 'absolutely correct'),
(46, 12, 1, 'somewhat correct'),
(47, 12, 1, 'somewhat wrong'),
(48, 12, 1, 'absolutely wrong'),
(49,13,0,'yes'),
(50,13,0,'no'),
(51,13,0,'do not know'),
(52,14,0,'yes'),
(53,14,0,'no'),
(54,14,0,'do not know'),
(55,15,0,'yes'),
(56,15,0,'no'),
(57,15,0,'do not know'),
(58,16,0,'yes'),
(59,16,0,'no'),
(60,16,0,'do not know'),
(61,17,0,'yes'),
(62,17,0,'no'),
(63,17,0,'do not know'),
(64,18,0,'');



-- --------------------------------------------------------

--
-- Table structure for table `questions`
--

CREATE TABLE `questions` (
  `question_number` int(11) NOT NULL,
  `question` text COLLATE utf16_bin NOT NULL,
  `img` text COLLATE utf16_bin,
  PRIMARY KEY (`question_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf16 COLLATE=utf16_bin;

--
-- Dumping data for table `questions`
--

INSERT INTO `questions` (`question_number`, `question`, `img`) VALUES
(1, 'When I meet a new person, I am interested in learning more about him/her.', ''),
(2, 'I am interested in people.', ''),
(3, 'I find it fascinating to get to know new people.', ''),
(4,'I like to learn about the habits of others.', ''),
(5,'I like finding out how others "work".', ''),
(6,'I am interested in other people&apos;s thoughts and feelings.', ''),
(7,'Other people&apos;s life stories interest me.', ''),
(8,'When other people are having a conversation, I like to find out what it&apos;s about.', ''),
(9,'I like to look into other people&apos;s lit windows.', ''),
(10,'When people quarrel, I like to know what&apos;s going on.', ''),
(11,'When I see a crowd, I go over to see what&apos;s happening.', ''),
(12,'I like to go to public places and watch the people going by.', ''),
(13,'Late one night old Mrs. Peabody is walking home. She doesn&apos;t like
walking alone in the dark because she is always afraid that someone
will attack her and rob her. She is really very nervous! Suddenly, out
of the shadow comes a man. He wants to ask Mrs. Peabody what time
it is, so he walks towards her. When Mrs. Peabody sees the man coming
towards her, she starts to tremble and says, "Take my purse, just
don&apos;t hurt me".
Was the man surprised at what Mrs. Peabody said?',''),
(14,'Emma has a cough. All through lunch she coughs and coughs. Father
says: "Poor Emma, you must have a frog in your throat!"
Is it true, what Father says to Emma?',''),
(15,'One day Aunt Jane came to visit Peter. Now Peter loves his aunt very
much, but today she is wearing a new hat; a new hat, which Peter
thinks is very ugly indeed. Peter thinks his aunt looks silly in it, and
much nicer in her old hat.But when Aunt Jane asks Peter,"How do you
like my new hat", Peter says,"Oh, its very nice".
Was it true, what Peter said?',''),
(16,'Katie and Emma are playing in the house. Emma picks up a banana
from the fruit bowl and holds it up to her ear. She says to Katie,"Look!
This banana is a telephone!"
Is it true what Emma says?',''),
(17,'Yvonne is playing in the garden with her doll. She leaves her doll in
the garden when her mother calls her to come in for lunch.While they
are having lunch, it starts to rain. Yvonne&apos;s mother asks Yvonne: "Did
you leave your doll in the garden?"Yvonne answers:"No,I brought her
in with me".Is it true, what Yvonne says?',''),
(18,'beauty contest game','');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

CREATE TABLE `question_answers` (
  `id` int(48) NOT NULL AUTO_INCREMENT,
  `ppnr` varchar(256) NOT NULL,
  `question_id` int(11) NOT NULL,
  `choice_id` int(48) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf16 COLLATE=utf16_bin;

