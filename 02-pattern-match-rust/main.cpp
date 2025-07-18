#include <iostream>
#include <expected>
#include <cstdint>

template <typename T, typename E, typename FSuccess, typename FError>
void match(const std::expected<T, E>& expected_result, FSuccess onSuccess, FError onError){
  if(expected_result.has_value()){
    onSuccess(expected_result.value());
  } else {
    onError(expected_result.error());
  }
}

enum class Error {
  NEGATIVE_AGE,
  ZERO,
  ABOVE_150
};

std::expected<std::uint32_t, Error> check_age(const std::uint32_t age){
  if(age < 0 )return std::unexpected(Error::NEGATIVE_AGE);
  else if(age == 0) return std::unexpected(Error::ZERO);
  else if(age > 150) return std::unexpected(Error::ABOVE_150);
  return age;
} 

// g++ -std=c++23 main.cpp -o main

int main(){
  std::uint32_t age = 0;

  const auto result = check_age(age);

  match(result,
    [](std::uint32_t age){
      std::cout << "Valid Age: " << age << "\n";
    },
    [](Error error){
      std::cout << "Error: " << static_cast<std::uint32_t>(error) << "\n";
    }
  );


  return 0;
}