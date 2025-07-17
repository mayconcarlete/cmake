#include <iostream>
#include <cstdint>
#include <expected>

#ifndef CXX_VERSION_STRING
#define CXX_VERSION_STRING "Desconhecido"
#endif

enum class Err {
  WRONG,
  SUCCESS
};

std::expected<std::int32_t, Err> sum(const int a, const int b){
  if(a == 0) return std::unexpected(Err::WRONG);
  return a + b;
} 

int main(){
  std::cout << "Versão desconhecida: " << __cplusplus << "\n";
  

  std::cout << "CXX_VERSION_STRING: " << CXX_VERSION_STRING << "\n";

  std::cout << "Hello World!" << std::endl;

  const auto soma = sum(1, 2);
  if(soma.has_value()){
    std::cout << soma.value() << "\n";
  } else {
    std::cout << static_cast<std::uint32_t>(soma.error()) << "\n";
  }
  
  return 0;
}