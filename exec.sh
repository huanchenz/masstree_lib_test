#!bin/bash

g++ -std=gnu++0x -g -W -Wall -O2 -MD -MF masstree/.deps/mtIndexAPItest.d -MP -include masstree/config.h -c -o mtIndexAPItest.o mtIndexAPItest.cc
g++ -std=gnu++0x -g -W -Wall -O2 -o mtIndexAPItest mtIndexAPItest.o masstree/mtIndexAPI.a masstree/libjson.a -ltcmalloc_minimal -lpthread -lm
