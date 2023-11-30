import pathlib
import sys
import csv

# Exception.csv 공유 파일 배열로 읽어오기
file_path = 'Exception.csv'
data_list = []
with open(file_path, 'r', newline='', encoding='utf-8') as file:
    # CSV 파일을 읽기 위한 reader 객체 생성
    reader = csv.reader(file)

    for row in reader:
        data_list.append(row)

for data in data_list:
    print(data)

code = """#pragma once

#include <string>
#include "ExceptionCode.h"

namespace anylink {{
class GatewayExceptionCode: public ExceptionCode {{
private:
    std::string codeName;
    std::string code;

public:
    GatewayExceptionCode(int codeNumber, const std::string& codeName);
    virtual ~GatewayExceptionCode() = default;
    std::string getCode() const override;
    std::string getCodeName() const override;

public:
{push_back}

}};
}} /* namespace anylink */
"""

# 위 header에 배열의 값 넣어주기
output_file_name = '/home/bont/PycharmProjects/pythonProject/generate/header.hpp'
output = pathlib.Path(output_file_name)
push_back = '\n'.join(['    // {}\n    static const GatewayExceptionCode& {};\n'.format(row[-1], row[0]) for row in data_list])
output.write_text(code.format(push_back=push_back))
