/*
 * ProblemLoader.h
 *
 *  Created on: 17 Jan 2016
 *      Author: lubiedak
 */

#ifndef IO_PROBLEMLOADER_H_
#define IO_PROBLEMLOADER_H_

#include <string>
#include "../model/Problem.h"

enum loadStatus {
  SUCCESFUL = 0, WARNING, ERROR,
};

class LoadResult {
public:
  LoadResult() :
      status(SUCCESFUL) {
  }
  LoadResult(loadStatus s) :
      status(s) {
  }
  void addMessage(std::string s) {
    messages.push_back(s);
  }
  const std::vector<std::string>& getWarnings() const {
    return messages;
  }
  loadStatus getStatus() const {
    return status;
  }

private:
  loadStatus status;
  std::vector<std::string> messages;
};

class ProblemLoader {
public:
  ProblemLoader() {}
  ProblemLoader(const std::string& fileName);
  virtual ~ProblemLoader();

  Problem load();

private:
  Problem p;
  std::string fileName;
  std::vector<std::string> content;

  std::vector<std::string> readContent();

  std::vector<std::string> getLinesContaining(const std::string& str);
  LoadResult loadCriteria();
  LoadResult loadNodes();

};

#endif /* IO_PROBLEMLOADER_H_ */
