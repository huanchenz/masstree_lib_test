#include <iostream>
#include "masstree/mtIndexAPI.hh"

//int main (int argc, char *argv[]) {
int main () {
  std::cout << "test:\n";
  mt_index<Masstree::default_table> mti;

  mti.setup();

  mti.put("huanchen", 8, "yingjie", 7);
  mti.put("zhuo", 4, "yangzi", 6);
  mti.put("julian", 6, "wenlu", 5);
  Str value;
  bool get_success;
  get_success = mti.get("huanchen", 8, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("zhuo", 4, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("julian", 6, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("dave", 4, value);
  std::cout << get_success << "\t" << value.s << "\n";

  /*
  bool remove_success = mti.remove("dave", 4);
  std::cout << remove_success << "\n";
  mti.get("zhuo", 4, value);
  std::cout << value.s << "\n";
  */

  

  return 0;
}
