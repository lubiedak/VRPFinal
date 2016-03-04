SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Table `vrpdb`.`Criteria`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `vrpdb`.`Criteria` (
  `id` INT NOT NULL,
  `maxNodes` INT NULL,
  `minNodes` INT NULL,
  `maxDistance` INT NULL,
  `minDistance` INT NULL,
  `maxDemand` INT NULL,
  `minDemand` INT NULL,
  PRIMARY KEY (`id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `vrpdb`.`Problem`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `vrpdb`.`Problem` (
  `id` INT NOT NULL,
  `name` VARCHAR(45) NOT NULL,
  `criteriaId` INT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_Problem_Criteria_idx` (`criteriaId` ASC),
  CONSTRAINT `fk_Problem_Criteria`
    FOREIGN KEY (`criteriaId`)
    REFERENCES `vrpdb`.`Criteria` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `vrpdb`.`Solution`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `vrpdb`.`Solution` (
  `id` INT NOT NULL,
  `problemId` INT NULL,
  `distance` INT NULL,
  `demand` INT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_Solution_Problem_idx` (`problemId` ASC),
  CONSTRAINT `fk_Solution_Problem`
    FOREIGN KEY (`problemId`)
    REFERENCES `vrpdb`.`Problem` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `vrpdb`.`Cycle`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `vrpdb`.`Cycle` (
  `id` INT NOT NULL,
  `demand` INT NULL,
  `distance` INT NULL,
  `solution_id` INT NULL,
  `innerDistanceRatio` FLOAT NULL,
  `demandToDistanceRatio` FLOAT NULL,
  `demandRank` FLOAT NULL,
  `distanceRank` FLOAT NULL,
  `innerDistanceRatioRank` FLOAT NULL,
  `demandToDistanceRatioRank` FLOAT NULL,
  PRIMARY KEY (`id`),
  INDEX `fk_Cycle_Solution_idx` (`solution_id` ASC),
  CONSTRAINT `fk_Cycle_Solution`
    FOREIGN KEY (`solution_id`)
    REFERENCES `vrpdb`.`Solution` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `vrpdb`.`Node`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `vrpdb`.`Node` (
  `id` INT NOT NULL,
  `problemId` INT NULL,
  `demand` INT NULL,
  `x` INT NULL,
  `y` INT NULL,
  `cycleId` INT NULL,
  `type` VARCHAR(45) NULL DEFAULT 'node',
  `distanceId` INT NULL,
  INDEX `fk_Node_1_idx` (`problemId` ASC),
  INDEX `fk_Node_Cycle_idx` (`cycleId` ASC),
  PRIMARY KEY (`id`),
  CONSTRAINT `fk_Node_Problem`
    FOREIGN KEY (`problemId`)
    REFERENCES `vrpdb`.`Problem` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Node_Cycle`
    FOREIGN KEY (`cycleId`)
    REFERENCES `vrpdb`.`Cycle` (`id`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
