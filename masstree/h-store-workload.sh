#!bin/bash

./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_IDX_CUSTOMER tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_IDX_CUSTOMER_NAME tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_IDX_ORDER_LINE_TREE tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_IDX_ORDERS tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_I_PK_ARRAY_10027 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_NO_PK_TREE_10075 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_CT_10033_10035 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_CT_10067_10069 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_PK_10022_10023 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_PK_10032_10034 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_PK_10056_10057 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_PK_10066_10068 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_SYS_PK_10082_10083 tpcc
./mttest --stat -j 1 -l 10000000 file=../h-store/inputMasstree/inMT_SYS_IDX_W_PK_ARRAY_10018 tpcc
