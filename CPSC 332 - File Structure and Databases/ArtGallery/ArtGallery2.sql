-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema ArtGallery
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema ArtGallery
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `ArtGallery` DEFAULT CHARACTER SET utf8 ;
USE `ArtGallery` ;

-- -----------------------------------------------------
-- Table `ArtGallery`.`Artist`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ArtGallery`.`Artist` (
  `Name` VARCHAR(45) NOT NULL,
  `Phone` VARCHAR(45) NULL,
  `Address` VARCHAR(45) NULL,
  `Age` INT NULL,
  `StyleOfArt` VARCHAR(45) NULL,
  `BirthPlace` VARCHAR(45) NULL,
  PRIMARY KEY (`Name`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ArtGallery`.`ArtWork`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ArtGallery`.`ArtWork` (
  `Title` VARCHAR(45) NOT NULL,
  `Location` VARCHAR(45) NULL,
  `Price` FLOAT NULL,
  `DateAcquired` VARCHAR(45) NULL,
  `DateOfCreation` VARCHAR(45) NULL,
  `TypeOfArt` VARCHAR(45) NULL,
  `Artist_Name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`Title`),
  INDEX `fk_ArtWork_Artist_idx` (`Artist_Name` ASC) VISIBLE,
  CONSTRAINT `fk_ArtWork_Artist`
    FOREIGN KEY (`Artist_Name`)
    REFERENCES `ArtGallery`.`Artist` (`Name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ArtGallery`.`Art Shows`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ArtGallery`.`Art Shows` (
  `ShowID` INT NOT NULL,
  `DateTime` VARCHAR(45) NULL,
  `Location` VARCHAR(45) NULL,
  `contactPerson` VARCHAR(45) NULL,
  `contactNumber` VARCHAR(45) NULL,
  `Artist_Name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`ShowID`),
  INDEX `fk_Art Shows_Artist1_idx` (`Artist_Name` ASC) VISIBLE,
  CONSTRAINT `fk_Art Shows_Artist1`
    FOREIGN KEY (`Artist_Name`)
    REFERENCES `ArtGallery`.`Artist` (`Name`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ArtGallery`.`Customer`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ArtGallery`.`Customer` (
  `CustomerNumber` INT NOT NULL,
  `Phone` VARCHAR(45) NULL,
  `ArtPreference` VARCHAR(45) NULL,
  PRIMARY KEY (`CustomerNumber`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `ArtGallery`.`Customer_has_Art Shows`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `ArtGallery`.`Customer_has_Art Shows` (
  `Customer_CustomerNumber` INT NOT NULL,
  `Art Shows_ShowID` INT NOT NULL,
  PRIMARY KEY (`Customer_CustomerNumber`, `Art Shows_ShowID`),
  INDEX `fk_Customer_has_Art Shows_Art Shows1_idx` (`Art Shows_ShowID` ASC) VISIBLE,
  INDEX `fk_Customer_has_Art Shows_Customer1_idx` (`Customer_CustomerNumber` ASC) VISIBLE,
  CONSTRAINT `fk_Customer_has_Art Shows_Customer1`
    FOREIGN KEY (`Customer_CustomerNumber`)
    REFERENCES `ArtGallery`.`Customer` (`CustomerNumber`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Customer_has_Art Shows_Art Shows1`
    FOREIGN KEY (`Art Shows_ShowID`)
    REFERENCES `ArtGallery`.`Art Shows` (`ShowID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;