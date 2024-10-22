#ifndef c_dsalgos_testSuites_testSuites_h
#define c_dsalgos_testSuites_testSuites_h

void runTestSuites(int argc, char* argv[]);

int argsContainsTest(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "test") == 0) return 1;
    }
    return 0;
}

#endif