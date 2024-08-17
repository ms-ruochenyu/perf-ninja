#include "solution.hpp"

uint16_t checksum_baseline(const Blob &blob) {
  uint16_t acc = 0;
  for (auto value : blob) {
    acc += value;
    acc += acc < value; // add carry
  }
  return acc;
}

uint16_t checksum_solution(const Blob &blob) {
  uint32_t acc = 0;
  for (auto value : blob) {
    acc += (uint32_t)value;
  }

  acc = (uint16_t)(acc & 0xFFFFu + (acc >> 16));
  acc = (uint16_t)(acc & 0xFFFFu + (acc >> 16)); // acc still can overflow.
  return static_cast<uint16_t>(acc);
}
