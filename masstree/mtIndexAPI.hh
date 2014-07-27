#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/select.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <limits.h>
#if HAVE_NUMA_H
#include <numa.h>
#endif
#if HAVE_SYS_EPOLL_H
#include <sys/epoll.h>
#endif
#if HAVE_EXECINFO_H
#include <execinfo.h>
#endif
#if __linux__
#include <asm-generic/mman.h>
#endif
#include <fcntl.h>
#include <assert.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <signal.h>
#include <errno.h>
#ifdef __linux__
#include <malloc.h>
#endif
#include "nodeversion.hh"
#include "kvstats.hh"
#include "query_masstree.hh"
#include "masstree_tcursor.hh"
#include "masstree_insert.hh"
#include "masstree_remove.hh"
#include "masstree_scan.hh"
#include "timestamp.hh"
#include "json.hh"
#include "kvtest.hh"
#include "kvrandom.hh"
#include "kvrow.hh"
#include "kvio.hh"
#include "clp.h"
#include <algorithm>
#include <numeric>

template <typename T>
class mt_index {
public:
  mt_index() {}
  ~mt_index() {
    ti_->rcu_stop();
  }


  void setup() {
    ti_ = new threadinfo();
    ti_->rcu_start();
    table_ = new T;
    table_->initialize(*ti_);
  }
  

  void put(const Str &key, const Str &value) {
    q_[0].run_replace(table_->table(), key, value, *ti_);
  }
  
  void put(const char *key, int keylen, const char *value, int valuelen) {
    put(Str(key, keylen), Str(value, valuelen));
  }
  
  bool get(const char *key, int keylen, Str &value) {
    return q_[0].run_get1(table_->table(), Str(key, keylen), 0, value, *ti_);
  }

  bool remove(const char *key, int keylen) {
    return remove(Str(key, keylen));
  }

  bool remove(const Str &key) {
    return q_[0].run_remove(table_->table(), key, *ti_);
    
  }

private:
  T *table_;
  threadinfo *ti_;
  query<row_type> q_[1];

};

/*
template <typename T>
class mt_index {
public:
  mt_index() {}
  ~mt_index() {
    ti_->rcu_stop();
  }
  void setup();
  void put(const Str &key, const Str &value);
  void put(const char *key, int keylen, const char *value, int valuelen);
  bool get(const char *key, int keylen, Str &value);
//bool remove(const Str &key);
//bool remove(const char *key, int keylen);

private:
  T *table_;
  threadinfo *ti_;
  query<row_type> q_[1];

};
*/
