#pragma once
class FileDirChecker {
public:

  FileDirChecker(void);
  ~FileDirChecker(void);

  bool isFileEnabled(const char * name);
  bool isDirEnabled(const char * pathname);
};

