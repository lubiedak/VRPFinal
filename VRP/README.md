### To build:

Enter Release directory and run `make` command. It is able to build in linux environment with gcc 4.8+

### To Run:

Run VRPCore2.0 with these options:
```
Options:
  --help       -h  Print usage and exit.
  --inputFile, -i  Problem file path. (MANDATORY)
  --outputDir, -o  Directory, where output would be produced
  --random,    -r  Running VRP in Random mode. Solving n problems
  --test,      -t  Running VRP in test mode - running all tests.
  --debug,     -d  Setup file path.

Examples:
  VRPCore2.0 --inputFile=input_file --outputDir=some_dir
  VRPCore2.0 --random=10  VRPCore2.0 --test=true
```
