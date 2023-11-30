import pathlib
import sys

# for simplicity we do not verify argument list
max_number = 100
output_file_name = '/home/bont/Desktop/work/script_result/primes.hpp'

output = pathlib.Path(output_file_name)

numbers = range(2, max_number + 1)
is_prime = {number: True for number in numbers}

for number in numbers:
    current_position = number
    if is_prime[current_position]:
        while current_position <= max_number:
            current_position += number
            is_prime[current_position] = False

primes = (number for number in numbers if is_prime[number])
code = """#pragma once

#include <vector>

const std::size_t max_number = {max_number};

std::vector<int> & primes() {{
  static std::vector<int> primes;

{push_back}

  return primes;
}}
"""
push_back = '\n'.join(['  primes.push_back({:d});'.format(x) for x in primes])
output.write_text(
    code.format(max_number=max_number, push_back=push_back))