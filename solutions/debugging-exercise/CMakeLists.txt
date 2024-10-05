cmake_minimum_required(VERSION 3.5)
project(Debugingcontest)

add_executable(alloc alloc.cc)
add_executable(fpe fpe.cc)
add_executable(check_prime main_prime.cc check_prime.cc)
