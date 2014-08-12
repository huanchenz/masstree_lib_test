#include <iostream>
#include "masstree/mtIndexAPI.hh"

//int main (int argc, char *argv[]) {
int main () {
  std::cout << "test:\n";
  mt_index<Masstree::default_table> mti;

  mti.setup();

  std::cout << "\nPUT and GET test\n";
  mti.put("huanchenhuanchen", 16, "yingjie", 7);
  mti.put("zhuozhuozhuo", 12, "yangzi", 6);
  mti.put("julianjulianjulian", 18, "wenlu", 5);
  Str value;
  bool get_success;
  get_success = mti.get("huanchenhuanchen", 16, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("zhuozhuozhuo", 12, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("julianjulianjulian", 18, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get("dave", 4, value);
  std::cout << get_success << "\t" << value.s << "\n";

  std::cout << "\nUPDATE test\n";
  mti.put("zhuozhuozhuo", 12, "shuguang", 8);
  get_success = mti.get("zhuozhuozhuo", 12, value);
  std::cout << get_success << "\t" << value.s << "\n";


  std::cout << "\nPARTIAL KEY GET test\n";
  Str retKey1;
  Str retKey2;
  Str retKey3;
  Str retKey4;
  Str retKey5;
  mti.get_lower_bound("apple", 5, retKey1);
  //std::cout << retKey1.s << "\n";
  mti.get_lower_bound("icecream", 8, retKey2);
  //std::cout << retKey2.s << "\n";
  mti.get_lower_bound("yingjie", 7, retKey3);
  //std::cout << retKey3.s << "\n";
  mti.get_lower_bound("zhuzhu", 6, retKey4);
  //std::cout << retKey4.s << "\n";
  mti.get_lower_bound("zhuozhuozhuo", 12, retKey5);
  //std::cout << retKey5.s << "\n";

  get_success = mti.get(retKey1, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get(retKey2, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get(retKey3, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get(retKey4, value);
  std::cout << get_success << "\t" << value.s << "\n";
  get_success = mti.get(retKey5, value);
  std::cout << get_success << "\t" << value.s << "\n";

  std::cout << "\nGET_NEXT test\n";
  Str retKey6;
  Str key;
  mti.get_lower_bound("apple", 5, retKey6);
  std::cout << retKey6.s << "\n";
  mti.get_next(retKey6, key, value);
  std::cout << "key: " << key.s << "\tvalue: " << value.s << "\n";
  mti.get_next(key, key, value);
  std::cout << "key: " << key.s << "\tvalue: " << value.s << "\n";
  mti.get_next(key, key, value);
  std::cout << "key: " << key.s << "\tvalue: " << value.s << "\n";
  

  std::cout << "\nREMOVE test\n";
  get_success = mti.get("julianjulianjulian", 18, value);
  std::cout << get_success << "\t" << value.s << "\n";
  mti.remove("julianjulianjulian", 18);
  get_success = mti.get("julianjulianjulian", 18, value);
  std::cout << get_success << "\t" << value.s << "\n";

  /*
  bool remove_success = mti.remove("dave", 4);
  std::cout << remove_success << "\n";
  mti.get("zhuo", 4, value);
  std::cout << value.s << "\n";
  */

  

  return 0;
}
